#include <stdlib.h>
#include <string.h>
#include "lua.h"

#include "lauxlib.h"
#include "lualib.h"

#include "bcm2835.h"

#define __weak_symbol   __attribute__((__weak__))

#ifdef __GLOBL
#undef __GLOBL
#endif
#define __GLOBL1(sym)   __asm__(".globl " #sym)
#define __GLOBL(sym)    __GLOBL1(sym)
#define __section(x)    __attribute__((__section__(x)))
#define __used          __attribute__((__used__))
#ifdef __CONCAT
#undef __CONCAT
#endif
#define __CONCAT1(x,y)  x ## y
#define __CONCAT(x,y)   __CONCAT1(x,y)

#define __MAKE_SET(set, sym)                                            \
	__GLOBL(__CONCAT(__start_set_,set));                            \
        __GLOBL(__CONCAT(__stop_set_,set));                             \
        static void const * const __set_##set##_sym_##sym               \
        __section("set_" #set) __used = &sym

#define DATA_SET(set, sym)      __MAKE_SET(set, sym)

#define SET_DECLARE(set, ptype)                                 	\
	extern ptype __weak_symbol *__CONCAT(__start_set_,set); 	\
        extern ptype __weak_symbol *__CONCAT(__stop_set_,set)

#define REG(set, ptype)							\
	SET_DECLARE(set, ptype);					\
	static luaL_Reg __reg_entry_dummy = {"dummy", NULL};		\
	DATA_SET(bcm2835_lib, __reg_entry_dummy)

#define REG_BEGIN()							\
	(&(__reg_entry_dummy) + 1 )

#define SET_BEGIN(set)                                                  \
	        (&__CONCAT(__start_set_,set))


#define REG_DEC(name)							\
	static luaL_Reg __reg_entry_##name = {#name, lua_##name};	\
	DATA_SET(bcm2835_lib, __reg_entry_##name)

#define REG_END()							\
	static int __dummy_end(lua_State *L) {return 0;}		\
	static luaL_Reg __reg_entry_end = {NULL, __dummy_end};		\
	DATA_SET(bcm2835_lib, __reg_entry_end);				\

#define MALLOC_BUF(name, size) 						\
	do {								\
		if ( size > BCM2835_BUFF_SZ )				\
			name = (char *)malloc(size);			\
		else							\
			name = gobal_buf;				\
	} while (0)	

#define FREE_BUF(name)							\
	do {								\
		if (name != gobal_buf)					\
			free((void*)name);				\
	} while (0)
			


#define VOID_FUNC(name)							\
	static int lua_##name(lua_State *L)				\
	{								\
		name();							\
		return 0;						\
	}								\
	REG_DEC(name);

#define INT_FUNC(name)							\
	static int lua_##name(lua_State *L)				\
	{								\
		uint64_t ret = name();					\
		lua_pushnumber(L, ret);					\
		return 1;						\
	}								\
	REG_DEC(name);

#define VOID_FUNC_INT(name)						\
	static int lua_##name(lua_State *L)				\
	{								\
		name(luaL_checknumber(L, 1));				\
		return 0;						\
	}								\
	REG_DEC(name);

#define INT_FUNC_INT(name)						\
	static int lua_##name(lua_State *L)				\
	{								\
		lua_pushinteger(L, name(luaL_checkinteger(L, 1)));	\
		return 1;						\
	}								\
	REG_DEC(name);

#define VOID_FUNC_INT_INT(name)						\
	static int lua_##name(lua_State *L)				\
	{								\
		name(luaL_checknumber(L, 1), 				\
			luaL_checknumber(L, 2));			\
		return 0;						\
	}								\
	REG_DEC(name);

#define VOID_FUNC_INT_INT_INT(name)					\
	static int lua_##name(lua_State *L)				\
	{								\
		name(luaL_checknumber(L, 1), 				\
			luaL_checknumber(L, 2),				\
			luaL_checknumber(L, 3));			\
		return 0;						\
	}								\
	REG_DEC(name);

#define VOID_FUNC_ISTR_L(name)						\
	static int lua_##name(lua_State *L)				\
	{								\
		const char *in = NULL;					\
		int size = 0;						\
		in = luaL_checklstring(L, 1, &size);			\
		if (size <= 0) return 0;				\
		name(in, size); 					\
		return 0;						\
	}								\
	REG_DEC(name);

#define INT_FUNC_ISTR_L(name)						\
	static int lua_##name(lua_State *L)				\
	{								\
		const char *in = NULL;					\
		int size = 0;						\
		int ret = 0;						\
		in = luaL_checklstring(L, 1, &size);			\
		if (size <= 0) return 0;				\
		ret = name(in, size); 					\
		lua_pushinteger(L, ret);				\
		return 1;						\
	}								\
	REG_DEC(name);

#define VOID_FUNC_OSTR_L(name)						\
	static int lua_##name(lua_State *L)				\
	{								\
		char *out = NULL;					\
		int size = 0;						\
		size = luaL_checkinteger(L, 1);				\
		if (size <= 0) return 0;				\
		MALLOC_BUF(out, size);					\
		name(out, size); 					\
		lua_pushlstring(L, out, size);				\
		FREE_BUF(out);						\
		return 0;						\
	}								\
	REG_DEC(name);

#define INT_FUNC_OSTR_L(name)						\
	static int lua_##name(lua_State *L)				\
	{								\
		char *out = NULL;					\
		int size = 0;						\
		int ret = 0;						\
		size = luaL_checkinteger(L, 1);				\
		if (size <= 0) return 0;				\
		MALLOC_BUF(out, size);					\
		ret = name(out, size); 					\
		lua_pushlstring(L, out, size);				\
		lua_pushinteger(L, ret);				\
		FREE_BUF(out);						\
		return 2;						\
	}								\
	REG_DEC(name);

#define VOID_FUNC_ISTR_OSTR_L(name)					\
	static int lua_##name(lua_State *L)				\
	{								\
		const char *in = NULL;					\
		int size = 0;						\
		char *out = NULL;					\
		in = luaL_checklstring(L, 1, &size);			\
		if (size <= 0) return 0;				\
		MALLOC_BUF(out, size);					\
		name(in, out, size); 					\
		lua_pushlstring(L, out, size);				\
		FREE_BUF(out);						\
		return 1;						\
	}								\
	REG_DEC(name);

#define VOID_FUNC_IOSTR_L(name)						\
	static int lua_##name(lua_State *L)				\
	{								\
		const char *in = NULL;					\
		int size = 0;						\
		char *inout = NULL;					\
		in = luaL_checklstring(L, 1, &size);			\
		if (size <= 0) return 0;				\
		MALLOC_BUF(inout, size);				\
		memcpy(inout, in, size);				\
		name(inout, size); 					\
		lua_pushlstring(L, inout, size);			\
		FREE_BUF(inout);					\
		return 1;						\
	}								\
	REG_DEC(name);


#define INT_FUNC_ISTR_L_OSTR_L(name)					\
	static int lua_##name(lua_State *L)				\
	{								\
		const char *in = NULL;					\
		int insize = 0;						\
		char *out = NULL;					\
		int outsize = 0;					\
		int ret = 0;						\
		in = luaL_checklstring(L, 1, &insize);			\
		outsize = luaL_checkinteger(L, 2);			\
		if (insize <= 0 || outsize <= 0) return 0;		\
		MALLOC_BUF(out, outsize);				\
		name(in, insize, out, outsize); 			\
		lua_pushlstring(L, out, outsize);			\
		FREE_BUF(out);						\
		return 1;						\
	}								\
	REG_DEC(name);


#define BCM2835_BUFF_SZ 2048
/* decare a gobal buffer to avoid malloc */ 
static char gobal_buf[BCM2835_BUFF_SZ] = {0};

REG(bcm2835_lib, luaL_Reg);
VOID_FUNC(bcm2835_init);
VOID_FUNC(bcm2835_close);
VOID_FUNC(bcm2835_version);

/* gpio */
VOID_FUNC_INT_INT(bcm2835_gpio_fsel);
VOID_FUNC_INT(bcm2835_gpio_set);
VOID_FUNC_INT(bcm2835_gpio_clr);
VOID_FUNC_INT(bcm2835_gpio_set_multi);
VOID_FUNC_INT(bcm2835_gpio_clr_multi);
VOID_FUNC_INT(bcm2835_gpio_lev);
VOID_FUNC_INT(bcm2835_gpio_eds);
VOID_FUNC_INT(bcm2835_gpio_set_eds);
VOID_FUNC_INT(bcm2835_gpio_ren);
VOID_FUNC_INT(bcm2835_gpio_clr_ren);
VOID_FUNC_INT(bcm2835_gpio_fen);
VOID_FUNC_INT(bcm2835_gpio_clr_fen);
VOID_FUNC_INT(bcm2835_gpio_len);
VOID_FUNC_INT(bcm2835_gpio_clr_len);
VOID_FUNC_INT(bcm2835_gpio_aren);
VOID_FUNC_INT(bcm2835_gpio_clr_aren);
VOID_FUNC_INT(bcm2835_gpio_afen);
VOID_FUNC_INT(bcm2835_gpio_clr_afen);
VOID_FUNC_INT(bcm2835_gpio_pud);
VOID_FUNC_INT_INT(bcm2835_gpio_pudclk);
VOID_FUNC_INT(bcm2835_gpio_pad);
VOID_FUNC_INT_INT(bcm2835_gpio_set_pad);
VOID_FUNC_INT(bcm2835_delay);
VOID_FUNC_INT(bcm2835_delayMicroseconds);
VOID_FUNC_INT_INT(bcm2835_gpio_write);
VOID_FUNC_INT_INT(bcm2835_gpio_write_multi);
VOID_FUNC_INT_INT(bcm2835_gpio_write_mask);
VOID_FUNC_INT_INT(bcm2835_gpio_set_pud);

/* spi */
VOID_FUNC(bcm2835_spi_begin);
VOID_FUNC(bcm2835_spi_end);
VOID_FUNC_INT(bcm2835_spi_setBitOrder);
VOID_FUNC_INT(bcm2835_spi_setClockDivider);
VOID_FUNC_INT(bcm2835_spi_setDataMode);
VOID_FUNC_INT(bcm2835_spi_chipSelect);
VOID_FUNC_INT_INT(bcm2835_spi_setChipSelectPolarity);
INT_FUNC_INT(bcm2835_spi_transfer);
VOID_FUNC_ISTR_OSTR_L(bcm2835_spi_transfernb);
VOID_FUNC_IOSTR_L(bcm2835_spi_transfern);
VOID_FUNC_ISTR_L(bcm2835_spi_writenb);

/* i2c */
VOID_FUNC(bcm2835_i2c_begin);
VOID_FUNC(bcm2835_i2c_end);
VOID_FUNC_INT(bcm2835_i2c_setSlaveAddress);
VOID_FUNC_INT(bcm2835_i2c_setClockDivider);
VOID_FUNC_INT(bcm2835_i2c_set_baudrate);
INT_FUNC_ISTR_L(bcm2835_i2c_write);
INT_FUNC_OSTR_L(bcm2835_i2c_read);
//INT_FUNC_P_OSTR_L(bcm2835_i2c_read_register_rs);
INT_FUNC_ISTR_L_OSTR_L(bcm2835_i2c_write_read_rs);

/* time */
INT_FUNC(bcm2835_st_read);
VOID_FUNC_INT_INT(bcm2835_st_delay);

/* pwm */
VOID_FUNC_INT(bcm2835_pwm_set_clock);
VOID_FUNC_INT_INT_INT(bcm2835_pwm_set_mode);
VOID_FUNC_INT_INT(bcm2835_pwm_set_range);
VOID_FUNC_INT_INT(bcm2835_pwm_set_data);

REG_END();

LUALIB_API int luaopen_bcm2835lua51 (lua_State *L) 
{
  luaL_register(L, "bcm2835", REG_BEGIN());
  return 1;
}

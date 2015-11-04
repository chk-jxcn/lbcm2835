#include <stdio.h>

#include "bcm2835.h"
#define PRINT_CONSTANT(name) printf(#name" = %d\n", name)

/* export from perl Device-BCM2835 module. */
int main()
{
	PRINT_CONSTANT(BCM2835_BLOCK_SIZE);
	PRINT_CONSTANT(BCM2835_CLOCK_BASE);
	PRINT_CONSTANT(BCM2835_GPAFEN0);
	PRINT_CONSTANT(BCM2835_GPAFEN1);
	PRINT_CONSTANT(BCM2835_GPAREN0);
	PRINT_CONSTANT(BCM2835_GPAREN1);
	PRINT_CONSTANT(BCM2835_GPCLR0);
	PRINT_CONSTANT(BCM2835_GPCLR1);
	PRINT_CONSTANT(BCM2835_GPEDS0);
	PRINT_CONSTANT(BCM2835_GPEDS1);
	PRINT_CONSTANT(BCM2835_GPFEN0);
	PRINT_CONSTANT(BCM2835_GPFEN1);
	PRINT_CONSTANT(BCM2835_GPFSEL0);
	PRINT_CONSTANT(BCM2835_GPFSEL1);
	PRINT_CONSTANT(BCM2835_GPFSEL2);
	PRINT_CONSTANT(BCM2835_GPFSEL3);
	PRINT_CONSTANT(BCM2835_GPFSEL4);
	PRINT_CONSTANT(BCM2835_GPFSEL5);
	PRINT_CONSTANT(BCM2835_GPHEN0);
	PRINT_CONSTANT(BCM2835_GPHEN1);
	PRINT_CONSTANT(BCM2835_GPIO_BASE);
	PRINT_CONSTANT(BCM2835_GPIO_FSEL_ALT0);
	PRINT_CONSTANT(BCM2835_GPIO_FSEL_ALT1);
	PRINT_CONSTANT(BCM2835_GPIO_FSEL_ALT2);
	PRINT_CONSTANT(BCM2835_GPIO_FSEL_ALT3);
	PRINT_CONSTANT(BCM2835_GPIO_FSEL_ALT4);
	PRINT_CONSTANT(BCM2835_GPIO_FSEL_ALT5);
	PRINT_CONSTANT(BCM2835_GPIO_FSEL_INPT);
	PRINT_CONSTANT(BCM2835_GPIO_FSEL_MASK);
	PRINT_CONSTANT(BCM2835_GPIO_FSEL_OUTP);
	PRINT_CONSTANT(BCM2835_GPIO_PADS);
	PRINT_CONSTANT(BCM2835_GPIO_PUD_DOWN);
	PRINT_CONSTANT(BCM2835_GPIO_PUD_OFF);
	PRINT_CONSTANT(BCM2835_GPIO_PUD_UP);
	PRINT_CONSTANT(BCM2835_GPIO_PWM);
	PRINT_CONSTANT(BCM2835_GPLEN0);
	PRINT_CONSTANT(BCM2835_GPLEN1);
	PRINT_CONSTANT(BCM2835_GPLEV0);
	PRINT_CONSTANT(BCM2835_GPLEV1);
	PRINT_CONSTANT(BCM2835_GPPUD);
	PRINT_CONSTANT(BCM2835_GPPUDCLK0);
	PRINT_CONSTANT(BCM2835_GPPUDCLK1);
	PRINT_CONSTANT(BCM2835_GPREN0);
	PRINT_CONSTANT(BCM2835_GPREN1);
	PRINT_CONSTANT(BCM2835_GPSET0);
	PRINT_CONSTANT(BCM2835_GPSET1);
	PRINT_CONSTANT(BCM2835_PADS_GPIO_0_27);
	PRINT_CONSTANT(BCM2835_PADS_GPIO_28_45);
	PRINT_CONSTANT(BCM2835_PADS_GPIO_46_53);
	PRINT_CONSTANT(BCM2835_PAD_DRIVE_10mA);
	PRINT_CONSTANT(BCM2835_PAD_DRIVE_12mA);
	PRINT_CONSTANT(BCM2835_PAD_DRIVE_14mA);
	PRINT_CONSTANT(BCM2835_PAD_DRIVE_16mA);
	PRINT_CONSTANT(BCM2835_PAD_DRIVE_2mA);
	PRINT_CONSTANT(BCM2835_PAD_DRIVE_4mA);
	PRINT_CONSTANT(BCM2835_PAD_DRIVE_6mA);
	PRINT_CONSTANT(BCM2835_PAD_DRIVE_8mA);
	PRINT_CONSTANT(BCM2835_PAD_GROUP_GPIO_0_27);
	PRINT_CONSTANT(BCM2835_PAD_GROUP_GPIO_28_45);
	PRINT_CONSTANT(BCM2835_PAD_GROUP_GPIO_46_53);
	PRINT_CONSTANT(BCM2835_PAD_HYSTERESIS_ENABLED);
	PRINT_CONSTANT(BCM2835_PAD_SLEW_RATE_UNLIMITED);
	PRINT_CONSTANT(BCM2835_PAGE_SIZE);
	PRINT_CONSTANT(BCM2835_PERI_BASE);
	PRINT_CONSTANT(BCM2835_PWM0_DATA);
	PRINT_CONSTANT(BCM2835_PWM0_ENABLE);
	PRINT_CONSTANT(BCM2835_PWM0_MS_MODE);
	PRINT_CONSTANT(BCM2835_PWM0_OFFSTATE);
	PRINT_CONSTANT(BCM2835_PWM0_RANGE);
	PRINT_CONSTANT(BCM2835_PWM0_REPEATFF);
	PRINT_CONSTANT(BCM2835_PWM0_REVPOLAR);
	PRINT_CONSTANT(BCM2835_PWM0_SERIAL);
	PRINT_CONSTANT(BCM2835_PWM0_USEFIFO);
	PRINT_CONSTANT(BCM2835_PWM1_DATA);
	PRINT_CONSTANT(BCM2835_PWM1_ENABLE);
	PRINT_CONSTANT(BCM2835_PWM1_MS_MODE);
	PRINT_CONSTANT(BCM2835_PWM1_OFFSTATE);
	PRINT_CONSTANT(BCM2835_PWM1_RANGE);
	PRINT_CONSTANT(BCM2835_PWM1_REPEATFF);
	PRINT_CONSTANT(BCM2835_PWM1_REVPOLAR);
	PRINT_CONSTANT(BCM2835_PWM1_SERIAL);
	PRINT_CONSTANT(BCM2835_PWM1_USEFIFO);
	PRINT_CONSTANT(BCM2835_PWMCLK_CNTL);
	PRINT_CONSTANT(BCM2835_PWMCLK_DIV);
	PRINT_CONSTANT(BCM2835_PWM_CONTROL);
	PRINT_CONSTANT(BCM2835_PWM_STATUS);
	PRINT_CONSTANT(BCM2835_SPI0_BASE);
	PRINT_CONSTANT(BCM2835_SPI0_CLK);
	PRINT_CONSTANT(BCM2835_SPI0_CS);
	PRINT_CONSTANT(BCM2835_SPI0_CS_ADCS);
	PRINT_CONSTANT(BCM2835_SPI0_CS_CLEAR);
	PRINT_CONSTANT(BCM2835_SPI0_CS_CLEAR_RX);
	PRINT_CONSTANT(BCM2835_SPI0_CS_CLEAR_TX);
	PRINT_CONSTANT(BCM2835_SPI0_CS_CPHA);
	PRINT_CONSTANT(BCM2835_SPI0_CS_CPOL);
	PRINT_CONSTANT(BCM2835_SPI0_CS_CS);
	PRINT_CONSTANT(BCM2835_SPI0_CS_CSPOL);
	PRINT_CONSTANT(BCM2835_SPI0_CS_CSPOL0);
	PRINT_CONSTANT(BCM2835_SPI0_CS_CSPOL1);
	PRINT_CONSTANT(BCM2835_SPI0_CS_CSPOL2);
	PRINT_CONSTANT(BCM2835_SPI0_CS_DMAEN);
	PRINT_CONSTANT(BCM2835_SPI0_CS_DMA_LEN);
	PRINT_CONSTANT(BCM2835_SPI0_CS_DONE);
	PRINT_CONSTANT(BCM2835_SPI0_CS_INTD);
	PRINT_CONSTANT(BCM2835_SPI0_CS_INTR);
	PRINT_CONSTANT(BCM2835_SPI0_CS_LEN);
	PRINT_CONSTANT(BCM2835_SPI0_CS_LEN_LONG);
	PRINT_CONSTANT(BCM2835_SPI0_CS_LMONO);
	PRINT_CONSTANT(BCM2835_SPI0_CS_REN);
	PRINT_CONSTANT(BCM2835_SPI0_CS_RXD);
	PRINT_CONSTANT(BCM2835_SPI0_CS_RXF);
	PRINT_CONSTANT(BCM2835_SPI0_CS_RXR);
	PRINT_CONSTANT(BCM2835_SPI0_CS_TA);
	PRINT_CONSTANT(BCM2835_SPI0_CS_TE_EN);
	PRINT_CONSTANT(BCM2835_SPI0_CS_TXD);
	PRINT_CONSTANT(BCM2835_SPI0_DC);
	PRINT_CONSTANT(BCM2835_SPI0_DLEN);
	PRINT_CONSTANT(BCM2835_SPI0_FIFO);
	PRINT_CONSTANT(BCM2835_SPI0_LTOH);
	PRINT_CONSTANT(BCM2835_SPI_BIT_ORDER_LSBFIRST);
	PRINT_CONSTANT(BCM2835_SPI_BIT_ORDER_MSBFIRST);
	PRINT_CONSTANT(BCM2835_SPI_CLOCK_DIVIDER_1);
	PRINT_CONSTANT(BCM2835_SPI_CLOCK_DIVIDER_1024);
	PRINT_CONSTANT(BCM2835_SPI_CLOCK_DIVIDER_128);
	PRINT_CONSTANT(BCM2835_SPI_CLOCK_DIVIDER_16);
	PRINT_CONSTANT(BCM2835_SPI_CLOCK_DIVIDER_16384);
	PRINT_CONSTANT(BCM2835_SPI_CLOCK_DIVIDER_2);
	PRINT_CONSTANT(BCM2835_SPI_CLOCK_DIVIDER_2048);
	PRINT_CONSTANT(BCM2835_SPI_CLOCK_DIVIDER_256);
	PRINT_CONSTANT(BCM2835_SPI_CLOCK_DIVIDER_32);
	PRINT_CONSTANT(BCM2835_SPI_CLOCK_DIVIDER_32768);
	PRINT_CONSTANT(BCM2835_SPI_CLOCK_DIVIDER_4);
	PRINT_CONSTANT(BCM2835_SPI_CLOCK_DIVIDER_4096);
	PRINT_CONSTANT(BCM2835_SPI_CLOCK_DIVIDER_512);
	PRINT_CONSTANT(BCM2835_SPI_CLOCK_DIVIDER_64);
	PRINT_CONSTANT(BCM2835_SPI_CLOCK_DIVIDER_65536);
	PRINT_CONSTANT(BCM2835_SPI_CLOCK_DIVIDER_8);
	PRINT_CONSTANT(BCM2835_SPI_CLOCK_DIVIDER_8192);
	PRINT_CONSTANT(BCM2835_SPI_CS0);
	PRINT_CONSTANT(BCM2835_SPI_CS1);
	PRINT_CONSTANT(BCM2835_SPI_CS2);
	PRINT_CONSTANT(BCM2835_SPI_CS_NONE);
	PRINT_CONSTANT(BCM2835_SPI_MODE0);
	PRINT_CONSTANT(BCM2835_SPI_MODE1);
	PRINT_CONSTANT(BCM2835_SPI_MODE2);
	PRINT_CONSTANT(BCM2835_SPI_MODE3);
	PRINT_CONSTANT(HIGH);
	PRINT_CONSTANT(LOW);
	PRINT_CONSTANT(RPI_GPIO_P1_03);
	PRINT_CONSTANT(RPI_GPIO_P1_05);
	PRINT_CONSTANT(RPI_GPIO_P1_07);
	PRINT_CONSTANT(RPI_GPIO_P1_08);
	PRINT_CONSTANT(RPI_GPIO_P1_10);
	PRINT_CONSTANT(RPI_GPIO_P1_11);
	PRINT_CONSTANT(RPI_GPIO_P1_12);
	PRINT_CONSTANT(RPI_GPIO_P1_13);
	PRINT_CONSTANT(RPI_GPIO_P1_15);
	PRINT_CONSTANT(RPI_GPIO_P1_16);
	PRINT_CONSTANT(RPI_GPIO_P1_18);
	PRINT_CONSTANT(RPI_GPIO_P1_19);
	PRINT_CONSTANT(RPI_GPIO_P1_21);
	PRINT_CONSTANT(RPI_GPIO_P1_22);
	PRINT_CONSTANT(RPI_GPIO_P1_23);
	PRINT_CONSTANT(RPI_GPIO_P1_24);
	PRINT_CONSTANT(RPI_GPIO_P1_26);
	PRINT_CONSTANT(RPI_V2_GPIO_P1_03);
	PRINT_CONSTANT(RPI_V2_GPIO_P1_05);
	PRINT_CONSTANT(RPI_V2_GPIO_P1_07);
	PRINT_CONSTANT(RPI_V2_GPIO_P1_08);
	PRINT_CONSTANT(RPI_V2_GPIO_P1_10);
	PRINT_CONSTANT(RPI_V2_GPIO_P1_11);
	PRINT_CONSTANT(RPI_V2_GPIO_P1_12);
	PRINT_CONSTANT(RPI_V2_GPIO_P1_13);
	PRINT_CONSTANT(RPI_V2_GPIO_P1_15);
	PRINT_CONSTANT(RPI_V2_GPIO_P1_16);
	PRINT_CONSTANT(RPI_V2_GPIO_P1_18);
	PRINT_CONSTANT(RPI_V2_GPIO_P1_19);
	PRINT_CONSTANT(RPI_V2_GPIO_P1_21);
	PRINT_CONSTANT(RPI_V2_GPIO_P1_22);
	PRINT_CONSTANT(RPI_V2_GPIO_P1_23);
	PRINT_CONSTANT(RPI_V2_GPIO_P1_24);
	PRINT_CONSTANT(RPI_V2_GPIO_P1_26);
	PRINT_CONSTANT(RPI_V2_GPIO_P5_03);
	PRINT_CONSTANT(RPI_V2_GPIO_P5_04);
	PRINT_CONSTANT(RPI_V2_GPIO_P5_05);
	PRINT_CONSTANT(RPI_V2_GPIO_P5_06);
	return 0;
}

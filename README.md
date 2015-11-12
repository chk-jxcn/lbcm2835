##About lbcm2835

A lua binding of bcm2835 c library.

Note that libbcm2835 don't have a -fPIC compile option, so compile it with below command:
```
gcc -fPIC -O3 -c bcm2835.c -o bcm2835.o
gcc -fPIC -O0 -c bcm2835lua51.c -o bcm2835lua51.o -I/usr/include/lua5.1/
gcc  -shared -fPIC -o bcm2835lua51.so bcm2835lua51.o bcm2835.o
```

##Example
```lua
local pi = require "bcm2835" --constants will loaded into bcm2835
require "contants" -- or you can also load contants into global table.

--[[
export functions:
see bcm2835.h
]]
PIN = 18
pi.bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_OUTP) --set PIN 18 output mode.
pi.bcm2835_gpio_write(PIN, HIGH)  -- write high to PIN 18

pi.bcm2835_delay(18)  -- sleep for a long time(>100us)
pi.bcm2835_delayMicroseconds(10)  -- busy wait on system timer register. (~us)


```

###TODO
* I2C and SPI did't test.

* operat PIN by table

example of Mike Pall
```lua
-- User-level (non-raw) GPIO API. The numbers correspond to the numbering
-- on the GPIO connector drawing: http://elinux.org/File:GPIOs.png
-- Input/output direction is automatically selected.

local function pinerror(t, i)
  error("bad GPIO pin number "..tostring(i), 2)
end
local rawmap = {[0]=17, 18, 21, 22, 23, 24, 25, 4}
local inmap = setmt({[0]=-1,-1,-1,-1,-1,-1,-1,-1,-1}, {__index=pinerror})
local outmap = setmt({[0]=-1,-1,-1,-1,-1,-1,-1,-1,-1}, {__index=pinerror})

pin = setmt({}, {
  __index = function(t, i)
    local pin = inmap[i]
    if pin < 0 then
      pin = rawmap[i]; inmap[i] = pin; outmap[i] = -1; _rawdir(pin, 0)
    end
    return band(shr(gp[13], pin), 1)
  end,
  __newindex = function(t, i, v)
    local pin = outmap[i]
    if pin < 0 then
      pin = rawmap[i]; outmap[i] = pin; inmap[i] = -1; _rawdir(pin, 1)
    end
    gp[10-band(v, 1)*3] = shl(1, pin)
  end,
})

function msleep(ms)
  C.poll(nil, 0, ms)
end

local gpio = require("rpi.gpio")

for i=1,10 do
  print("GPIO 6:", gpio.pin[6])
  gpio.pin[0] = 1
  gpio.msleep(100)
  gpio.pin[0] = 0
  gpio.msleep(100)
end

```

###License
None

###Contact
chk.jxcn#gmail.com


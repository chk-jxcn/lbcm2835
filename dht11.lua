pi = require "bcm2835"
require "constants"

seq = {}
PIN = 12
pi.bcm2835_init()
pi.bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_OUTP)

--[[

1. -> HIGH
2. -> LOW 18ms
3. -> HIGH
4. <- 80us LOW
5. <- 80us HIGH
6. <- max(50+70)* 40 = 4800us = 4.8ms
7. <- 50us LOW

]]
pi.bcm2835_gpio_write(PIN, LOW)
pi.bcm2835_delay(18)		
pi.bcm2835_gpio_write(PIN, HIGH)
pi.bcm2835_gpio_write(PIN, LOW)
pi.bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_INPT)
--pi.bcm2835_gpio_set_pud(PIN, BCM2835_GPIO_PUD_UP)
i = 0
interval = 5
count = 4800 / interval
stop = 100 / interval		-- stop at 100us of continuous HIGH output 
repeat
	local out = pi.bcm2835_gpio_lev(PIN)
	table.insert(seq, out)
	pi.bcm2835_delayMicroseconds(interval)
	i = i + 1
until i >= count

bits = {}
low = 0
high = 0

-- when change high to low, compare last low time and high time.
for _,v in ipairs(seq) do
	if v == 1 then
		if high >= stop then break end
		-- print "	|"
		high = high + 1
	else
		-- print "|"
		if high ~= 0 then -- do the compare
			if low ~= 0 then
				if high < low then
					table.insert(bits, 0)
				else
					table.insert(bits, 1)
				end
			end
			high = 0
			low = 0
		end
		low = low + 1
	end
end

-- delete fisrt bit
table.remove(bits, 1)
if table.maxn(bits) ~= 40 then
	error(string.format("data not 40 bits, but %d", table.maxn(bits)))
end

print(table.concat(bits,""))

-- convert bits to digit
data = {}
dig = 0
for k,v in ipairs(bits) do
	dig = dig + v * 2^(-k%8)
	if k % 8 == 0 then
		table.insert(data, dig)
		dig = 0
	end
end

print("TEMP:" .. data[3] .. "	H:" .. data[1])
if data[5] == data[1] + data[3] then 
	print "Parity OK"
else
	print "Parity WRONG"
end





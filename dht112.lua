pi = require "bcm2835"
require "constants"

seq = {}
PIN = 12
pi.bcm2835_init()

--[[

1. -> HIGH
2. -> LOW 18ms
3. -> HIGH
4. <- 80us LOW
5. <- 80us HIGH
6. <- max(50+70)* 40 = 4800us = 4.8ms
7. <- 50us LOW

]]

pi.bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_OUTP)
pi.bcm2835_gpio_set_pud(PIN, BCM2835_GPIO_PUD_UP)
pi.bcm2835_gpio_write(PIN, LOW)
pi.bcm2835_delay(20)
pi.bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_INPT)
pi.bcm2835_delayMicroseconds(10)

low = 0
high = 0
raw = {}
interval = 1
repeat
	local out = pi.bcm2835_gpio_lev(PIN)
	if out == 1 then
		high = high + 1
		if low ~= 0 and high >= 5 * low  or high > 100 then break end
	else
		if high ~= 0 then
			if low ~= 0 then
				table.insert(raw, {low, high})
			end
			high = 0
			low = 0
		end
		low = low + 1
	end
	-- pi.bcm2835_delayMicroseconds(interval)
until nil 

-- convert to bits 
bits = {}
for _, v in ipairs(raw) do
	-- print(v[1], v[2])
	if v[1] * 0.8 < v[2]  then
		table.insert(bits, 1)
	else
		table.insert(bits, 0)
	end

end

-- delete fisrt bit
table.remove(bits, 1)
if table.maxn(bits) ~= 40 then
	print(string.format("data not 40 bits, but %d", table.maxn(bits)))
	return
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

io.write("TEMP:" .. data[3] .. "	H:" .. data[1] .. "	")
if data[5] == data[1] + data[3] then
	print "P: GOOD"
else
	print "P: ERROR"
end


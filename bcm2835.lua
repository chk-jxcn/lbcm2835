local bcm2835 = require "bcm2835lua51"
local print = print

setmetatable(bcm2835, {__index = require "constants"})
setfenv(1, bcm2835)


return bcm2835

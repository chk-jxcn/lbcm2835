local _M = require "bcm2835lua51"
local require = require
local setfenv = setfenv
local _G = _G

setfenv(0, _M)
package.loaded.constants=nil
require "bcm2835.constants"
package.loaded.constants=nil
setfenv(0, _G)

return _M

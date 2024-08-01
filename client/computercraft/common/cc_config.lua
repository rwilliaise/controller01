
local config = require "common.config"
local cc_config = setmetatable(
    {},
    {
        __index = config,
        __tostring = function()
            return "cc_config"
        end
    }
)
cc_config.__index = cc_config

function cc_config.new(filename)
    local out = setmetatable({}, cc_config)
    return out:constructor(filename) or out
end

function cc_config:constructor(filename)
    config:constructor(filename)
end

function cc_config:save(filename)
    local file = fs.open(filename, "w")
    file.write(textutils.serialize(self._internal))
    file.close()
end

function cc_config:load(filename)
    local file = fs.open(filename, "r")
    local contents = file.readAll()
    file.close()
    self._internal = textutils.unserialize(contents)
end

return cc_config

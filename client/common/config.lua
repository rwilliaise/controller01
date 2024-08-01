--[[
    Really basic config system.
]]--

local config = setmetatable(
    {},
    {
        __tostring = function()
            return "config"
        end
    }
)
config.__index = config

function config.new(filename)
    local out = setmetatable({}, config)
    return out:constructor(filename) or out
end

function config:constructor(filename)
    self:load(filename)
    if not self._internal then
        self._internal = {}
    end
end

function config:has(key)
    return self._internal[key] ~= nil
end

function config:get(key, default)
    if not self._internal[key] and default then
        self._internal[key] = default
    end
    return self._internal[key]
end

function config:set(key, value)
    self._internal[key] = value
end

-- methods that must be implemented on client versions
function config:save(filename)
    error("'save' unimplemented on " .. tostring(self))
end

-- sets self._internal to a dictionary of config values
function config:load(filename)
    error("'load' unimplemented on " .. tostring(self))
end

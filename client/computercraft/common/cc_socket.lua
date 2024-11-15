--[[
    Implementation of the generic socket for ComputerCraft websockets.
]]--

local socket = require "common.socket"
local cc_socket = setmetatable(
    {},
    {
        __index = socket,
        __tostring = function()
            return "cc_socket"
        end
    }
)
cc_socket.__index = cc_socket

function cc_socket.new()
    return setmetatable({}, cc_socket)
end

function cc_socket:unwrap()
    return assert(self._internal, "no socket!")
end

-- implementation
function cc_socket:open(url)
    local out, message = http.websocket(url, { })
    assert(out, "failed to open socket: " .. tostring(message))
    self._internal = out
end

function cc_socket:send(data)
    self:unwrap().send(data)
end

function cc_socket:receive(timeout)
    return self:unwrap().receive(timeout)
end

function cc_socket:close()
    self:unwrap().close()
end

return cc_socket

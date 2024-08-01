--[[
    Websocket API that must be implemented on client versions.
]]--

local socket = setmetatable(
    {},
    {
        __tostring = function()
            return "socket"
        end
    }
)
socket.__index = socket

function socket.new()
    return setmetatable({}, socket)
end

function socket:send_json(obj)
    if JSON then
        -- TODO: oc
        return
    elseif textutils then
        socket:send(textutils.serializeJSON(obj))
        return
    end
    error("'send_json' unimplemented on " .. tostring(self))
end

-- methods that must be implemented on client versions
function socket:open(url)
    error("'open' unimplemented on " .. tostring(self))
end

function socket:send(data)
    error("'send' unimplemented on " .. tostring(self))
end

function socket:receive()
    error("'receive' unimplemented on " .. tostring(self))
end

function socket:close()
    error("'close' unimplemented on " .. tostring(self))
end

return socket

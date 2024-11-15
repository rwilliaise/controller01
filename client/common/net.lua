--[[
    A networking system based on the generic socket.
]]--

local net = setmetatable(
    {},
    {
        __tostring = function()
            return "net"
        end
    }
)
net.__index = net

function net.new(socket)
    local self = setmetatable({}, net)
    self:constructor(socket)
    return self
end

function net:constructor(socket)
    assert(socket, "no socket!")
    self.socket = socket
end

function net:update()
    self.socket:send("hello")
    local data = self.socket:receive()
    print(data)
end

return net

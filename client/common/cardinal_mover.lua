--[[
    A locomotion system where the bot can face the four cardinal directions, and
    move up, down, and forward. Used by ComputerCraft Turtles and OpenComputers Robots.
]]--

local cardinal_mover = setmetatable(
    {},
    {
        __tostring = function()
            return "cardinal_mover"
        end
    }
)
cardinal_mover.__index = cardinal_mover

function cardinal_mover.new()
    return setmetatable({}, cardinal_mover)
end

-- methods that must be implemented on client versions
function cardinal_mover:move_forward()
    error("'move_forward' unimplemented on " .. tostring(self))
end

function cardinal_mover:move_up()
    error("'move_up' unimplemented on " .. tostring(self))
end

function cardinal_mover:move_down()
    error("'move_down' unimplemented on " .. tostring(self))
end

function cardinal_mover:get_power()
    error("'get_power' unimplemented on " .. tostring(self))
end

return cardinal_mover

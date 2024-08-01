
local cardinal_mover = require "common.cardinal_mover"
local turtle_mover = setmetatable(
    {},
    {
        __index = cardinal_mover,
        __tostring = function()
            return "turtle_mover"
        end
    }
)
turtle_mover.__index = turtle_mover

function turtle_mover.new()
    return setmetatable({}, turtle_mover)
end

function turtle_mover:move_forward()
    turtle.forward()
end

function turtle_mover:move_down()
    turtle.down()
end

function turtle_mover:move_up()
    turtle.up()
end

function turtle_mover:get_power()
    return turtle.getFuelLevel()
end

return turtle_mover

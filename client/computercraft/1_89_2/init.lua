
local cc_config = require "computercraft.common.cc_config"
local cc_socket = require "computercraft.common.cc_socket"
local net = require "common.net"
local CONFIG_FILE = "/controller01.cfg"

print("[+] starting controller01")
print("[+] loading config...")

local loaded_config = cc_config.new(CONFIG_FILE)
local websocket_url = loaded_config:get("websocket_url", "ws://localhost:8080")
loaded_config:upgrade()

local turtle_socket = cc_socket.new()
turtle_socket:open(websocket_url)

local turtle_net = net.new(turtle_socket)

local function clean_up()
    print("[-] saving config...")
    if GLOBAL_CONFIG then
        GLOBAL_CONFIG:save(CONFIG_FILE)
    end
end

-- overrides os.pullEvent to save config and then exit on terminate
function os.pullEvent(filter)
    local out = { os.pullEventRaw(filter) }
    if out[1] == "terminate" then
        clean_up()
        print("[-] terminated")
        os.exit()
    end
    return table.unpack(out)
end

local function net_loop()
    while true do
        turtle_net:update()
    end
end

local success, error = pcall(function()
    parallel.waitForAny(net_loop)
end)
if not success then
    print("[-] " .. error)
end

clean_up()


local cc_config = require "computercraft.common.cc_config"
local CONFIG_FILE = "/controller01.cfg"

print("[+] starting controller01")
print("[+] loading config...")

local loaded_config = cc_config.new(CONFIG_FILE)


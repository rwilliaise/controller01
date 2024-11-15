
set(COMMON_SRCS
    cardinal_mover
    config
    net
    socket
)
set(CLIENT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

file(
    REAL_PATH ${CMAKE_CURRENT_SOURCE_DIR}/amalg.lua AMALG_LUA
)
file(
    REAL_PATH ${CMAKE_CURRENT_SOURCE_DIR}/minifier.lua MINIFIER_LUA
)

set(SRCS "")
foreach(src ${COMMON_SRCS})
    set(SRCS "${SRCS};common.${src}")
endforeach(src ${COMMON_SRCS})
string(STRIP "${SRCS}" COMMON_SRCS)

find_program(LUA_PROGRAM NAMES lua)
add_subdirectory(computercraft)


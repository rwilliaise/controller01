

set(TURTLE_SRCS

)

set(SRCS "")
foreach(src ${TURTLE_SRCS})
    set(SRCS "${SRCS} computercraft.1_89_2.${src}")
endforeach(src ${TURTLE_SRCS})

add_custom_target(computercraft_1_89_2
    DEPENDS
        "${CMAKE_CURRENT_BINARY_DIR}/dist_large.lua"
        "${CMAKE_CURRENT_BINARY_DIR}/dist.lua"
)

add_custom_command(
    OUTPUT
        "${CMAKE_CURRENT_BINARY_DIR}/dist_large.lua"
    COMMAND
        ${LUA_PROGRAM} ${AMALG_LUA}
            -s ${CMAKE_CURRENT_SOURCE_DIR}/init.lua
            -o ${CMAKE_CURRENT_BINARY_DIR}/dist_large.lua
            -- ${COMMON_SRCS} ${CC_COMMON_SRCS} ${SRCS}
    WORKING_DIRECTORY
        ${CLIENT_DIR}
)

add_custom_command(
    OUTPUT
        "${CMAKE_CURRENT_BINARY_DIR}/dist.lua"
    COMMAND
        ${LUA_PROGRAM} ${MINIFIER_LUA}
            ${CMAKE_CURRENT_BINARY_DIR}/dist_large.lua
            ${CMAKE_CURRENT_BINARY_DIR}/dist.lua
    DEPENDS
        "${CMAKE_CURRENT_BINARY_DIR}/dist_large.lua"
)


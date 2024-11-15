
set(CC_COMMON_SRCS
    cc_config
    cc_socket
    turtle_mover
)

set(SRCS "")
foreach(src ${CC_COMMON_SRCS})
    set(SRCS "${SRCS};computercraft.common.${src}")
endforeach(src ${CC_COMMON_SRCS})
string(STRIP "${SRCS}" CC_COMMON_SRCS)

add_subdirectory(1_89_2)

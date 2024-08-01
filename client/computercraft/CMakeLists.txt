
set(CC_COMMON_SRCS
    cc_config
    turtle_mover
)

set(SRCS "")
foreach(src ${COMMON_SRCS})
    set(SRCS "${SRCS} computercraft.common.${src}")
endforeach(src ${COMMON_SRCS})
string(STRIP ${SRCS} COMMON_SRCS)


add_subdirectory(1_89_2)

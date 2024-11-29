
add_library(server_control STATIC
    control.h
    ws_connection.cpp
    ws_connection.h
    ws_server.cpp
    ws_server.h
)
add_library(server::control ALIAS server_control)
target_link_libraries(server_control PRIVATE Boost::boost Boost::log)



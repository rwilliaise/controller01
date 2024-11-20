
add_library(server_control STATIC
    control.h
    server.cpp
    server.h
    ws_connection.cpp
    ws_connection.h
    ws_listener.cpp
    ws_listener.h
)
add_library(server::control ALIAS server_control)



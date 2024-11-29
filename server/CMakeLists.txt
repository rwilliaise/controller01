 
find_package(Boost REQUIRED COMPONENTS log)

add_subdirectory(control/)

add_executable(server
    main.cpp
)
target_link_libraries(server PRIVATE Boost::boost Boost::log server::control)


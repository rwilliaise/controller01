 
find_package(Boost REQUIRED)

add_executable(server
    main.cpp
)
target_link_libraries(server PRIVATE Boost::boost)


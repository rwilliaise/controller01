
#include <boost/log/trivial.hpp>
#include <boost/program_options.hpp>
#include <iostream>
#include <algorithm>

#include "control/ws_server.h"

int main(int argc, const char *argv[])
{
    try {
        if (argc != 3) {
            std::cout << "Usage: server <address> <port>" << std::endl;
            return 1;
        }
        int thread_count = std::thread::hardware_concurrency();
        int server_threads = std::max(1, thread_count - 1);
        auto server = std::make_shared<control::ws_server>(server_threads);
        server->open(argv[1], std::atoi(argv[2]));
        server->run();
    } catch (std::exception &e) {
        BOOST_LOG_TRIVIAL(fatal) << "std::exception -> " << e.what();
        return 1;
    }
    return 0;
}

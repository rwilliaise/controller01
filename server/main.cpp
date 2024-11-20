
#include <boost/log/trivial.hpp>
#include <boost/program_options.hpp>
#include <iostream>
#include <algorithm>

#include "control/server.h"

int main(int argc, const char *argv[])
{
    try {
        if (argc != 3) {
            std::cout << "Usage: server <address> <port>" << std::endl;
            return 1;
        }
        const auto thread_count = std::thread::hardware_concurrency();
        const auto server_threads = std::max(1, thread_count - 1);
        control::server server(server_threads);
    } catch (std::exception &e) {
        BOOST_LOG_TRIVIAL(fatal) << "std::exception -> " << e.what();
        return 1;
    }
    return 0;
}

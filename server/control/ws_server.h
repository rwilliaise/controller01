
#pragma once

#include "control.h"

#include <memory>
#include <thread>
#include <vector>

CONTROL_NAMESPACE_BEGIN

class ws_server : public std::enable_shared_from_this<ws_server> {
public:

    enum class error_code {
        success,
        open_fail,
        bind_fail,
        listen_fail,
    };

public:
    ws_server(int thread_count);

    // start listening for connections
    error_code open(const std::string &address, int port);
    // start accepting connections
    void run();

private:
    void start_accept();
    void on_accept(beast::error_code ec, tcp::socket socket);

private:
    int thread_count;
    net::io_context ctx;
    tcp::acceptor acceptor;
    std::vector<std::thread> threads;
};

CONTROL_NAMESPACE_END

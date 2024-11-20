
#pragma once

#include "control.h"
#include <boost/asio/io_context.hpp>
#include <memory>

CONTROL_NAMESPACE_BEGIN

class ws_listener : public std::enable_shared_from_this<ws_listener> {
public:

    enum class error_code {
        success,
        open_fail,
        bind_fail,
        listen_fail,
    };

public:
    ws_listener(net::io_context &);

    // start listening for connections
    error_code open(const std::string &address, int port);
    // start accepting connections
    void run();

private:
    net::io_context &ctx;
    tcp::acceptor acceptor;
};

CONTROL_NAMESPACE_END

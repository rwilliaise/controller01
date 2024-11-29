
#pragma once

#include "control.h"

#include <memory>

CONTROL_NAMESPACE_BEGIN

class ws_connection : public std::enable_shared_from_this<ws_connection> {
public:

    explicit ws_connection(tcp::socket &&);

    void execute();

private:
    void run();
    void on_accept(beast::error_code ec);

    void start_read();
    void on_read(beast::error_code ec, std::size_t bytes_read);

private:
    websocket::stream<beast::tcp_stream> ws;
    beast::flat_buffer buffer;

};

CONTROL_NAMESPACE_END

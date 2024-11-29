
#include "ws_connection.h"
#include "control.h"

#include <boost/log/trivial.hpp>

CONTROL_NAMESPACE_BEGIN

ws_connection::ws_connection(tcp::socket &&socket) : ws(std::move(socket))
{
}

void ws_connection::execute()
{
    net::dispatch(
        ws.get_executor(),
        beast::bind_front_handler(&ws_connection::run, shared_from_this())
    );
}

void ws_connection::run()
{
    ws.set_option(websocket::stream_base::timeout::suggested(beast::role_type::server));
    ws.set_option(websocket::stream_base::decorator(
        [](websocket::response_type &res)
        {
            res.set(http::field::server, "");
        }));
    ws.async_accept(
        beast::bind_front_handler(&ws_connection::on_accept, shared_from_this())
    );
}

void ws_connection::on_accept(beast::error_code ec)
{
    if (ec) {
        BOOST_LOG_TRIVIAL(error) << "accept failure: " << ec.message() << std::endl;
        return;
    }
    start_read();
}

void ws_connection::start_read()
{
    ws.async_read(
        buffer,
        beast::bind_front_handler(&ws_connection::on_read, shared_from_this())
    );
}

void ws_connection::on_read(beast::error_code ec, std::size_t)
{
    if (ec) {
        BOOST_LOG_TRIVIAL(error) << "read failure: " << ec.message() << std::endl;
        return;
    }
}

CONTROL_NAMESPACE_END


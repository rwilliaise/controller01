
#include "ws_listener.h"
#include "control.h"
#include <boost/asio/io_context.hpp>
#include <boost/beast/core/error.hpp>
#include <boost/log/trivial.hpp>

CONTROL_NAMESPACE_BEGIN

ws_listener::ws_listener(net::io_context &ctx): ctx(ctx), acceptor(ctx)
{
}

ws_listener::error_code ws_listener::open(const std::string &address, int port)
{
    beast::error_code err;
    const net::ip::address ip_address = net::ip::make_address(address);
    tcp::endpoint endpoint(ip_address, port);
    acceptor.open(endpoint.protocol(), err);
    if (err) {
        BOOST_LOG_TRIVIAL(error) << "open failure: " << err.message();
        return error_code::open_fail;
    }
    acceptor.set_option(net::socket_base::reuse_address(true));
    acceptor.bind(endpoint, err);
    if (err) {
        BOOST_LOG_TRIVIAL(error) << "bind failure: " << err.message();
        return error_code::bind_fail;
    }
    acceptor.listen(net::socket_base::max_listen_connections, err);
    if (err) {
        BOOST_LOG_TRIVIAL(error) << "listen failure: " << err.message();
        return error_code::listen_fail;
    }
    return error_code::success;
}

CONTROL_NAMESPACE_END

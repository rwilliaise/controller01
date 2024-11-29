
#include "ws_server.h"
#include "control.h"
#include "ws_connection.h"

#include <boost/log/trivial.hpp>

CONTROL_NAMESPACE_BEGIN

ws_server::ws_server(int thread_count): thread_count(thread_count), ctx(thread_count), acceptor(ctx)
{
}

ws_server::error_code ws_server::open(const std::string &address, int port)
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

void ws_server::run()
{
    start_accept();
    threads.reserve(thread_count);
    for (int i = 0; i < thread_count; i++)
        threads.emplace_back(
            [this]
            {
                ctx.run();
            }
        );
    ctx.run();
}

void ws_server::start_accept()
{
    acceptor.async_accept(
        net::make_strand(ctx),
        beast::bind_front_handler(&ws_server::on_accept, shared_from_this())
    );
}

void ws_server::on_accept(beast::error_code ec, tcp::socket socket)
{
    if (ec) {
        BOOST_LOG_TRIVIAL(error) << "accept failure: " << ec.what();
        return;
    }
    std::make_shared<ws_connection>(std::move(socket))->execute();
    start_accept();
}

CONTROL_NAMESPACE_END

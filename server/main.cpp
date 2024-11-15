
#include <boost/asio/io_context.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/websocket.hpp>
#include <iostream>
#include <thread>

namespace beast = boost::beast;
namespace websocket = beast::websocket;
namespace net = boost::asio;
using tcp = boost::asio::ip::tcp;

void do_session(tcp::socket socket)
{
    try {
        websocket::stream<tcp::socket> ws(std::move(socket));
        ws.accept();

        for (;;) {
            beast::flat_buffer buffer;
            ws.read(buffer);
            std::cout << "[ws] " << ws.got_text() << std::endl;
            ws.text(ws.got_text());
            ws.write(buffer.data());

        }
    } catch (beast::system_error &e) {
        if (e.code() != websocket::error::closed)
            std::cerr << "[beast::system_error] " << e.code().message() << std::endl;
    } catch (std::exception &e) {
        std::cerr << "[std::exception] " << e.what() << std::endl;
    }
}

int main(int argc, const char *argv[])
{
    try {
        if (argc != 3) {
            std::cout << "Usage: server <address> <port>" << std::endl;
            return 1;
        }
        auto const address = net::ip::make_address(argv[1]);
        const unsigned short port = std::atoi(argv[2]);
        net::io_context ctx(1);
        tcp::acceptor acceptor(ctx, {address, port});
        for (;;) {
            tcp::socket socket(ctx);
            acceptor.accept(socket);
            std::thread(&do_session, std::move(socket)).detach();
        }
    } catch (std::exception &e) {
        std::cerr << "[std::exception] " << e.what() << std::endl;
        return 1;
    }
    return 0;
}

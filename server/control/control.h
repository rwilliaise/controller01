
#pragma once

#include <boost/asio.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/websocket.hpp>

#define CONTROL_NAMESPACE_BEGIN namespace control {
#define CONTROL_NAMESPACE_END }

CONTROL_NAMESPACE_BEGIN

namespace beast = boost::beast;
namespace websocket = beast::websocket;
namespace net = boost::asio;
namespace http = beast::http;
using tcp = boost::asio::ip::tcp;

CONTROL_NAMESPACE_END


#pragma once

#include "control.h"

#include <boost/asio/io_context.hpp>
#include <memory>
#include <thread>

CONTROL_NAMESPACE_BEGIN

class server : public std::enable_shared_from_this<server> {
public:
    server(int threads);

private:
    net::io_context ctx;
    std::vector<std::thread> threads;

};

CONTROL_NAMESPACE_END

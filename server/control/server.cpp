
#include "server.h"
#include "control.h"

CONTROL_NAMESPACE_BEGIN

server::server(int thread_count) : ctx(thread_count)
{
    for (int i = 0; i < thread_count - 1; i++) {
    }
}

CONTROL_NAMESPACE_END

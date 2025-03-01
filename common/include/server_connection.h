#pragma once

#include "fwd.h"

namespace ftp
{

class server_connection
{
public:

    virtual ~server_connection() = default;

    virtual int listen(incoming_connection_shared handler) = 0;
};

server_connection_unique make_server_connection(uint16_t port);

} // namespace ftp

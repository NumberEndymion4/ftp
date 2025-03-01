#pragma once

#include "fwd.h"

#include <cstdint>
#include <string_view>

namespace ftp
{

class client_connection
{
public:

    virtual ~client_connection() = default;

    virtual broadcast_unique broadcast() = 0;
};

client_connection_unique make_client_connection(std::string_view address, uint16_t port);

} // namespace ftp

#pragma once

#include "fwd.h"

namespace ftp
{

class incoming_connection
{
public:

    virtual ~incoming_connection() = default;

    virtual void connect(broadcast_unique client) = 0;
};

} // namespace ftp

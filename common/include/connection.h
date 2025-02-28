#pragma once

#include "fwd.h"

namespace ftp
{

class connection
{
public:

    virtual ~connection() = default;

    virtual int listen(incoming_connection_shared handler) = 0;
};

connection_unique make_connection();

} // namespace ftp

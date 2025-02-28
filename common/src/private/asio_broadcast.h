#pragma once

#include <broadcast.h>

namespace ftp
{

class asio_broadcast : public broadcast
{
public:

    ~asio_broadcast() override = default;
};

} // namespace ftp

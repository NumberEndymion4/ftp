#pragma once

#include <string_view>

namespace ftp
{

class broadcast
{
public:

    virtual ~broadcast() = default;

    virtual std::string read() = 0;
    virtual void write(std::string_view message) = 0;
};

} // namespace ftp

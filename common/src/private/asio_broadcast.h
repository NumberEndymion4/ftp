#pragma once

#include <array>
#include <asio/ip/tcp.hpp>
#include <broadcast.h>

namespace ftp
{

class asio_broadcast : public broadcast
{
public:

    explicit asio_broadcast(asio::ip::tcp::socket &&socket);
    ~asio_broadcast() override = default;

    std::string read() override;
    void write(std::string_view message) override;

private:

    asio::ip::tcp::socket socket;
    std::array<char, 128> buffer;
};

} // namespace ftp

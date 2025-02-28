#pragma once

#include <asio/io_context.hpp>
#include <connection.h>
#include <cstdint>

namespace ftp
{

class asio_connection : public connection
{
public:

    explicit asio_connection(uint16_t port);
    asio_connection(const asio_connection &) = delete;
    asio_connection(asio_connection &&) = delete;
    asio_connection &operator=(const asio_connection &) = delete;
    asio_connection &operator=(asio_connection &&) = delete;
    ~asio_connection() override;

    int listen(incoming_connection_shared handler) override;

private:

    asio::io_context context;
    const std::uint16_t port;
};

} // namespace ftp

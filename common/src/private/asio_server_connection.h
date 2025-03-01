#pragma once

#include <cstdint>
#include <server_connection.h>

namespace ftp
{

class asio_sever_connection : public server_connection
{
public:

    explicit asio_sever_connection(uint16_t port);
    asio_sever_connection(const asio_sever_connection &) = delete;
    asio_sever_connection(asio_sever_connection &&) = delete;
    asio_sever_connection &operator=(const asio_sever_connection &) = delete;
    asio_sever_connection &operator=(asio_sever_connection &&) = delete;
    ~asio_sever_connection() override;

    int listen(incoming_connection_shared handler) override;

private:

    const std::uint16_t port;
};

} // namespace ftp

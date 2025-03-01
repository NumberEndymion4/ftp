#pragma once

#include "client_connection.h"
#include "fwd.h"

#include <cstdint>
#include <string_view>

namespace ftp
{

class asio_client_connection : public client_connection
{
public:

    asio_client_connection(std::string_view address, uint16_t port);
    asio_client_connection(const asio_client_connection &) = delete;
    asio_client_connection(asio_client_connection &&) = delete;
    asio_client_connection &operator=(const asio_client_connection &) = delete;
    asio_client_connection &operator=(asio_client_connection &&) = delete;
    ~asio_client_connection() override = default;

    broadcast_unique broadcast() override;

private:

    const std::string_view address;
    const uint16_t port;
};

} // namespace ftp

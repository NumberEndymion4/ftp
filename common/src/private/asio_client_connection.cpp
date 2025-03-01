#include "asio_client_connection.h"

#include "asio_broadcast.h"

#include <asio.hpp>
#include <incoming_connection.h>
#include <memory>
#include <string_view>

namespace ftp
{

using asio::ip::tcp;

asio_client_connection::asio_client_connection(const std::string_view address, const uint16_t port)
    : address(address)
    , port(port)
{
}

broadcast_unique asio_client_connection::broadcast()
{
    asio::io_context io_context;
    const auto endpoints = tcp::resolver(io_context).resolve(tcp::endpoint(tcp::v4(), port));
    tcp::socket socket(io_context);
    asio::connect(socket, endpoints);

    return std::make_unique<asio_broadcast>(std::move(socket));
}

client_connection_unique make_client_connection(std::string_view address, uint16_t port)
{
    return std::make_unique<asio_client_connection>(address, port);
}

} // namespace ftp

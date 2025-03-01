#include "asio_broadcast.h"

#include <asio.hpp>
#include <string>

namespace ftp
{

using asio::ip::tcp;

asio_broadcast::asio_broadcast(tcp::socket &&socket)
    : socket(std::move(socket))
{
}

std::string asio_broadcast::read()
{
    std::string result;

    for (std::error_code error;;)
    {
        const auto length = socket.read_some(asio::buffer(buffer), error);

        if (error == asio::error::eof)
        {
            break;
        }

        if (error)
        {
            throw std::system_error(error);
        }

        result.append(buffer.data(), length);
    }

    return result;
}

void asio_broadcast::write(const std::string_view message)
{
    std::error_code error;
    asio::write(socket, asio::buffer(message), error);
}

} // namespace ftp

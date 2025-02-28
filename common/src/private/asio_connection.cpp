#include "asio_broadcast.h"
#include "asio_connection.h"

#include <asio.hpp>
#include <incoming_connection.h>
#include <iostream>
#include <memory>

namespace ftp
{

using asio::ip::tcp;

asio_connection::asio_connection(const uint16_t port)
    : port(port)
{
}

asio_connection::~asio_connection()
{
}

int asio_connection::listen(const incoming_connection_shared incoming_connection)
{
    try
    {
        tcp::acceptor acceptor(context, tcp::endpoint(tcp::v4(), port));

        while (true)
        {
            tcp::socket socket(context);
            acceptor.accept(socket);

            incoming_connection->connect(std::make_unique<asio_broadcast>());
        }
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 1;
}

connection_unique make_connection()
{
    return std::make_unique<asio_connection>(10000);
}

} // namespace ftp

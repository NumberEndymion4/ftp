#include "asio_server_connection.h"

#include "asio_broadcast.h"

#include <asio.hpp>
#include <incoming_connection.h>
#include <iostream>
#include <memory>

namespace ftp
{

using asio::ip::tcp;

asio_sever_connection::asio_sever_connection(const uint16_t port)
    : port(port)
{
}

asio_sever_connection::~asio_sever_connection()
{
}

int asio_sever_connection::listen(const incoming_connection_shared incoming_connection)
{
    try
    {
        asio::io_context context;
        tcp::acceptor acceptor(context, tcp::endpoint(tcp::v4(), port));

        for (;;)
        {
            tcp::socket socket(context);
            acceptor.accept(socket);

            incoming_connection->connect(std::make_unique<asio_broadcast>(std::move(socket)));
        }
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 1;
}

server_connection_unique make_server_connection(const uint16_t port)
{
    return std::make_unique<asio_sever_connection>(port);
}

} // namespace ftp

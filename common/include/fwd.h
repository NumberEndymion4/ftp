#pragma once

#include <memory>

namespace ftp
{

class broadcast;
using broadcast_unique = std::unique_ptr<broadcast>;

class client_connection;
using client_connection_unique = std::unique_ptr<client_connection>;

class server_connection;
using server_connection_unique = std::unique_ptr<server_connection>;

class incoming_connection;
using incoming_connection_shared = std::shared_ptr<incoming_connection>;

} // namespace ftp

#pragma once

#include <memory>

namespace ftp
{

class broadcast;
using broadcast_unique = std::unique_ptr<broadcast>;

class connection;
using connection_unique = std::unique_ptr<connection>;

class incoming_connection;
using incoming_connection_shared = std::shared_ptr<incoming_connection>;

} // namespace ftp

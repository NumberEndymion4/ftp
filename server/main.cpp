#include <broadcast.h>
#include <incoming_connection.h>
#include <server_connection.h>
#include <vector>

namespace
{

std::vector<ftp::broadcast_unique> broadcasts;

class incoming : public ftp::incoming_connection
{
    void connect(ftp::broadcast_unique broadcast) override
    {
        broadcasts.push_back(std::move(broadcast));
    }
};

} // namespace

int main(const int argc, const char **argv)
{
    const auto connection = ftp::make_server_connection(10000);
    return connection->listen(std::make_shared<incoming>());
}

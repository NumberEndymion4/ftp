#include <broadcast.h>
#include <client_connection.h>

int main(const int argc, const char **argv)
{
    const auto connection = ftp::make_client_connection("", 10000);
    auto broadcast = connection->broadcast();
    broadcast->write("Message");

    return 0;
}

#include "client.h"

#include <boost/asio.hpp>

int main()
{
    std::setlocale(LC_ALL, "Russian");

    boost::asio::io_service io_service;
    Client client(io_service, "127.0.0.1", 9000);
    client.send_data("Hello from client!");

    return 0;
}

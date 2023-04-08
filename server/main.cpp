#include <iostream>
#include <boost/asio.hpp>
#include "server.h"

using boost::asio::ip::tcp;

int main() {
    try {
        boost::asio::io_service io_service;
        Server server(io_service, 9000); // запускаем сервер на порту 1234
        io_service.run(); // запускаем цикл обработки событий
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}

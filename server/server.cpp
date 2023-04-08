#include "server.h"

Server::Server(boost::asio::io_service& io_service, short port)
        : acceptor_(io_service, tcp::endpoint(tcp::v4(), port)),
          socket_(io_service) {
    start_accept();
}

void Server::start_accept() {
    acceptor_.async_accept(socket_, boost::bind(&Server::handle_accept, this,
                                                boost::asio::placeholders::error));
}

void Server::handle_accept(const boost::system::error_code& error) {
    if (!error) {
        std::cout << "Client connected." << std::endl;
        socket_.async_read_some(boost::asio::buffer(data_, max_length),
                                boost::bind(&Server::handle_read, this,
                                            boost::asio::placeholders::error,
                                            boost::asio::placeholders::bytes_transferred));
    }
}

void Server::handle_read(const boost::system::error_code& error, size_t bytes_transferred) {
    if (!error) {
        std::cout << "Received: " << data_ << std::endl;
        socket_.async_read_some(boost::asio::buffer(data_, max_length),
                                boost::bind(&Server::handle_read, this,
                                            boost::asio::placeholders::error,
                                            boost::asio::placeholders::bytes_transferred));
    }
}
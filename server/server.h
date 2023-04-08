#ifndef SERVER_H
#define SERVER_H

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <iostream>

using boost::asio::ip::tcp;

class Server {
public:
    Server(boost::asio::io_service& io_service, short port);
private:
    void start_accept();
    void handle_accept(const boost::system::error_code& error);
    void handle_read(const boost::system::error_code& error, size_t bytes_transferred);

    tcp::acceptor acceptor_;
    tcp::socket socket_;
    enum { max_length = 1024 };
    char data_[max_length];
};

#endif // SERVER_H
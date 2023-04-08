#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

class Client {
public:
    Client(boost::asio::io_service& io_service, std::string host, int port);
    void send_data(const std::string& message);

private:
    void handle_connect(const boost::system::error_code& error);
    void handle_write(const boost::system::error_code& error);
    void handle_read(const boost::system::error_code& error);

    boost::asio::io_service& io_service_;
    boost::asio::ip::tcp::socket socket_;
    std::string message_;
};
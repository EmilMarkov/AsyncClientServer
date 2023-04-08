#include "client.h"

Client::Client(boost::asio::io_service& io_service, std::string host, int port) : io_service_(io_service), socket_(io_service)
{
    this->socket_.connect(boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(host), port));
}

void Client::handle_connect(const boost::system::error_code& error)
{
    if (!error) {
        std::cout << "Connected to server." << std::endl;
        std::cout << "Enter message: ";
        std::getline(std::cin, message_);

        boost::asio::async_write(socket_, boost::asio::buffer(message_), boost::bind(&Client::handle_write, this, boost::asio::placeholders::error));
    }
}

void Client::handle_write(const boost::system::error_code &error)
{
    if (!error) {
        std::cout <<"Message sent." <<std::endl;

        boost::asio::async_read(socket_,
                   boost::asio::buffer(message_,1024),
                   boost::bind(&Client::handle_read, this, boost::asio::placeholders::error));
    }
}

void Client::handle_read(const boost::system::error_code &error)
{
    if (!error) {
        std::cout << "Received message: " << message_ << std::endl;
    }
}

void Client::send_data(const std::string& message) {
    boost::system::error_code error;
    boost::asio::write(this->socket_, boost::asio::buffer(message), error);
    if( !error ) {
        std::cout << "Client sent hello message!" << std::endl;
    }
    else {
        std::cout << "send failed: " << error.message() << std::endl;
    }
}


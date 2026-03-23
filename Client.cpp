#include "Client.h"
#include <iostream>

Client::Client()
{
	
	std::cout<<"Enter Name: ";
	std::cin>>name;

	serverSocket = {socket(AF_INET, SOCK_STREAM, 0)};

	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(8080);
	serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");

	connect(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));

}
Client::~Client()
{

	close(serverSocket);

}


void Client::Communicate()
{

	std::thread readThread(&Client::RecvMessage, this);
	std::thread sendThread(&Client::SendMessage, this);

	readThread.join();
	sendThread.join();

}


void Client::SendMessage()
{


	write(serverSocket, name.data(), 1);
/*
	while(true)
	{
		Message message{};
		
		message.Make();



		message.Send(serverSocket);

		if(message.End() == true)
		{
			break;
		}

	}
*/
}

void Client::RecvMessage()
{

	char c;

	read(serverSocket, &c, 1);
/*
	while(true)
	{
		Message message{};

		message.Read(serverSocket);

		message.display();
		
	}
*/
	std::cout<<"Received: "<<c<<std::endl;

}



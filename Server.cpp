#include "Server.h"
#include <iostream>

Server::Server()
{
	serverSocket = {socket(AF_INET, SOCK_STREAM, 0)};

	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(8080);
	serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");

	idMap.clear();

	bind(serverSocket, (sockaddr *)&serverAddress, sizeof(serverAddress));

	listen(serverSocket, numberofClients);

}

Server::~Server()
{
	close(serverSocket);
}

void Server::HandleConnection()
{

	while(true)
	{
		std::cout<<"Type Shi\n";
		int clientID {accept(serverSocket, nullptr, nullptr)};
		std::thread(&Server::ConnectClient, this, clientID).detach();
	}
}


void Server::ConnectClient(int clientID)
{
	
	char buffer[1024];
	
	std::cout<<"Working till here for clientID: "<<clientID<<std::endl;

	int bytes = read(clientID, buffer, 1023 * sizeof(char));

	if(bytes < 1) return;

	buffer[bytes] = 0;

	std::string name {buffer};

	{
		std::lock_guard<std::mutex> lock(insertingMap);
		idMap.insert({clientID, name});
	}

	HandleCommunication(clientID);

}

void Server::HandleCommunication(int clientID)
{
	std::cout<<"Working till here for clientID: "<<clientID<<std::endl;

	/*

	Message msg{};

	while(true)
	{

		msg.clear();

		msg.ReadMsg(clientID);

		if(msg.End() == true)
		{
			close(clientID);
			break;
		}

		msg.Send();

	}

	*/

}


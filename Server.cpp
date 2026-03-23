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
		int clientID {accept(serverSocket, nullptr, nullptr)};
		clientIDs.insert(clientID);
		std::thread(&Server::ConnectClient, this, clientID).detach();
	}
}


void Server::ConnectClient(int clientID)
{

/*	
	char buffer[1024];
	

	int bytes = read(clientID, buffer, 1023 * sizeof(char));

	if(bytes < 1) return;

	buffer[bytes] = 0;

	std::string name {buffer};

	{
		std::lock_guard<std::mutex> lock(insertingMap);
		idMap.insert({clientID, name});
	}
*/
	HandleCommunication(clientID);

}

void Server::HandleCommunication(int clientID)
{
	std::cout<<"Working till here for clientID: "<<clientID<<std::endl;

	char c;

	read(clientID, &c, 1);

	std::cout<<"Received: "<<c<<" from: "<<clientID<<std::endl;

	/*

	Message msg{};

	while(true)
	{

		msg.clear();

		msg.Read(clientID);

		if(msg.End() == true)
		{
			clientIds.erase(clientID);
			close(clientID);
			break;
		}

		msg.Send();

	}

	*/

}


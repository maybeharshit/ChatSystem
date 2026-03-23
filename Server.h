#include <netinet/in.h>
#include <sys/socket.h>
#include <unordered_map>
#include <string>
#include <thread>
#include <unistd.h>
#include <arpa/inet.h>
#include <mutex>
#include <set>
class Server
{

	int numberofClients = 5;
	int serverSocket;
	std::set<int> clientIDs;
	sockaddr_in serverAddress;
	std::unordered_map<int, std::string> idMap;
	std::mutex insertingMap;
	public:
		Server();
		~Server();
		void HandleConnection();
		void ConnectClient(int);
		void HandleCommunication(int);
};

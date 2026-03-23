#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <thread>
#include <mutex>
#include <string>
#include <arpa/inet.h>
class Client
{

	std::string name;
	int serverSocket;
	sockaddr_in serverAddress;
	public:
		Client();
		~Client();	
		void Communicate();
		void SendMessage();
		void RecvMessage();
};


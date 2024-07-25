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

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&address, sizeofaddr);
	listen(sListen, SOMAXCONN);
	SOCKET newConnection = accept(sListen, (SOCKADDR*)&address, &sizeofaddr);
	if (newConnection == 0)
	{
		std::cout << "Error\n";
	}
	else
	{
		std::cout << "CLient connected\n";
		char stringToSend[256];
		char response[10000];
		while (true)
		{
			std::cin >> stringToSend;
			if (strcmp(stringToSend, "exit\n") == 1) { //Если клиент отсоединился
				
				break;
			}
			send(newConnection, stringToSend, sizeof(stringToSend), NULL);
			recv(newConnection, response, sizeof(response), NULL);
			std::cout << response;
		}

	}
	return 0;
}
#include "Server_Socket.h"

Server_Socket::Server_Socket()
{
}

Server_Socket::~Server_Socket()
{
	closesocket(servSock);
	WSACleanup();
}

bool Server_Socket::InitSocket()
{
	WSADATA wsaData;
	SOCKADDR_IN servAddr;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		return false;

	servSock = socket(AF_INET, SOCK_STREAM, 0);
	if (servSock == INVALID_SOCKET)
		return false;

	ZeroMemory(&servAddr, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAddr.sin_port = htons(TEST_PORT);

	if (connect(servSock, (SOCKADDR*)&servAddr, sizeof(servAddr)) < 0)
		return false;

	return true;
}

SOCKET& Server_Socket::GetSocket()
{
	return servSock;
}
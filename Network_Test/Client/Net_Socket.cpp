#include "Net_Socket.h"

Net_Socket::Net_Socket()
{

}

Net_Socket::~Net_Socket()
{
	closesocket(cntSock);
	WSACleanup();
}

bool Net_Socket::InitSocket()
{
	WSADATA wsaData;
	SOCKADDR_IN servAddr;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		return false;

	cntSock = socket(AF_INET, SOCK_STREAM, 0);
	if (cntSock == INVALID_SOCKET)
		return false;

	ZeroMemory(&servAddr, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr(TEST_IP);
	servAddr.sin_port = htons(TEST_PORT);

	if (connect(cntSock, (SOCKADDR*)&servAddr, sizeof(servAddr)) < 0)
		return false;

	return true;
}

SOCKET& Net_Socket::GetSocket()
{
	return cntSock;
}

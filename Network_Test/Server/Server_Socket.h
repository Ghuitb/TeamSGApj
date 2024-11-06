#pragma once

#include "Network.h"

#define TEST_PORT 9190

class Server_Socket
{
public:
	Server_Socket();
	~Server_Socket();

	bool InitSocket();

	SOCKET& GetSocket();

private:
	SOCKET servSock = INVALID_SOCKET;
};


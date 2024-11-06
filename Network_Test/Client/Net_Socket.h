#pragma once

#include "Network.h"

#define TEST_IP "172.30.1.70"
#define TEST_PORT 9190

/*
서버에 연결을 생성하는 것까지가 Net_Socket에서 담당한다

- 소켓 생성 후 connect까지
*/
class Net_Socket
{
public:
	Net_Socket();
	~Net_Socket();

	bool InitSocket();

	SOCKET& GetSocket();
	
private:
	SOCKET cntSock = INVALID_SOCKET;
};


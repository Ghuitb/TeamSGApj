#pragma once

#include "Network.h"

#define TEST_IP "172.30.1.70"
#define TEST_PORT 9190

/*
������ ������ �����ϴ� �ͱ����� Net_Socket���� ����Ѵ�

- ���� ���� �� connect����
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


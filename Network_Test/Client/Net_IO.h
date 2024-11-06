#pragma once

#include "Network.h"
#include "Net_Data.h"

#include <thread>

/*
연결된 소켓을 받아와서
데이터 송수신 코드를 실행 시킨다.

- 클라이언트이기 때문에
송신을 주로 잡고
수신은 별도의 thread를 생성해서 받는다.

지금은 데이터 구조가 결합되어있지만
데이터 구조를 Net_Data으로 분리하고
Net_Data에 종
*/
class Net_IO
{
public:
	Net_IO(SOCKET& socket, Net_Data& data)
		: IOSock(socket), IOData(data) {}
	~Net_IO() {}

	void recvOtherData();
	void recvThread();
	void sendData();

private:
	SOCKET& IOSock;
	Net_Data& IOData;
};
#pragma once

#include "Network.h"
#include "DataStruct.h"

#include <thread>
#include <vector>

struct CLIENT
{
	SOCKET cntSock_;
	DataStruct cntData_;
};

class Server_IO
{
public:
	Server_IO(SOCKET& socket)
	: IOSock(socket) {}
	~Server_IO()
	{
		closesocket(IOSock);
		WSACleanup();
	}

	bool InitIO();		// listen 시작

	void recvThread(int index);	// 연결을 accept하고 vector에 저장

	int ClientConnect();
	void recvDataFromClient(int& index);
	void sendDataToClient();

	void AddServerLog();

private:
	SOCKET& IOSock;
	DataStruct IOData;
	std::vector<CLIENT> ConnectedClients;
};
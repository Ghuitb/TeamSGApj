#include "Server_IO.h"

bool Server_IO::InitIO()
{
	return listen(IOSock, 5) != SOCKET_ERROR ? true : false;
}

void Server_IO::recvThread(int index)
{
	std::thread(recvDataFromClient, index, std::ref(ConnectedClients)).detach();
}

int Server_IO::ClientConnect()
{
	CLIENT cnt;
	PSOCKADDR_IN cntAddr;
	int szCntAddr = sizeof(cntAddr);

	while (true)
	{
		cnt.cntSock_ = accept(IOSock, (SOCKADDR*)&cntAddr, &szCntAddr);

		if (cnt.cntSock_ == INVALID_SOCKET)
			continue;

		ConnectedClients.push_back(cnt);
	}

	return ConnectedClients.size() - 1;
}

void Server_IO::recvDataFromClient(int& index)
{
	constexpr size_t bufferSize = sizeof(DataStruct);
	char buffer[bufferSize];
	int recvSize;

	recvSize = recv(ConnectedClients[index].cntSock_, buffer, bufferSize, 0);
	if (recvSize <= 0)
		return;

	for (auto& client : ConnectedClients)
	{
		int sendData = send(client.cntSock_, buffer, bufferSize, 0);
		if (sendData == SOCKET_ERROR)
			return;
	}
}

void Server_IO::sendDataToClient()
{

}

void Server_IO::AddServerLog()
{

}

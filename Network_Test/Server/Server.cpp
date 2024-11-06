#include <winsock2.h>
#include <iostream>
#include <thread>
#include <string>
#include <vector>

#include "Net_Data.h"

#pragma comment(lib, "ws2_32.lib")

struct CLIENT
{
	SOCKET m_ClientSock;
	Net_Data data;
};

void ErrorHandling(const char* message);
void handleClient(int clientIndex, std::vector<CLIENT>& clients);
void sendDataToAll(std::vector<CLIENT>& clients, Net_Data& data);

#define TEST_PORT 9190

int main(int argc, char* argv[])
{
	WSADATA wsaData;
	SOCKET hServSock;
	std::vector<CLIENT> Clients;
	SOCKADDR_IN servAddr, clntAddr;

	int szClntAddr = sizeof(clntAddr);
	char message[] = "Hello World!";

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		ErrorHandling("WSAStartup() error!");

	hServSock = socket(PF_INET, SOCK_STREAM, 0);
	if (hServSock == INVALID_SOCKET)
		ErrorHandling("socket() error");

	ZeroMemory(&servAddr, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAddr.sin_port = htons(TEST_PORT);

	if (bind(hServSock, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
		ErrorHandling("bind() error");

	if (listen(hServSock, 5) == SOCKET_ERROR)
		ErrorHandling("listen() error");

	std::cout << "Server start!\n";

	while (1)
	{
		CLIENT ClientTemp;
		ClientTemp.m_ClientSock = accept(hServSock, (SOCKADDR*)&clntAddr, &szClntAddr);
		if (ClientTemp.m_ClientSock == INVALID_SOCKET)
		{
			ErrorHandling("accept() error");
			continue;
		}

		Clients.push_back(ClientTemp);

		int clientIndex = Clients.size() - 1;
		std::thread(handleClient, clientIndex, std::ref(Clients)).detach();
	}

	for (auto& data : Clients)
	{
		closesocket(data.m_ClientSock);
	}

	closesocket(hServSock);
	WSACleanup();

	return 0;
}

void ErrorHandling(const char* message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

void handleClient(int clientIndex, std::vector<CLIENT>& clients)
{
	constexpr size_t bufferSize = sizeof(Net_Data);
	char buffer[bufferSize];
	int recvSize;

	while (true) {
		// Ŭ���̾�Ʈ�κ��� ������ ����
		recvSize = recv(clients[clientIndex].m_ClientSock, buffer, bufferSize, 0);
		if (recvSize <= 0) {
			std::cout << "Client " << clients[clientIndex].m_ClientSock << " ���� ������ �����߽��ϴ�.\n";
			break;
		}

		// ������ ������ ������ȭ
		clients[clientIndex].data.deserialize(buffer);

		// ���� �ֿܼ� ���ŵ� ������ ���
		std::cout << "Received data from client " << clients[clientIndex].m_ClientSock << ": "
			<< "int: " << clients[clientIndex].data.A << ", float: " << clients[clientIndex].data.B << std::endl;

		// ������ ���� �Ϸ� �޽��� ���
		std::cout << "Data sent to server from client " << clients[clientIndex].m_ClientSock << std::endl;

		// ��� Ŭ���̾�Ʈ���� ������ ����
		sendDataToAll(clients, clients[clientIndex].data);
	}

	closesocket(clients[clientIndex].m_ClientSock);
}

void sendDataToAll(std::vector<CLIENT>& clients, Net_Data& data)
{
	// ����ȭ�� ������ ����
	constexpr size_t bufferSize = sizeof(Net_Data);
	char buffer[bufferSize];

	// �����͸� ����ȭ�Ͽ� ���ۿ� ����
	data.serialize(buffer);

	// ��� Ŭ���̾�Ʈ���� ������ ����
	for (auto& client : clients)
	{
		int sentBytes = send(client.m_ClientSock, buffer, bufferSize, 0);
		if (sentBytes == SOCKET_ERROR) {
			std::cerr << "Error sending data to client" << std::endl;
		}
	}
}

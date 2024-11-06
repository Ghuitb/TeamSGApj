#include "Server_Socket.h"
#include "Server_IO.h"
#include "Server_DataCtrl.h"
#include "DataStruct.h"

#pragma comment(lib, "ws2_32.lib")

int main()
{
	// DataStruct ������ ������ ���� ��ü�� main���� ������ ���� �޸𸮷� ����� ���� ������ ����ΰ�?
	// �Լ��� �Ű������� �־����� �ʾƵ� �Ǿ ���� �ѵ� �´� ��������� �𸣰ڳ�

	Server_Socket sock;
	if (!sock.InitSocket())
		return 1;

	//Server_DataCtrl controller;

	Server_IO IO(sock.GetSocket());

	IO.InitIO();

	while (true)
	{
		IO.recvThread(IO.ClientConnect());
	}

	return 0;
}
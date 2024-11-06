#pragma once

#include "Network.h"
#include "Net_Data.h"

#include <thread>
#include <string>

/*
����� ������ �޾ƿͼ�
������ �ۼ��� �ڵ带 ���� ��Ų��.

- Ŭ���̾�Ʈ�̱� ������
�۽��� �ַ� ���
������ ������ thread�� �����ؼ� �޴´�.

������ ������ ������ ���յǾ�������
������ ������ Net_Data���� �и��ϰ�
Net_Data�� ��
*/
class Net_IO
{
public:
	Net_IO(SOCKET& socket, Net_Data& data)
		: IOsock(socket), IOData(data) {}
	~Net_IO() {}

	void recvOtherData();
	void recvThread();
	void sendData();

private:
	SOCKET& IOsock;
	Net_Data& IOData;
};
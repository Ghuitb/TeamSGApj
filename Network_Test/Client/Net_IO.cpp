#include "Net_IO.h"

#include <iostream>
#include <string>
#include <array>

void Net_IO::recvOtherData()
{
	constexpr const int bufferSize = sizeof(IOData);
	char buffer[bufferSize];

	while (true)
	{
		int recvSize = recv(IOsock, buffer, bufferSize, 0);

		if (recvSize <= 0)
			break;

		IOData.deserialize(buffer);		// ���ۿ� �ִ� �����͸� IOData ��ü�� ����
		IOData.print();					// IOData�� ����� �����͸� print�� ���
	}
}

void Net_IO::recvThread()
{
	std::thread([this]() { recvOtherData(); }).detach();
	// std::thread(std::bind(&Net_IO::recvOtherData, this)).detach(); // functional
}

void Net_IO::sendData()
{
	constexpr size_t bufferSize = sizeof(IOData);
	char buffer[bufferSize];
	IOData.serialize(buffer);  // Net_Data ����ȭ

	// Net_IO�� ���� ����ȭ�� ������ ����
	send(IOsock, buffer, bufferSize, 0);
}


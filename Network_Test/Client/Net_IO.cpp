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

		IOData.deserialize(buffer);		// 버퍼에 있는 데이터를 IOData 객체에 복사
		IOData.print();					// IOData에 복사된 데이터를 print로 출력
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
	IOData.serialize(buffer);  // Net_Data 직렬화

	// Net_IO를 통해 직렬화된 데이터 전송
	send(IOsock, buffer, bufferSize, 0);
}


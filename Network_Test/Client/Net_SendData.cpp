#include "Net_SendData.h"

void Net_SendData::getUserInput()
{
	int i;
	float f;

	std::cout << "������ ������ �Է� ���ּ��� : ";
	std::cin >> i >> f;

	data_.A = i;
	data_.B = f;
}
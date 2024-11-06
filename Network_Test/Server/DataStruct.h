#pragma once

#include <iostream>

class DataStruct
{
public:
	int A;
	int B;

	DataStruct()
		: A(0), B(0) {}

    // ����ȭ (Net_Data ��ü�� ����Ʈ �迭�� ��ȯ)
    void serialize(char* buffer) const {
        std::memcpy(buffer, this, sizeof(DataStruct));  // ��ü�� �޸𸮷� ����
    }

    // ������ȭ (���ۿ��� Net_Data ��ü�� ��ȯ)
    void deserialize(const char* buffer) {
        std::memcpy(this, buffer, sizeof(DataStruct));  // �޸𸮿��� ��ü�� ����
    }

    // ������ ���
    void print() const {
        std::cout << "A: " << A << ", B: " << B << std::endl;
    }
};
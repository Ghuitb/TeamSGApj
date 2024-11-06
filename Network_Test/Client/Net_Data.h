#pragma once

#include <iostream>
#include <array>
#include <algorithm>
#include <string>


class Net_Data
{
public:
	int A;
	int B;

    Net_Data()
        : A(0), B(0) {}

    // ����ȭ (Net_Data ��ü�� ����Ʈ �迭�� ��ȯ)
    void serialize(char* buffer) const {
        std::memcpy(buffer, this, sizeof(Net_Data));  // ��ü�� �޸𸮷� ����
    }

    // ������ȭ (���ۿ��� Net_Data ��ü�� ��ȯ)
    void deserialize(const char* buffer) {
        std::memcpy(this, buffer, sizeof(Net_Data));  // �޸𸮿��� ��ü�� ����
    }

    // ������ ���
    void print() const {
        std::cout << "data1: " << A << ", data2: " << B << std::endl;
    }
private:
};
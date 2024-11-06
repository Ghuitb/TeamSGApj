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

    Net_Data(int i = 0, float f = 0.0f) : A(i), B(f) {}

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
        std::cout << "A: " << A << ", B: " << B << std::endl;
    }
private:
};
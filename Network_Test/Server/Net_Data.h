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

    // 직렬화 (Net_Data 객체를 바이트 배열로 변환)
    void serialize(char* buffer) const {
        std::memcpy(buffer, this, sizeof(Net_Data));  // 객체를 메모리로 복사
    }

    // 역직렬화 (버퍼에서 Net_Data 객체로 변환)
    void deserialize(const char* buffer) {
        std::memcpy(this, buffer, sizeof(Net_Data));  // 메모리에서 객체를 복사
    }

    // 데이터 출력
    void print() const {
        std::cout << "A: " << A << ", B: " << B << std::endl;
    }
private:
};
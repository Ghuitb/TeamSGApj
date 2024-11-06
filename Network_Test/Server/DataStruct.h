#pragma once

#include <iostream>

class DataStruct
{
public:
	int A;
	int B;

	DataStruct()
		: A(0), B(0) {}

    // 직렬화 (Net_Data 객체를 바이트 배열로 변환)
    void serialize(char* buffer) const {
        std::memcpy(buffer, this, sizeof(DataStruct));  // 객체를 메모리로 복사
    }

    // 역직렬화 (버퍼에서 Net_Data 객체로 변환)
    void deserialize(const char* buffer) {
        std::memcpy(this, buffer, sizeof(DataStruct));  // 메모리에서 객체를 복사
    }

    // 데이터 출력
    void print() const {
        std::cout << "A: " << A << ", B: " << B << std::endl;
    }
};
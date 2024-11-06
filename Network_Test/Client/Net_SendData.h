#pragma once

#include <iostream>
#include "Net_Data.h"

class Net_SendData
{
public:
	Net_SendData(Net_Data& data)
		: data_(data) {}
	~Net_SendData() {}

	void getUserInput();

private:
	Net_Data& data_;
};


#pragma once

#include <iostream>
#include "Net_Data.h"

class Net_SendData
{
public:
	Net_SendData() {}
	~Net_SendData() {}

	void getUserInput();

	Net_Data& GetData();

private:
	Net_Data data_;
};


#include <iostream>
#include "NumberDispatcher.h"

void NodeSys::NumberDispatcher::Handle(int data, const string& sender, const string& receiver)
{
	num++;
	cout << sender << " -> " << receiver << ": N = " << num << endl;
}

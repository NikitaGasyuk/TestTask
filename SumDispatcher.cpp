#include <iostream>
#include "SumDispatcher.h"

void NodeSys::SumDispatcher::Handle(int data, const string &sender, const string &receiver)
{
	sum += data;
	cout << sender << " -> " << receiver << ": S = " << sum << endl;
}

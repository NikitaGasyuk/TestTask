#pragma once

#ifndef NODESYS_SUMDISPATCHER_H
#define NODESYS_SUMDISPATCHER_H

#include <iostream>
#include "EventDispatcher.h"

using namespace std;

namespace NodeSys
{
	class SumDispatcher : public EventDispatcher
	{

		int sum = 0;

	public:

		virtual void Handle(int data, const string &sender, const string &receiver) override;

	};
};

#endif 
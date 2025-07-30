#ifndef NODESYS_NUMBERDISPATCHER_H
#define NODESYS_NUMBERDISPATCHER_H

#include "EventDispatcher.h"

using namespace std;

namespace NodeSys
{
	class NumberDispatcher : public EventDispatcher
	{
		int num = 0;

	public:

		virtual void Handle(int data, const string& sender, const string& receiver) override;

	};
}

#endif 

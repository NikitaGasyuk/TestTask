#ifndef NODESYS_EVENTDISPATCHER
#define NODESYS_EVENTDISPATCHER

#include <string>

using namespace std;

namespace NodeSys
{
	class EventDispatcher
	{

	public:

		virtual void Handle(int data, const string& sender, const string& receiver) = 0;
		virtual ~EventDispatcher() = default;

	};
}

#endif

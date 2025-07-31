//����� �������������, ������� ������������� ������������ ��������� ������������� �����,
// ������� ��� ������� �����.
#ifndef NODESYS_EVENTDISPATCHER
#define NODESYS_EVENTDISPATCHER
// ����������� ���������� string
#include <string>

using namespace std;

namespace NodeSys
{
	// ���������� ������ EventDispatcher
	class EventDispatcher
	{

	public:
		// ����������� ������� ������� ��������� ��������� ���������
		// ������ �������(data), ��� ���� �����������(sender), ��� ���� ����������(receiver)
		virtual void Handle(int data, const string& sender, const string& receiver) = 0;
		// ����������� ����������
		virtual ~EventDispatcher() = default;

	};
}

#endif
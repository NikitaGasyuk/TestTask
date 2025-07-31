//����� �������������, ������� ������������� ������������ ��������� ������������� �����,
// ������� ��� ������� �����.
#ifndef NODESYS_NUMBERDISPATCHER_H
#define NODESYS_NUMBERDISPATCHER_H

//����������� ���������� iostream
#include <iostream>
//����������� ������������� ����� EventDispatcher
#include "EventDispatcher.h"

using namespace std;

namespace NodeSys
{
	// ���������� ������ NumberDispatcher �������������� �� EventDispatcher
	class NumberDispatcher : public EventDispatcher
	{
		// ������������� ������������� ���������� ���������� �����
		int num = 0;

	public:
		// ����������� ������� ��������� ������� ������� ��������� ��������� ���������
		// ������ �������(data), ��� ���� �����������(sender), ��� ���� ����������(receiver)
		virtual void Handle(int data, const string& sender, const string& receiver) override;

	};
}

#endif 

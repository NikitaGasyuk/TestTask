// ����������� ������������� �����
#include "NumberDispatcher.h"
//����������� ������� ��������� �������
void NodeSys::NumberDispatcher::Handle(int data, const string& sender, const string& receiver)
{
	//���������� ���������� �� 1 
	num++;
	//����� � ������� ��� ���� �����������, ���� ���������� � �������� ���������� ����� ����
	cout << sender << " -> " << receiver << ": N = " << num << endl;
}

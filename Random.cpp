//������������ ������������ ����
#include "Random.h"
//������� ���������� ��������� ����
void NodeSys::Random::update()
{
	//�������� ������� ����������
	if (hasNoSubsribe())
	{
		// �������
		return;
	}
	// ������������� ������������ ���������� ������� ��������� �������� ���������������� �������
	int eventData = generateEvent();
	//����� ������� �����������  � �������� ���������������� ������� �����������
	notify(eventData);
	// �������� ������������� 0-5
	uniform_int_distribution<> chance(0, 4);
	//�������� �� ��������� ����
	if (chance(gen) == 0)
	{
		// ����� ������� 
		createAndSubscribeNewNode();
	}
}
// ������� �������� ������� 
int NodeSys::Random::generateEvent()
{
	// ����������� ���������� ����� �� 0-100
	return dis(gen);
}
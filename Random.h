//����� �������������, ������� ������������� ������������ ��������� ������������� �����,
// ������� ��� ������� �����.
#ifndef NODESYS_RANDOM_H
#define NODESYS_RANDOM_H
//����������� ���������� ������
#include <random>
//����������� ������������� ����� Node
#include "Node.h"

using namespace std;

namespace NodeSys
{
	//���������� ������ Random � �������������� �� ������ Node
	class Random : public Node
	{
		// ���������� ��� ��������� ��������� �����
		random_device rd;
		// ��������� ��������� �����
		mt19937 gen;
		//���������� ��� ������������ ������������� ����� �����
		uniform_int_distribution<> dis;

	public:
		// �����������, ������� �������� ��� ���� � ����� ����� �����,
		// ���������� ����������� �������� ������
		// ���������������� ��������� ��������� �����
		// ���������������� ���������� ������������� ����� ����� �� 1-100
		Random(const string &name, vector<shared_ptr<Node>> &buffer) : Node(name, buffer), gen(rd()), dis(1, 100) {}
		// ����������� ������� �������� �������
		virtual int generateEvent() override;
		// ����������� ������� ���������� ��������� ����
		virtual void update() override;

	};
};

#endif 
#ifndef NODESYS_RANDOM_H
#define NODESYS_RANDOM_H

#include <random>
#include "Node.h"

using namespace std;

namespace NodeSys
{
	class Random : public Node
	{
		random_device rd;
		
		mt19937 gen;
		
		uniform_int_distribution<> dis;

	public:

		Random(const string &name, vector<shared_ptr<Node>> &buffer) : Node(name, buffer), gen(rd()), dis(1, 100) {}

		virtual int generateEvent() override;

		virtual void update() override;

	};
};

#endif 
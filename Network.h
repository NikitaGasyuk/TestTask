#ifndef NODESYS_NETWORK_H
#define NODESYS_NETWORK_H

#include <vector>
#include <memory>
#include <random>
#include "Node.h"

using namespace std;

namespace NodeSys
{
	class Network
	{	
	public:
		
		vector<shared_ptr<Node>> nodes;
		
		vector<shared_ptr<Node>> newNodesBuffer;
		
		random_device rd;
		
		mt19937 gen;
		
		static int uniqueNodeCounter;

		Network() : gen(rd()) {}

		void addNode(const shared_ptr<Node> &node);

		void UpdateNetwork();

		void generateRandomSubscriptions();

		void generateRandomNetwork(int numNodes);

		bool isNetworkAlive() const { return !nodes.empty(); }

		static string generateUniqueNodeName() { return "Node" + to_string(uniqueNodeCounter++); }
		
	};
}

#endif
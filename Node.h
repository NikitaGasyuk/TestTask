#pragma once

#ifndef NODESYS_NODE_H
#define NODESYS_NODE_H

#include <iostream>
#include <utility>
#include <unordered_map>
#include "EventDispatcher.h"

using namespace std;

namespace NodeSys
{
	class Node
	{
	protected:
		
		string name;
		
		unordered_map<Node *, shared_ptr<EventDispatcher>> subscribers;
		
		vector<shared_ptr<Node>> &newNodesBuffer;
	
	public:

		Node(string NodeName, vector<shared_ptr<Node>> &buffer) : name(move(NodeName)), newNodesBuffer(buffer) {}

		virtual void update() = 0;

		virtual int generateEvent() = 0;

		void subscribe(Node* neighbor, shared_ptr<EventDispatcher> handler);

		void unsubscribe(Node* neighbor);

		void notify(int data);

		const string& getName() const { return name; }

		bool hasNoSubsribe() const { return subscribers.empty(); }
	};
};

#endif
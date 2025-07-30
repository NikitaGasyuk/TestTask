#include <iostream>
#include <utility>
#include "Node.h"
#include "SumDispatcher.h"
#include "Random.h"
#include "Network.h"

void NodeSys::Node::subscribe(Node * neighbor, shared_ptr<EventDispatcher> handler)
{
	if (neighbor != this && !subscribers.count(neighbor))
	{
		subscribers[neighbor] = move(handler);
	}
}

void NodeSys::Node::unsubscribe(Node * neighbor)
{
	auto it = subscribers.find(neighbor);
	if (it != subscribers.end())
	{
		subscribers.erase(it);
	}
}

void NodeSys::Node::notify(int data)
{
	for (auto& subscriber : subscribers)
	{
		Node* neighbor = subscriber.first;
		shared_ptr<EventDispatcher> dispathcer = subscriber.second;
		dispathcer->Handle(data, name, neighbor->getName());
	}
}

void NodeSys::Node::createAndSubscribeNewNode()
{
	string newNodeName = Network::generateUniqueNodeName();
	auto newNode = make_shared<Random>(newNodeName, newNodesBuffer);

	newNodesBuffer.push_back(newNode);

	this->subscribe(newNode.get(), make_shared<SumDispatcher>());
	cout << name << " created new node and subscribe: " << newNodeName << endl;

}

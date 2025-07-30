#include "Node.h"

void NodeSys::Node::subscribe(Node* neighbor, shared_ptr<EventDispatcher> handler)
{
	if (neighbor != this && !subscribers.count(neighbor))
	{
		subscribers[neighbor] = move(handler);
	}
}

void NodeSys::Node::unsubscribe(Node* neighbor)
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
		shared_ptr<EventDispatcher> dispathcer = subscriber.second;
	}
}

void NodeSys::Node::createAndSubscribeNewNode()
{

}

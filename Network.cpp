#include <iostream>
#include "Network.h"
#include "SumDispatcher.h"
#include "NumberDispatcher.h"
#include "Random.h"

int NodeSys::Network::uniqueNodeCounter = 0;

void NodeSys::Network::addNode(const shared_ptr<Node> &node)
{
    if (find(nodes.begin(), nodes.end(), node) == nodes.end()) 
    {
        nodes.push_back(node);
    }
    else 
    {
        cerr << "Node already exists!" << endl;
    }
}

void NodeSys::Network::UpdateNetwork()
{
    cout << " Starting network update... " << endl;

    vector<shared_ptr<Node>> toBeRemoved;

    for(auto &node : nodes)
    {
        node->update();
    }

    for(auto &node : nodes)
    {
        if(node->hasNoSubsribe())
        {
            toBeRemoved.push_back(node);
        }
    }

    for(auto &node : toBeRemoved)
    {
        for(auto &neighbor : nodes)
        {
            if(neighbor.get() != node.get())
            {
                neighbor->unsubscribe(node.get());
            }
        }
    }

    for(auto &node : toBeRemoved)
    {
        cout << "Removing node: " << node->getName() << endl;
        nodes.erase(remove(nodes.begin(), nodes.end(), node), nodes.end());
    }

    if (!newNodesBuffer.empty())
    {
        nodes.insert(nodes.end(), newNodesBuffer.begin(), newNodesBuffer.end());
        newNodesBuffer.clear();
    }

    cout << " network update complited. " << endl;

}

void NodeSys::Network::generateRandomSubscriptions()
{
    uniform_int_distribution<size_t> dist(0, nodes.size() - 1);
    uniform_int_distribution<size_t> dispatcherDist(0, 1);

    for(auto &node : nodes)
    {
        size_t numSubscriptions = dist(gen) % 3;

        for (int i = 0; i < numSubscriptions; ++i)
        {
            size_t neighborIdx = dist(gen);

            if (nodes[neighborIdx].get() != node.get())
            {
                shared_ptr<EventDispatcher> dispatcher;
                if (dispatcherDist(gen) == 0)
                {
                    dispatcher = make_shared<SumDispatcher>();
                }
                else
                {
                    dispatcher = make_shared<NumberDispatcher>();
                }
                node->subscribe(nodes[neighborIdx].get(), dispatcher);
            }
        }
    }
}

void NodeSys::Network::generateRandomNetwork(int numNodes)
{
    for (int i = 0; i < numNodes; ++i)
    {
        auto node = make_shared<Random>(Network::generateUniqueNodeName(), newNodesBuffer);
        addNode(node);
    }
    generateRandomSubscriptions();
}

//подключение библиотек iostream, utility
// подключение заголовочных файло Node, SumDispathcer, Random, Network
#include <iostream>
#include <utility>
#include "Node.h"
#include "SumDispatcher.h"
#include "Random.h"
#include "Network.h"
// функция подписки на узел 
void NodeSys::Node::subscribe(Node * neighbor, shared_ptr<EventDispatcher> handler)
{
	//провкерка условия, что подписчик(соседний узел) это не он сам
	// и что его еще нет в списке подпсчиков 
	if (neighbor != this && !subscribers.count(neighbor))
	{
		//добавляем подписку и перемещаем обработчика
		subscribers[neighbor] = move(handler);
	}
}
//функция отписки от узла
void NodeSys::Node::unsubscribe(Node * neighbor)
{
	//инизиализируем локальную переменную присваивая найденное значение подписчика в таблице
	auto it = subscribers.find(neighbor);
	//проверяем найден ли подписчик
	if (it != subscribers.end())
	{
		//удаляем подписчика из списка
		subscribers.erase(it);
	}
}
//функция уведомления подписчиков о событии
void NodeSys::Node::notify(int data)
{
	//запускаем цикл, в котором происходит перебор всех подписчиков
	for (auto& subscriber : subscribers)
	{
		// получаем указатель на соседний узел
		Node* neighbor = subscriber.first;
		// получаем обработчик событий для этого узла
		shared_ptr<EventDispatcher> dispathcer = subscriber.second;
		//Вызываем обработичк передавая следующие значения: данные событи,
		// имя текущего узла и имя узла-подписчика
		dispathcer->Handle(data, name, neighbor->getName());
	}
}
// функция создания и подписки новых узлов
void NodeSys::Node::createAndSubscribeNewNode()
{
	//генерация нового имени для узла
	string newNodeName = Network::generateUniqueNodeName();
	// создание нового узла, с помощью класса Random, с сгенерированным именем и передавая
	// ссылку на буфер новых узлов
	auto newNode = make_shared<Random>(newNodeName, newNodesBuffer);
	//добавление нового узла в буфер сети
	newNodesBuffer.push_back(newNode);
	//подписка текущего узла на новый с передачей указателем на новый узешл
	// и созданием обработчика события классом SumDispatcher
	this->subscribe(newNode.get(), make_shared<SumDispatcher>());
	// вывод в консоль информации о том, что узел создал новый узел и подписался на него
	cout << name << " created new node and subscribe: " << newNodeName << endl;

}

//метод препроцессора, который предотвращает многократное включение заголовочного файла,
// который был включен ранее.
#ifndef NODESYS_NODE_H
#define NODESYS_NODE_H
//подключение контейнера, который хранит пары "ключ-значение", использует таблицы хэширования 
//благодаря чему обеспечивается высокая скорость доступа данных
#include <unordered_map>
//подключение заголовочного файла, диспетчера событий
#include "EventDispatcher.h"
// использование стандартного пространства имён
using namespace std;

// подключение пространства имён
namespace NodeSys
{ 
	//объявление класса
	class Node
	{

	protected:	
		// имя узла
		string name;
		// контейнер подписчиков(соседей) и их обработчик событий
		unordered_map<Node *, shared_ptr<EventDispatcher>> subscribers;
		// ссылка на буфер новых узлов в сети (для создания новых узлов)
		vector<shared_ptr<Node>> &newNodesBuffer;
	
	public:
		// конструктор, который принимает имя узлла, ссылку на буфер новых узлов
		Node(string NodeName, vector<shared_ptr<Node>> &buffer) : name(move(NodeName)), newNodesBuffer(buffer) {}
		// виртуальная функция, которая обновляет статус узла
		virtual void update() = 0;
		// виртуальная функция, которая создает событие узла 
		virtual int generateEvent() = 0;
		// функция подписки на узел 
		void subscribe(Node * neighbor, shared_ptr<EventDispatcher> handler);
		//функция отписки от узла
		void unsubscribe(Node * neighbor);
		// функция уведомления подписчиков о событии 
		void notify(int data);
		//геттер функция получения имени узла
		const string& getName() const { return name; }
		//геттер функция проверки наличия подписчика
		bool hasNoSubsribe() const { return subscribers.empty(); }
		//функция создания и подписки на новый узел 
		void createAndSubscribeNewNode();
		// виртуальный деструктор
		virtual ~Node() = default;
	};
};

#endif
//метод препроцессора, который предотвращает многократное включение заголовочного файла,
// который был включен ранее.
#ifndef NODESYS_NETWORK_H
#define NODESYS_NETWORK_H
// подключение библиотек vector, memory, random
#include <vector>
#include <memory>
#include <random>
//подключение заголовочного файла Node.h
#include "Node.h"
//использование стандартного пространства имен
using namespace std;
//подключение пространства имен NodeSys
namespace NodeSys
{
	// объявление класса Network
	class Network
	{	
	public:
		// контейнер для хранения узлов сети
		vector<shared_ptr<Node>> nodes;
		// контейнер для временного хранения узлов перед добавлением в буфер 
		vector<shared_ptr<Node>> newNodesBuffer;
		// устройство для получения случайных чисел
		random_device rd;
		//генератор случайных чисел
		mt19937 gen;
		// статический счётчик для генерации уникальных имен узлов
		static int uniqueNodeCounter;
		//конструктор который по умолчанию использует генератор случайных чисел
		Network() : gen(rd()) {}
		//функция добавления новых узлов сети
		void addNode(const shared_ptr<Node> &node);
		//функция обновления состояния сети
		void UpdateNetwork();
		//функция создания случайных связей между узлами
		void generateRandomSubscriptions();
		// функция генерации сети с учетом количества случайных узлов
		void generateRandomNetwork(int numNodes);
		// геттер
		// функция проверки активных узлов сети
		bool isNetworkAlive() const { return !nodes.empty(); }
		// геттер
		// функция генерации уникального имени для нового узла
		static string generateUniqueNodeName() { return "Node" + to_string(uniqueNodeCounter++); }
		
	};
}

#endif
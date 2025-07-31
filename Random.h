//метод препроцессора, который предотвращает многократное включение заголовочного файла,
// который был включен ранее.
#ifndef NODESYS_RANDOM_H
#define NODESYS_RANDOM_H
//подключение библиотеки рандом
#include <random>
//подключение заголовочного файла Node
#include "Node.h"

using namespace std;

namespace NodeSys
{
	//объ€вление класса Random с унаследованием от класса Node
	class Random : public Node
	{
		// устройство дл€ получени€ случайных чисел
		random_device rd;
		// генератор случайных чисел
		mt19937 gen;
		//устройство дл€ равномерного распределени€ целых чисел
		uniform_int_distribution<> dis;

	public:
		// конструктор, который получает им€ узла и буфер новых узлов,
		// вызываетс€ конструктор базового класса
		// инициализируетс€ генератор случайных чисел
		// инициализируетс€ устройство распределени€ целых чисел от 1-100
		Random(const string &name, vector<shared_ptr<Node>> &buffer) : Node(name, buffer), gen(rd()), dis(1, 100) {}
		// виртуальна€ функци€ создани€ событи€
		virtual int generateEvent() override;
		// виртуальна€ функци€ обновлени€ состо€ни€ узла
		virtual void update() override;

	};
};

#endif 
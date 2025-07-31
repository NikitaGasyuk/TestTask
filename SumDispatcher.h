//метод препроцессора, который предотвращает многократное включение заголовочного файла,
// который был включен ранее.
#ifndef NODESYS_SUMDISPATCHER_H
#define NODESYS_SUMDISPATCHER_H

//подключение библиотеки iostream
#include <iostream>
// подключение заголовочного файла EventDispatcher
#include "EventDispatcher.h"

using namespace std;

namespace NodeSys
{
	// объ€вление класса SumDispatcher унаследованного от EventDispathcer
	class SumDispatcher : public EventDispatcher
	{
		// инициализаци€ целочисленной переменной суммы узлов сети
		int sum = 0;

	public:
		// виртуальна€ функи€ обработчика событий
		virtual void Handle(int data, const string &sender, const string &receiver) override;

	};
};

#endif 
//метод препроцессора, который предотвращает многократное включение заголовочного файла,
// который был включен ранее.
#ifndef NODESYS_NUMBERDISPATCHER_H
#define NODESYS_NUMBERDISPATCHER_H

//подключение бибилотеки iostream
#include <iostream>
//подключение заголовочного файла EventDispatcher
#include "EventDispatcher.h"

using namespace std;

namespace NodeSys
{
	// объ€вление класса NumberDispatcher унаследованого от EventDispatcher
	class NumberDispatcher : public EventDispatcher
	{
		// инициализаци€ целочисленной переменной количества узлов
		int num = 0;

	public:
		// виртуальна€ функци€ обработки событи€ котора€ принимает следующие параметры
		// данные событи€(data), им€ узла отправител€(sender), им€ узла получател€(receiver)
		virtual void Handle(int data, const string& sender, const string& receiver) override;

	};
}

#endif 

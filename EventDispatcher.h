// метод препроцессора, который предотвращает многгокраное включение загаловочного фалйа,
// который был включен ранее
#ifndef NODESYS_EVENTDISPATCHER
#define NODESYS_EVENTDISPATCHER
// подключение библиотеки string
#include <string>

using namespace std;

namespace NodeSys
{
	//объявление класса EventDispatcher
	class EventDispatcher
	{

	public:
		// виртуальная функция, которая принимает следующие параметры: данные события(data)
		// имя узла отправителя(sender), имя узла отправителя (receiver) 
		virtual void Handle(int data, const string& sender, const string& receiver) = 0;
		// виртуальный конструктор
		virtual ~EventDispatcher() = default;

	};
}

#endif

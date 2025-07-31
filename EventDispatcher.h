//метод препроцессора, который предотвращает многократное включение заголовочного файла,
// который был включен ранее.
#ifndef NODESYS_EVENTDISPATCHER
#define NODESYS_EVENTDISPATCHER
// подключение библиотеки string
#include <string>

using namespace std;

namespace NodeSys
{
	// объ€вление класса EventDispatcher
	class EventDispatcher
	{

	public:
		// виртуальна€ функци€ котора€ принимает следующие параметры
		// данные событи€(data), им€ узла отправител€(sender), им€ узла получател€(receiver)
		virtual void Handle(int data, const string& sender, const string& receiver) = 0;
		// виртуальный деструктор
		virtual ~EventDispatcher() = default;

	};
}

#endif
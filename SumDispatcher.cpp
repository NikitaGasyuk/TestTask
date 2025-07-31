// подключение заголовочного файла
#include "SumDispatcher.h"
// функци€ обработчика событий
void NodeSys::SumDispatcher::Handle(int data, const string &sender, const string &receiver)
{
	// увеличение суммы узлов сети добавл€€ к нему полученные данные
	sum += data;
	// вывод в консоль им€ узла отправител€ -> им€ узла получател€ и текущую сумму узлов сети
	cout << sender << " -> " << receiver << ": S = " << sum << endl;
}

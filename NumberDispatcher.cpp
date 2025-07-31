// подключение заголовочного файла
#include "NumberDispatcher.h"
//виртуальная функция обработки события
void NodeSys::NumberDispatcher::Handle(int data, const string& sender, const string& receiver)
{
	//увеличение переменной на 1 
	num++;
	//вывод в консоль имя узла отправителя, узла получателя и указания количества узлов сети
	cout << sender << " -> " << receiver << ": N = " << num << endl;
}

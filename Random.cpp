//подключается заголовочный файл
#include "Random.h"
//функция обновления состояния узла
void NodeSys::Random::update()
{
	//проверка наличия подписчика
	if (hasNoSubsribe())
	{
		// возврат
		return;
	}
	// инициализация целочисленой переменной которая принимает значения сгенерированного события
	int eventData = generateEvent();
	//вызов функции уведомления  и рассылка сгенерированного события подписчикам
	notify(eventData);
	// создание распределения 0-5
	uniform_int_distribution<> chance(0, 4);
	//проверка на равенство нулю
	if (chance(gen) == 0)
	{
		// вызов функции 
		createAndSubscribeNewNode();
	}
}
// функция создания события 
int NodeSys::Random::generateEvent()
{
	// возвращение случайного числа от 0-100
	return dis(gen);
}
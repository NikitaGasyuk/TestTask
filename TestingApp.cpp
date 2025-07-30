#include <iostream>
#include "Network.h"

using namespace std;

int main()
{
    // обращаемся к классу Network и заносим его в переменную
    NodeSys::Network network;
    // объявляем целочисленную переменную
    int numNodes;
    // выводим в консоль предложение где просится указать количество узлов
    cout << "Enter number of nodes: ";
    // вводимое число
    cin >> numNodes;
    // вызывается из класса Network функция
    network.generateRandomNetwork(numNodes);
    // запуск цикла. Будет выполняться пока функция isNetworkAlive() возвращает true
    while(network.isNetworkAlive())
    {
        // при выполнении условия обновляется состояние сети
        network.UpdateNetwork();
    }
    // при выходе из цикла написать в теримнале что сеть прервана
    cout << " Network terminated. " << endl;
    return 0;
}


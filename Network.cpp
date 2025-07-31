// подключение стандартной библиотеки
#include <iostream>
//подключение заголовочных файлов Network, SumDispatcher, NumberDispatcher, Random
#include "Network.h"
#include "SumDispatcher.h"
#include "NumberDispatcher.h"
#include "Random.h"
// инициализация статического счётчик для генерации уникальных имен узлов
int NodeSys::Network::uniqueNodeCounter = 0;
//функция добавления сети узла 
void NodeSys::Network::addNode(const shared_ptr<Node> &node)
{
    // проверка найденный узел не добавлен в сеть
    if (find(nodes.begin(), nodes.end(), node) == nodes.end()) 
    {
        // добавляем узел
        nodes.push_back(node);
    }
    else 
    {
        //вывод сообщения о том что данный узел существует
        cerr << "Node already exists!" << endl;
    }
}
// функция обновления состояния сети
void NodeSys::Network::UpdateNetwork()
{
    // вывод информации о том что началось обновление сети
    cout << " Starting network update... " << endl;

    // объявление локального контейнера для узлов которые будут удалены
    vector<shared_ptr<Node>> toBeRemoved;

    // запуск цикла поиска всех узлов
    for(auto &node : nodes)
    {
        // вызов метода update() для каждого узла
        node->update();
    }
    // запуск цикла поиска всех узлов
    for(auto &node : nodes)
    {
        // пороверка, есть ли у узла подписчик 
        if(node->hasNoSubsribe())
        {
            // добавляем на удаление
            toBeRemoved.push_back(node);
        }
    }
    // запуск цикла поиска узлов добавленных на удаление
    for(auto &node : toBeRemoved)
    {
        // запуск цикла по поиску соседей узлов
        for(auto &neighbor : nodes)
        {
            // проверяем что соседний узел это не он сам
            if(neighbor.get() != node.get())
            {
                // отписка от соседей
                neighbor->unsubscribe(node.get());
            }
        }
    }
    // запуск цикла поиска узлов помеченных на удаление
    for(auto &node : toBeRemoved)
    {
        // вывод информации о том какой узел удаляется
        cout << "Removing node: " << node->getName() << endl;
        // удаление узла из основного контейнера
        nodes.erase(remove(nodes.begin(), nodes.end(), node), nodes.end());
    }
    // проверка не пустой ли контейнер для временного хранения узлов перед добавлением буфер 
    if (!newNodesBuffer.empty())
    {
        // добавление всех узлов из буфера
        nodes.insert(nodes.end(), newNodesBuffer.begin(), newNodesBuffer.end());
        // очищаем временный контейнер
        newNodesBuffer.clear();
    }
    // вывод о том что обновление сети завершено
    cout << " network update complited. " << endl;

}
//функция создания случайных связей между узлами
void NodeSys::Network::generateRandomSubscriptions()
{
    //распределение случайных чисел для выбора узлов
    uniform_int_distribution<size_t> dist(0, nodes.size() - 1);
    //распределение случайных чисел для выбора типа обработчика
    uniform_int_distribution<size_t> dispatcherDist(0, 1);
    // запуск цикла поиска всех узлов
    for(auto &node : nodes)
    {
        // установка случайного количества подписок
        size_t numSubscriptions = dist(gen) % 3;
        //цикл установки заданного количества подписок
        for (int i = 0; i < numSubscriptions; ++i)
        {
            //устанавливаем случайный индекс соседнего узла
            size_t neighborIdx = dist(gen);
            //проверяем что это не попытка подписаться на самого себя
            if (nodes[neighborIdx].get() != node.get())
            {
                //создание диспетчера событий
                shared_ptr<EventDispatcher> dispatcher;
                //выбирается тип обработчика случайным образом
                if (dispatcherDist(gen) == 0)
                {
                    //создание диспетчера сумм
                    dispatcher = make_shared<SumDispatcher>();
                }
                else
                {
                    //создание диспетчера чисел
                    dispatcher = make_shared<NumberDispatcher>();
                }
                // подписка текущего узла на выбранного соседа
                node->subscribe(nodes[neighborIdx].get(), dispatcher);
            }
        }
    }
}
// функция генерации сети с учетом количества случайных узлов
void NodeSys::Network::generateRandomNetwork(int numNodes)
{
    // создание указаного количества узлов
    for (int i = 0; i < numNodes; ++i)
    {
        // создание узла с классом Random с уникальным именем
        auto node = make_shared<Random>(Network::generateUniqueNodeName(), newNodesBuffer);
        //добавление узла в сеть
        addNode(node);
    }
    // создание случайных подписок между узлами
    generateRandomSubscriptions();
}

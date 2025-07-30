#include <random>
#include "Random.h"

void NodeSys::Random::update()
{
	if (hasNoSubsribe())
	{
		return;
	}
	int eventData = generateEvent();
	notify(eventData);

	uniform_int_distribution<> chance(0, 4);
	if (chance(gen) == 0)
	{
		createAndSubscribeNewNode();
	}
}

int NodeSys::Random::generateEvent()
{
	return dis(gen);
}
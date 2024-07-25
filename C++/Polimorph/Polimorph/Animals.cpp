#include "Animals.h"

Animal::Animal(AnimalID id) :
	m_ID(id)
{
}

Animal::~Animal()
{
}

AnimalID Animal::GetID() const
{
	return m_ID;
}


#pragma once

enum class AnimalID
{
	Bird = 0,
	Cat
};

class Animal
{
public:
	Animal(AnimalID Id);
	virtual ~Animal();

	virtual void Voice() = 0;
	AnimalID GetID() const;

private:
	AnimalID m_ID;
};


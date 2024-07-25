#pragma once
#include <string>
enum Status
{
	InicialAttempts = 1,
	LimitAttempts = 3,
};

class Vectors
{
public:
	Vectors(int init_vector[], int size);
	Vectors(const Vectors& object);
	Vectors();
	~Vectors();

	int& operator[](int index) const;

	void append(const int amount);
	void remove(int index);
	int size() const;
	void reverse();
	void examination();


private:
	bool ChecherSize(int count) const;
	void Resize();

private:
	int m_SizeVector;
	int m_Count;
	int* m_Vector;

	
	std::string m_TruePass = "KuzyaSayMeow!";
	int m_PIN = 250423;
	
};


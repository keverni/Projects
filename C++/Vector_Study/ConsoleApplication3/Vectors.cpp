#include <iostream>
#include "Vectors.h"

Vectors::Vectors(int init_vector[], int size) :
    m_SizeVector(size),
    m_Count(size),
    m_Vector(new int[size])
{
    for (int i = 0; i < m_SizeVector; ++i)
    {
        m_Vector[i] = init_vector[i];
    }
    
}
Vectors::Vectors(const Vectors& object):
    m_SizeVector(object.m_SizeVector),
    m_Count(object.m_Count),
    m_Vector(new int[object.m_SizeVector])
{
    for (int i = 0; i < object.m_SizeVector; ++i)
    {
        m_Vector[i] = object.m_Vector[i];
    }
}
Vectors::Vectors():
    m_SizeVector(1),
    m_Count(1),
    m_Vector(new int [m_SizeVector])
{
}
Vectors::~Vectors()
{
    delete[] m_Vector;
}


int& Vectors::operator[](int index) const
{
    return m_Vector[index];   
}


void Vectors::append(const int amount)
{
    if (ChecherSize(m_Count))
    {
        Resize();
    }
    m_Vector[m_Count++] = amount;
}
void Vectors::remove(int index)
{
    for (int i = index; i < m_SizeVector - 1; ++i)
    {
        m_Vector[i] = m_Vector[i + 1];
    }
    --m_Count;
}
int Vectors::size() const
{
    return m_Count;
}
void Vectors::reverse()
{
    int* temp_vector = new int[m_Count];
    for (int index_vector = m_Count - 1, index_temp = 0; index_vector >= 0 and index_temp < m_Count; --index_vector, ++index_temp)
    {
        temp_vector[index_temp] = m_Vector[index_vector];
    }
    delete[] m_Vector;
    m_Vector = temp_vector;
}
void Vectors::examination()
{
    std::string UserPass = "";
    int CounterOfAttempts = Status::InicialAttempts;
    int UserPIN = 0;
   
    std::cout << "Enter a password!" << std::endl;
    std::getline(std::cin, UserPass);
     
    while (1)
    {
        if (CounterOfAttempts >= Status::LimitAttempts)
        {
            std::cout << "Access is denied. Enter PIN-code!" << std::endl;
            std::cin >> UserPIN;
            if (UserPIN == m_PIN)
            {
                // what we do after correct PIN?
            }
            else
            {
                std::cout << "Access is denied! Container is delete!" << std::endl;
                delete[] m_Vector;
                return;
            }
        }
        
        if (m_TruePass == UserPass)
        {
            std::cout << "Access is allowed!" << std::endl;
            CounterOfAttempts = Status::InicialAttempts;
            return;
        }
        else
        {
            ++CounterOfAttempts;
            std::cout << "Incorrect password! Your try: " << CounterOfAttempts << "/3" << std::endl;
            
        }
        std::getline(std::cin, UserPass);
    }
}


bool Vectors::ChecherSize(int count) const
{
    return (count == m_SizeVector);
}
void Vectors::Resize()
{
    int old_size = m_SizeVector;
    m_SizeVector *= 2;
    int* newdata = new int[m_SizeVector];
    for (int i = 0; i < old_size; ++i)
    {
        newdata[i] = m_Vector[i];
    }
    delete[] m_Vector;
    m_Vector = newdata;
}
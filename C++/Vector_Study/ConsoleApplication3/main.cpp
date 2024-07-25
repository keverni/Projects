#include <iostream>
#include "Vectors.h"

int main()
{
    int mas[5] = {1,2,3,4,5};
    Vectors vector(mas, 5);
    for (int i = 0; i < vector.size(); ++i)
    {
        std::cout << vector[i];
    }
    std::cout << std::endl;
    vector.examination();

    for (int i = 0; i < vector.size(); ++i)
    {
        std::cout << vector[i];
    }

    return 0;
}
#include <iostream>
#include <ctime>
#include "LinkedList.cpp"
#include "LinkedList.hpp"

int main()
{
    srand(time(NULL));

    List <int> list;

    int numbers_count {};
    std::cout << "How many indexes? : ";
    std::cin >> numbers_count;

    for ( int i {0}; i < numbers_count; i++ )
    {
        list.push_back( rand() % 10 );
    }

    std::cout << list[5];
    

    return 0;
}
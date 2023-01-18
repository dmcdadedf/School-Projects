// Double Hash.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    int target = 0;
    int key1 = 0;
    int key2 = 0;
    int size = 0;
    int a = 0;
    int b = 0;
    int i = 0;
    char done = 'F';
    
    std::cout << "Enter Target:";
    std::cin >> target;

    std::cout << "Enter A:";
    std::cin >> a;

    std::cout << "Enter B:";
    std::cin >> b;

    std::cout << "Enter Size:";
    std::cin >> size;
    while (done == 'F')
    {
        key1 = target % a;
        key2 = (b - target % b);
        std::cout << (key1 + i * (key2)) % size;

        std::cout << "\n Is Done?";
        std::cin >> done;
        i++;
    }


    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

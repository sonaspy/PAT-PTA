// Recursive Towers of Hanoi

#include <iostream>

using namespace std;

void towersOfHanoi(int n, char x, char y, char z)
{ // Move the top n disks from tower x to tower y.
    // Use tower z for intermediate storage.
    if (n > 0)
    {
        towersOfHanoi(n - 1, x, z, y);
        std::cout << "Move top disk from tower " << x
                  << " to top of tower " << y << std::endl;
        towersOfHanoi(n - 1, z, y, x);
    }
}

int main()
{
    std::cout << "Moves for a three disk problem are" << std::endl;
    towersOfHanoi(3, 'a', 'b', 'c');
}

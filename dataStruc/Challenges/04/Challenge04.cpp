// Challenge04
// Drew Helgerson - tah568 - CSE2383 - 04/16/24
#include <iostream>
#include <chrono>

using namespace std;

#include "LinkedList.h"
#include "BST.h"

int main()
{
    // srand(time(nullptr)); // comment for testing
    BST b;
    LinkedList l;
    int randInt;
    
    for (int i = 0;i<12;++i)
    {
        randInt = rand() % 999 + 1;
        b.insert(randInt);
        l.append(randInt);
    }
}
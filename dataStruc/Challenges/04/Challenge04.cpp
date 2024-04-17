// Challenge04
// Drew Helgerson - tah568 - CSE2383 - 04/16/24
#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

#include "DLL.h"
#include "BST.h"

void timeInsertion(ostream &stream, int count)
{
    BST b;
    LinkedList l;
    vector<int> randomInts;

    stream << "Insertion(ns): " << count << " random no's" << endl;
    stream << "BST:\tLL:" << endl;
    

    for(int i = 0; i < count; ++i)
    {
        randomInts.push_back(rand() % 999 + 1);
    }
    auto startTime = chrono::high_resolution_clock::now();
    for(int i = 0; i < count; i++)
    {
        b.insert(randomInts[i]);
    }
    auto endTime = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
    stream << duration;    

    startTime = chrono::high_resolution_clock::now();
    for(int i = 0; i < count; i++)
    {
        l.append(randomInts[i]);
    }
    endTime = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
    stream << "\t" << duration << endl;

    
}

int main()
{
    // srand(time(nullptr)); // comment for testing
    timeInsertion(cout,12);
    timeInsertion(cout,24);
    timeInsertion(cout,200);
        
}
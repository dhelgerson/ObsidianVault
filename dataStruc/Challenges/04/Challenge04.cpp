// Challenge04
// Drew Helgerson - tah568 - CSE2383 - 04/16/24
#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

#include "DLL.h"
#include "BST.h"

auto timeNow(){
    return chrono::high_resolution_clock::now();
}

void timeStruct(ostream &stream, int startNo, int endNo,bool random)
{
    BST b;
    LinkedList l;
    vector<int> ints;

    stream << "Insertion(ns): " << abs(endNo - startNo);
    if(random) stream << " random";
    stream << " no's from " << startNo << " to " << endNo << endl;
    stream << "BST:\tLL:" << endl;
    
    if(endNo - startNo < 0)
    {
        for (int i = startNo; i > endNo; i--)
        {
            if (random)
            {
                ints.push_back(rand() % 999 + 1);
            } 
            else 
            {
                ints.push_back(i);
            }
        }
    }
    else 
    {
        for(int i = startNo; i < endNo; ++i)
        {
            if (random) ints.push_back(rand() % 999 + 1); 
            else ints.push_back(i);            
        }
    }
    
    auto startTime = timeNow(); //chrono::high_resolution_clock::now();
    for(int i = 0; i < ints.size(); i++)
    {
        b.insert(ints[i]);
    }
    auto endTime = timeNow();
    auto duration = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
    stream << duration;    

    startTime = timeNow();
    for(int i = 0; i < ints.size(); i++)
    {
        l.append(ints[i]);
    }
    endTime = timeNow();
    duration = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
    stream << "\t" << duration << endl;

    cout << "Recall(ns):" << endl;
    startTime = timeNow();
    for(int i = 0; i < ints.size(); i++)
    {
        b.find(ints[i]);
    }
    endTime = timeNow();
    duration = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
    stream << duration;

    startTime = timeNow();
    for(int i = 0; i < ints.size(); i++)
    {
        l.search(ints[i]);
    }
    endTime = timeNow();
    duration = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
    stream << "\t" << duration << endl << endl;
}

int main()
{
    // srand(time(nullptr)); // comment for testing
    
    timeStruct(cout,0,12,true);
    timeStruct(cout,0,24,true);
    timeStruct(cout,0,200,true);
    timeStruct(cout,0,1000,false);
    timeStruct(cout,1000,0,false);
}
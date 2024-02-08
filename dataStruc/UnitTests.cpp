#include <iostream>

#include "LinkedList.h"
// #include "Node.h"

using namespace std;

int main(){

    LinkedList LL;

    LL.append(1);
    LL.append(20);
    LL.append(15);
    LL.display(cout);
    LL.prepend(5);
    LL.display(cout);
    LL.remove(1);
    LL.display(cout);

    return 0;
}
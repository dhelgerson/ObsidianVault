// Challenge01
// Drew Helgerson - tah568 - CSE2383 - 02/07/24

#include <iostream>
#include "LinkedList.h"
using namespace std;

int main(){
    
    LinkedList LL;
    LL.append(13);
    LL.append(47);
    cout << "should be true: " << LL.search(47) << endl;
    cout << "should be false: " << LL.search(12) << endl;    

    return 0;
}
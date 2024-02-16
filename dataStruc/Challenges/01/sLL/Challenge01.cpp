// Challenge01
// Drew Helgerson - tah568 - CSE2383 - 02/07/24

#include <iostream>
#include "LinkedList.h"
using namespace std;

int main(){
    
    LinkedList LL;
    LL.append(5);
    LL.append(33);
    LL.append(1);
    LL.append(7);
    LL.append(33);
    LL.append(12);
    LL.display( cout );
    LL.remove(33);
    LL.display( cout );
    LL.prepend(12);
    LL.display( cout );
    LL.remove(13);
    LL.display( cout );
    // LL.tailDisplay( cout );
    // LL.tailRemove( 12 );
    // LL.display( cout );

    return 0;
}
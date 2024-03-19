// Challenge02
// Drew Helgerson - tah568 - CSE2383 - 03/19/24

#include "Queue.h"
using namespace std;

int main(){
    
    Queue Q;
    int tmp;
    Q.push(5);
    Q.peek(tmp);
    cout << tmp << endl;
    Q.push(33);
    Q.push(1);
    Q.push(7);
    Q.peek(tmp);
    cout << tmp << endl;
    Q.push(33);
    Q.push(12);
    Q.display( cout );
    Q.pop( );
    Q.display( cout );
    Q.push(14);
    Q.display( cout );
    Q.pop( );
    Q.pop( );
    Q.display( cout );
    Q.pop( );
    Q.pop( );
    Q.display( cout );
    Q.peek(tmp);
    cout << tmp << endl;

    return 0;
}
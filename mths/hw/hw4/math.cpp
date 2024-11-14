#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 5) 
    {
        cout << "you must enter 4 numbers" << endl;
        exit(EXIT_FAILURE);
    }

    // following executes if 4 numbers are present

    int sum = 0;
    for (int i = 1;i < argc;i++)
    {
        sum += stoi(argv[i]);
    }

    cout << sum << endl;
}


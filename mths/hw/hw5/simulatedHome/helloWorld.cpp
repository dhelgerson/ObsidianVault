#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

int main()
{
	string name;

	cout << "What is your name? ";
	getline(cin, name);

	cout << "Hello, " << name << endl;

	return 0;
}

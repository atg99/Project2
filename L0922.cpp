#include <iostream>
#include <string>

using namespace std;

int TestString()
{
	char Greeting1[6] = "Hello";
	char Greeting2[6] = { 'H','E','L','L','O','\0' }; 
	string Greeting3 = "Hello";

	cout << Greeting3 + Greeting3 << endl;
	return 0;
}
#include <iostream>

using namespace std;

int main()
{
	int sum = 0;
	int sum3 = 0;
	for (int i = 1; i < 101; i++)
	{
		if (i % 3 == 0)
		{
			sum3 += i;
		}
		sum += i;
	}

	cout << sum << endl;
	cout << sum3 << endl;
	return 0;
}
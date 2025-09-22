#include <iostream>

using namespace std;

int main()
{
	int Sum = 0;
	int Sum3 = 0;
	for (int i = 1; i < 101; ++i)
	{
		Sum += i;
	}

	for (int i = 3; i <= 100; i += 3)
	{
		Sum3 += i;
	}
	//cout 버퍼에 저장
	//endl 버퍼 해제
	cout << Sum << endl;
	cout << Sum3 << endl;
	return 0;
}
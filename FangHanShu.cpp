#include<iostream>
using namespace std;

class IsGreaterThanVariable
{
public:
	IsGreaterThanVariable(int t) :var(t) {};
	bool operator()(int num)
	{
		return num > var ? true : false;
	}
private:
	int var;
};

int counting(int* start, int* end, IsGreaterThanVariable count)
{
	int couting = 0;
	for (int* i = start; i != end + 1; i++)
	{
		couting = count(*i) ? couting+ 1 : couting;
	}
	return couting;
}

int main()
{
	int a[] = {12,11,41,51,3,12,52};
	int result = counting(a, a + 6, IsGreaterThanVariable(13));
	cout << result;
	return 0;
}
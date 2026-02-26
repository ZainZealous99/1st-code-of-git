#include<iostream>
#include <string>
using namespace std;

template <class T>

T display(T n)
{
	return n;
}

int main()
{

	cout << "Output is this:" << display<string>("Hello world") << endl;

	return 0;
}
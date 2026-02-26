#include <iostream>
#include <string>
using namespace std;


template <class T>

class display
{
private:
	T n;

public:


	display(T N1)
	{
		n = N1;
	}
	void setvalue(T N)
	{
		n = N;
	}
	string getname()
	{
		return n;
	}
};
int main()
{
	display<string>stringdisplay("HELLO WORLD");

	cout << "Output is this:" << stringdisplay.getname() << endl;
	return 0;
}


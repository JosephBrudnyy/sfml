#include<iostream>
#include<string>
#include<fstream>
using namespace std;


namespace firstNS
{
	void Foo()
	{
		cout << "1 Foo" << endl;
	}	 
	
}


namespace secondNS
{
	void Foo()
	{
		cout << "2 Foo" << endl;
	}
	
}






int main()
{
	firstNS::Foo();
	secondNS::Foo();
	
}



#include <iostream>
#include <string>
#include "SetOperations.h"

using namespace setoperations;
using namespace std;

class collection
{
	public:	
		int num;
		string str;

		collection(int n, string s)
			:num(n), str(s) {};
};

int main()
{
	SetVector<collection> set1(20);
	for (int i(0); i < 20; i++)
	{
		collection collec(i, to_string(i) + " love");
		set1.set.push_back(collec);
	}
		
	SetVector<int> set2 = set1.Select<int>(
		set1.set,
		[](collection element) 
		{ 
			return element.num;
		}
	)
	.FindAll(
		[](int element)
		{
			return element > 3 && element < 18;
		}
	);

	for (vector<int>::iterator iter = set2.set.begin(); iter != set2.set.end(); iter++)
		cout << *iter << endl;

	return 0;
}
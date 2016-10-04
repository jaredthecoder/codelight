#include <iostream>
#include <set>
using namespace std;

int main()
{
	set <int> S, A, C;
	set <int>::iterator Si, t;
	int i, z, zz;
	while (cin >>i) {S.insert(i);}
	C = S;
	for (Si = S.begin(); Si != S.end(); Si++)
	{
		z = *Si;
		A.insert(*Si);
		t = Si;
		Si++;
		S.erase(*t);
		for(t = S.begin(); t != S.end(); t++)
		{
				zz += *t;
				A.insert(*t);
				if (zz == z){ z = 0; break;}
		} 
		if (z == 0) break;
	}

	for (Si = A.begin(); Si != A.end(); Si++)
	{
		cout << *Si <<" ";
	}
	cout <<endl;
	return 0;
}

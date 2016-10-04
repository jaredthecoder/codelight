#include <iostream>
using namespace std;

int main()
{
	string s, a = "";
	bool T;
	while(cin >> s) {
		T = false;
		if (s.find("\"") != string::npos) {
			a += s.substr(1);
			while (cin >> s){
				if(s.find("\"") == string::npos) {a += s; a += " ";}
				else{ 
					a += s.substr(0, s.find("\""));
					T = true;
					break;
				}
			}
		}
		if (T) cout<<a<<"\n";
	  else cout << s <<"\n";
		a = "";
  }
	return 0;
}

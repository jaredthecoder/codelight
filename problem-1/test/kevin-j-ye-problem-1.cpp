#include<string>
#include<iostream>

using namespace std;
int main(){
	string s;
	bool q = false;
	
	while(getline(cin, s))
	for(char c : s) {
		if(c == ' ' && !q)
			cout << '\n';
		else if(c == '\"' && !q) {
			q = true;
		}
		else if(c == '\"' && q) { 
			q = false;
		}
		else
			cout << c;
	}
	return 0;
}
		


#include <iostream>
#include <string>

using namespace std;

int main() {
	int c;
	string temp;
	string w;
	int b;
	while(getline(cin, w)) {
		temp = "";

		for(int i = 0; i < w.size(); i++) {
			b = 0;
			if(w[i] == '"')
				c++;
			else if(w[i] == ' ' && c != 1) {
				temp += w[i];
				cout << temp << endl;
				temp = "";
			}
			else
				temp += w[i];
			if(c == 2) {
				cout << temp << endl;
				temp == "";
				c = 0;
				b = 1;
			}
		}
		if(b)
			cout << temp << endl;
	}
}

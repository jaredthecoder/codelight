#include<algorithm>
#include<vector>
#include<cmath>
#include<iostream>

using namespace std;

int sum = 0;
int f(int i) {
	return abs((double)(sum - i)) > abs((double)sum);
}

int main() {
	int i;
	vector<int> v;
	while(cin >> i)
		v.push_back(i);
	for(int i : v)
		sum += i;
	sort(begin(v), end(v));
	while(sum != 0) {
		 auto j = find_if(begin(v), end(v), f);
		 *j = -100000000;
	}	
	for(int i : v) {
		if(i != -100000000)
			cout << i << " ";
	}
	return 0;
}

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <int> nums;

int rec(vector <int> nums, int sum, vector <int> ans) {
	vector <int> temp;
	vector <int> temp2;

	if(sum == 0 && ans.size() != 0) {
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		return 1;
	}

	for(int i = 0; i < nums.size(); i++) {
		sum += nums[i];
		temp2 = ans;
		ans.push_back(nums[i]);
		for(int j = 0; j < nums.size(); j++)  {
			if(j != i) {
				temp.push_back(nums[j]);
				cout << nums[j] << endl;
			}

		}
		if(rec(temp, sum, ans))
			return 1;
		sum -= nums[i];

		temp.resize(0);
		ans = temp2;
		


	}

}


int main() {
	int num;
	vector <int> answer;

	while(cin >> num)
		nums.push_back(num);

	rec(nums, 0, answer);

}


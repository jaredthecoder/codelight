#include <iostream>
#include <vector> 
#include <algorithm>
#include <random> 
using namespace std;
main(){
int i;
vector<int> v;
while(cin>>i)
	v.push_back(i);
vector<int> s;
while(1){

shuffle (v.begin(), v.end(), std::default_random_engine(0));
s.resize(0);
s.push_back(v[0]);
int c=v[0];
for(int j=1;j<v.size();j++)
	{
	if(!c)
		break;
	s.push_back(v[j]);
	c+=v[j];
	}
if(!c)break;
}
for(int j=0;j<s.size();j++)
	cout<<s[j]<<" ";
cout<<"\n";
}

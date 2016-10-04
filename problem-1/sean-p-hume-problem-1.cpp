#include <iostream>
using namespace std;
main(){
bool k=1;
string i,j;
while(getline(std::cin, i)){
	for(int p=0; p<i.size();p++)
		{
		if(i[p]=='\"') k=(!k);
		if(!k&&i[p]!='\"')cout<<i[p];
		if(k&&i[p]==' ')cout<<"\n";
		}
}
cout<<"\n";}

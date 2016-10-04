#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]){
  int i, j, k;
  int tmp;
  string s;
  vector <int> nums;
  vector <int> rv;

  while(cin >> s){
    nums.push_back(atoi(s.c_str()));
  }

  for(i = 0; i < (1 << nums.size()); i++){
    tmp = 0;
    rv.resize(0);
    for(j = 0; j<nums.size(); j++){
      if(i & (1 << j)){
        tmp += nums[j];
        rv.push_back(nums[j]);
      }
      if(rv.size() != 0 && tmp == 0){
        printf("%d", rv[0]);
        for(k = 1; k<rv.size(); k++){
          printf(" %d", rv[k]);
        }
        printf("\n");
        exit(0);
      }
    }
  }

}

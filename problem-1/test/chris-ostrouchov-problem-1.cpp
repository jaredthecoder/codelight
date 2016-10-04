#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>

int main() {
  std::string s;
  
  for (std::string line; std::getline(std::cin, line);) {
    s.append(line);
  }

  bool inside_quote = false;

  std::string token;

  int start = 0;
  int end = 0;

  for (unsigned int i=0; i<s.length(); i++) {
    if (isspace(s[i])) {
      token = s.substr(start,end);
      std::cout << token << "\n";
      start = end = i;
    }
    end++;
  }
  // std::cout << fullstring << std::endl;
  return 0;
}

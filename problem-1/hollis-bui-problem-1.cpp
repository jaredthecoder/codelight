#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

main(){
    string i;
    char i2[10000];
    char i3[2];

    while (cin >> i){
        if (i.find("\"") == string::npos)
            cout << i << endl;
        else{
            cout << i;
            //cin >> i
            //
            while ((fgets(i3, 2, stdin)) && (i3[0] != '"') && (i3[1] != '"'))
                cout << i3;
            //cin.getline(i2, sizeof(i2));
            //while ((cin >> i) && (i.find("\"") == string::npos))
            //    cout << i;
            cout << i3 << endl;
        }
    }
}

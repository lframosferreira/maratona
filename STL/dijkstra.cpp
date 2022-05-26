#include <bits/stdc++.h>

using namespace std;

#include <string>

int main(){

    string str;
    set<string> s;
    while (cin >> str){
        s.insert(str);
    }

    cout << s.size() << endl;

    return 0;
};
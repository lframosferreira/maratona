#include <bits/stdc++.h>

using namespace std;

void updateSum(int& sum, int qtd){
    sum += qtd;
}

int main(){

    int t; cin >> t;
    string s; 
    
    for (int i = 0; i < t; i++){
        set<pair<pair<int, int>, pair<int, int>>> paths;
        pair<int, int> currStart = {0, 0};
        pair<int, int> currFinish;
        int sum = 0;
        cin >> s;
        for (auto c : s){
            currFinish = currStart;
            if (c == 'S'){
                currFinish.second--;
            }
            else if (c == 'N'){
                currFinish.second++;  
            }
            else if (c == 'E'){
                currFinish.first++; 
            }
            else if (c == 'W'){
                currFinish.first--; 
            }


            if (!paths.count({currStart, currFinish}) && !paths.count({currFinish, currStart})){
                paths.insert({currStart, currFinish});
                updateSum(sum, 5);
            }
            else{
                updateSum(sum, 1);
            }       
            currStart = currFinish;

        }
        cout << sum << endl;   
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main(){

    int T; cin >> T;

    for (int i = 0; i < T; i++){
        string proibido;
        string bracelete;
        cin >> proibido >> bracelete;
        
        int k = proibido.size();
        
        for (int j = 0; j < k; j++){
            bracelete += bracelete.at(j);  
        }
        
        size_t q1 = bracelete.find(proibido);
        reverse(bracelete.begin(), bracelete.end());
        size_t q2 = bracelete.find(proibido);
        if (q1 == string::npos && q2 == string::npos){
            cout << "N" << endl;
        }
        else cout << "S" << endl;
    }

    return 0;
};
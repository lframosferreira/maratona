#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;cin>>t;
    int n,m;
    int B, W;
    for(int i=0;i<t;i++){
        cin>>n>>m;
        for (int j = 0; j < n; j++){
            for (int k = 0; k < m; k++){
                cout << ((j==0 && k==0) ? 'W' : 'B');
            }
            cout << endl;
        }
    }
    return 0;
}

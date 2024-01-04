#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back()

typedef long long ll;
typedef pair<int , int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main(){ _
    int t; cin>>t; int n, k;
    while (t--){
        cin >> n >> k;
        vector<int> v(n);
        for (int &i : v) cin >> i;
        int s = 0;
        for (int i = 0; i < k; i++){
            s+= v[i];
        }
        int prev = 0;
        for (int i = k; i < v.size(); i++){
            if (v[i] != v[prev]){
                v.insert(v.begin() + i, v[prev]);
            } 
            prev++;
        }
        cout << v.size() << endl;
        for (auto e : v) cout << e << " ";
        cout << endl;
    }
    exit(0);
}

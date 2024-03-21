// pescoço pra baixo é canela

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int , int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool prime(int x){
    for (int i = 2; i*i <= x; i++){
        if (x%i==0){
            return false;
        }
    }
    return true;
}

int main(){ _
    int t; cin >> t;
    while (t--){
        int n; cin>> n;
        vector<int> v(n);
        for (int &i : v) cin >> i;
        sort(v.begin(), v.end());
        int ptr=0;
        int curr=0;
        while (v[ptr]==0)ptr++;
        if (v[ptr]!=1){
            cout << 0 << endl;
        }else {
            curr=1;
            for (int i = ptr;i < n; i++){
                if (i==n-1){
                    curr=v[i]+1;
                    while (!prime(curr))curr++;
                    break;
                }
                else if (v[i]+1==v[i+1]){
                    curr=v[i]+1;
                }else if (v[i]==v[i+1]){
                    continue;
                }else {
                    curr=v[i]+1;
                    while (!prime(curr)){
                        if(v[i+1]==curr)i++;
                        curr++;
                    }
                    if (v[i+1]==curr) continue;
                    else break;
                }
            }
            cout << curr-1 <<endl;
        }
        
    }
    exit(0);
}


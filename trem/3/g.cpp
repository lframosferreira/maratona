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
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<vd> vdd;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    int t; cin >> t;
    while (t--){
        int idx;
        int n; cin >> n;
        vi v(n); for (int &i: v) cin >> i;
        int eq=1;
        for (int i = 0; i < n-1; i++) if (v[i]!=v[i+1])eq=0;
        if (eq) cout << -1 << endl;
        else {
            int mx=*max_element(v.begin(), v.end());
            if (v[0]==mx and v[1] < mx){
                idx=1;
            }
            else if (v[n-1]==mx and v[n-2]<mx){
                idx=n;
            }
            else for (int i = 1; i < n-1; i++){
               if (v[i]==mx and (v[i-1]<mx or v[i+1]<mx)){
                idx=i+1;break;
               } 
            }
            cout << idx << endl;
        }
    }    
    exit(0);
}

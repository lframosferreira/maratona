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
        int n; cin >> n;
        vi v(n);
        for (int &i: v) cin >> i;
        int mn=INF;
        for (int i = 0; i < n; i++){
            int cnt=i;
            int idx=i;
            while (1){
               if (idx + v[idx]+1) break;
               idx+=v[idx]+1; 
            } 
            if (idx < n) cnt+=n-idx;
            mn=min(mn, cnt);
        }
        cout << mn << endl;   
    }    
    exit(0);
}
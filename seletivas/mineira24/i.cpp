// pescoço pra baixo é canela

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define bs bitset
#define umap unordered_map
#define uset unordered_set
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

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
        vi v(n+1);
        ll kaio=0;
        for (int i = 1; i <= n; i++) {cin >> v[i];kaio+=v[i];}
        
        ll mx=-INF;
        ll curr=0;
        for (int i = 1; i < n; i++) {
           curr = curr+v[i]; 
           if (mx < curr) mx = curr;
           curr=max(curr, 0LL);
        }
        curr=0;
        for (int i = 2; i <= n; i++) {
           curr = curr+v[i]; 
           if (mx < curr) mx = curr;
           curr=max(curr, 0LL);
        }

        cout << (kaio > mx ? "YES" : "NO") << endl;

    }    
    exit(0);
}

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
    string a; cin >> a;
    int k; cin >> k;
    vi w(26); for (int& i: w) cin >> i;
    int ans=0;
    for (int i = 0; i < a.length(); i++) ans+=w[a[i]-'a']*(i+1);
    int mx = *max_element(all(w));    
    for (int i = 0; i < k; i++) ans += mx * (a.length()+i+1);
    cout << ans << endl;
    exit(0);
}

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
    int n; cin >> n;
    vi m(n); for (int& i: m) cin >> i;
    int idx = distance(m.begin(), max_element(all(m)));
    int l=idx-1;int r=idx+1;
    vi ans(n);
    int mx=m[idx];
    ans[idx]=m[idx];
    while (l>=0){
        mx=min(m[l], mx);
        ans[l]=mx;
        l--;
    }    
    mx=m[idx];
    while (r<= n-1){
        mx=min(m[r], mx);
        ans[r]=mx;
        r++;
    }    
    for (auto& i: ans) cout << i << " ";
    cout << endl;
    exit(0);
}

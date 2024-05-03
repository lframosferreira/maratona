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
    int n, x; cin >> n >> x;
    int diff=0;
    vector<pii> v(n); for (auto& [a, b]: v){ cin >> a >> b; diff+=b-a+1;}
    int ans=0;
    int ptr=0;
    int minuto=1;
    while (1){
        if (ptr==n) break;
        while (minuto + x <= v[ptr].f){
            minuto+=x;
        }
        ans+=v[ptr].f-minuto;
        minuto=v[ptr].s+1;
        ptr++;
    }
    cout << ans + diff << endl;
    exit(0);
}

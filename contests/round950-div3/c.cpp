// pescoço pra baixo é canela

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define sz(v) (int)v.size()
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define bs bitset
#define umap unordered_map
#define uset unordered_set
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int , int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<double> vd;
typedef vector<vd> vvd;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vi a(n);
        for (int &i : a) cin >> i;
        vi b(n);
        map<int, int> cnt;
        int add=0;
        int totdiff=0;
        for (int &i : b) {
            cin >> i;
            if (a[add]!=i) {
                cnt[i]++;
                totdiff++;
            }
            add++;
        }
        map<int, int> mapd;
        int m; cin >> m;
        int last;
        for (int i = 0; i < m; i++) {
            int x; cin >> x;
            if (i==m-1) last=x;
            mapd[x]++;
        }
        // sao todos iguais. Precisamos q ultimo element de d esteja em b
        if (totdiff == 0){
            int ok = find(all(b), last) != b.end();
            if (ok) cout << "YES" << endl;
            else cout <<"NO" << endl;
            continue;
        }
        // tem algm diferent. gulosaemnte vamos retirand de tras ora fente
        if (find(all(b), last) == b.end()){
            cout << "NO" << endl;
            continue;
        }
        int ok=1;
        for (auto& [x, y] : cnt){
            if (mapd[x] < y) ok=0;
        }
        cout << (ok ? "YES" : "NO") << endl;
    } 
    exit(0);
}

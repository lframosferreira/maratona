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
#define umap unordered_map
#define uset unordered_set
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef unsigned long long ull;
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
        int n, k1, k2,p,b;
        cin >> n >> k1 >> k2 >> p >> b;
        int mn = min(k1, k2);
        p-=mn;
        p-=(max(k1, k2)-mn)/2;
        if (p>0) {
            cout << "NO" << endl;
            continue;
        }
        b-=n-max(k1, k2);
        b-=(max(k1,k2)-mn)/2;
        if (b>0){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
    exit(0);
}
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
    int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;    
    r1--;c1--;r2--;c2--;
    cout << (r1==r2 or c1==c2 ? 1 : 2) << " ";

    if (abs(r1-r2)==abs(c1-c2)) cout << 1 << " ";
    else if ((r1+r2)%2==(c1+c2)%2) cout << 2 << " ";
    else cout << 0 << " ";

    cout << abs(r1-r2) + abs(c1-c2) - min(abs(r1-r2), abs(c1-c2)) << endl;
    exit(0);
}
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

int main(){ _
    int n; cin >> n;
    vector<pii> v(n);
    for (int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        v[i]={a, b};
    }    
    int ans=0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i==j) continue;
            if (v[i].f==v[j].s) ans++;
        }
    }
    cout << ans << endl;
    exit(0);
}

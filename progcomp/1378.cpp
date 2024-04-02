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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll sq(ll x){
    return x*x;
}

int main(){ _
    while (1){
        int N; cin >> N;
        if (N==0) break;
        vector<pll> v(N);
        for (int i = 0; i < N; i++){
            ll x, y; cin >> x >> y;
            v[i]={x, y};
        }
        ll cnt=0;
        for (int i = 0; i < N; i++){
            map<ll, int> dists;
            for (int j = 0; j < N; j++){
                if(i==j) continue;
                ll d = sq(v[i].f-v[j].f) + sq(v[i].s-v[j].s);
                dists[d]++;
            }
            for (auto [dist, qnt]: dists) if (qnt>1) cnt+=(qnt*(qnt-1))/2;
        }
        cout << cnt << endl;
    } 
    exit(0);
}

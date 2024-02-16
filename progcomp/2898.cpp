// pescoço pra baixo é canela

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int , int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    while (true){
        int N, M, A; cin >> N >> M >> A; 
        if (N == M == A == 0) break;
        vector<vector<pii> g(N+1);
        while (M--){
            int O, D, S;
            cin >> O >> D >> S;
            g[O].pb({D, S});
            g[D].pb({O, S});
        }

        
    }
    exit(0);
}

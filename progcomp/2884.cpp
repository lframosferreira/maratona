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
    int N, M; cin >> N >> M;
    int on; cin >> on;
    vector<bool> init(M+1, false);
    vector<bool> goal(M+1, false);
    for (int i = 0; i < on;i++){
        int aux;cin>>aux;init[aux]=true;
    }
    vector<vi> connections(N+1);
    for (int i = 1; i <= N;i++){
        int j; cin >> j;
        while (j--){
            int aux; cin>> aux;
            connections[i].pb(aux);
        }
    }
    bool can=false;
    int ans=0;
    for (int i = 1; i <= 2*N; i++){
        if (init==goal){
            can=true;break;
        } 
        ans++;
        int idx=(i>N ? i-N:i);
        for (auto c: connections[idx]){
            init[c] = !init[c];
        }
    }
    if(can) cout << ans <<endl;
    else cout << -1 << endl;
    exit(0);
}

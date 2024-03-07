// pescoço pra baixo é canela
// NÃO PASSOU

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
    int N, M;
    while (cin >> N >> M){
        vector<int> dgs(N); 
        while (M--){
            int A, B; cin >> A >> B;
            dgs[A]++;dgs[B]++;
        }
        int mn = INF;
        int mn_idx;
        int scnd_mn = INF;
        int scnd_mn_idx;
        for (int i = 0; i < N; i++){
            if (dgs[i]<mn){
                mn=dgs[i];
                mn_idx=i;
            }
        }
        for (int i = 0; i < N; i++){
            if (i==mn_idx) continue;
            if (dgs[i]<scnd_mn){
                scnd_mn=dgs[i];
                scnd_mn_idx=i;
            }
        }
        int a = min(mn_idx, scnd_mn_idx);
        int b = max(mn_idx, scnd_mn_idx);
        cout << a << " " << b << endl;
    }
    exit(0);
}

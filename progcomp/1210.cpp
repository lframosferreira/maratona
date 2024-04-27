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
typedef vector<double> vd;
typedef vector<vd> vdd;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int N, I, M, P;

int main(){ _
    while (cin >> N >> I >> M >> P){
        vi custo(M); for (int &i: custo) cin >> i;
        vi venda(M); for (int &i: venda) cin >> i;
        vvi dp(N, vi(M));
        for (int i = 1; i < N; i++){
            for (int j = I; j < M; j++){
                if (venda[j] >= custo[j]){
                   dp[i][j]=venda[j]-custo[j] + dp[i-1][j-1]; 
                }
            }
        }
    } 
    exit(0);
}

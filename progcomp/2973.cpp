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

int N, C, T;
vi P;

bool can_eat_all(ll time){
    int qnt_competidores = 1;
    ll pode_comer = T*time;
    for (int i = 0; i < N; i++){
        if (pode_comer >= P[i]){
            pode_comer-=P[i];
        } else {
            qnt_competidores++;
            pode_comer = T*time;
            i--;
        }
        if (qnt_competidores > C) break;
    } 
    return qnt_competidores <= C;
}

int main(){ _
    cin >> N >> C >> T;
    P.resize(N);
    for (int &i : P) cin >> i;
    int l = 0;
    int r = 1e9+1;
    while (l < r) {
        int m = (l+r)/2;
        if (can_eat_all(m)){
            r = m; 
        } else {
            l = m+1;
        }
    }
    cout << l << endl;
    exit(0);
}

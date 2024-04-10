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

const int MAX = 2e3+10;

int N, P;
int dp[MAX][MAX];

int main(){ _
    while (cin >> N >> P){
        vi dano(N);
        vi mana(N);
        for (int i = 0; i < N; i++){
            cin >> dano[i] >> mana[i];
        } 
        for (int i=1; i <= N;i++){
            for (int j = 1;j <= P;j++){
                
            }
        }
    } 
    exit(0);
}

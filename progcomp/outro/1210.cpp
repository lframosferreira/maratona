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

int main(){ _
    int N, I, M, P;
    while (cin >> N >> I >> M >> P){
        vi c(M), v(M);
        for (int &i: c) cin >> i;
        for (int &i: v) cin >> i;
        int ans=0;
        for (int i = 0; i < N; i++){
            if (I==M){
                I=1;
                ans+=v[M];
                ans-=P;
            }
            else if (c[I] >= P - v[I]){
                I=1;
                ans += P - v[I];
            }
            else{
                ans+=c[I];
                I++;
            } 
        }
        cout << ans << endl;
    }
    exit(0);
    }

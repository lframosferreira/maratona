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

bool oob(int x, int y, int N, int M){
    return x < 0 or x >= N or y < 0 or y >= M;
}

int main(){ _
    while (1){
        int N, M; cin >> N >> M;
        if (N == 0 and M == 0) break;
        vi v(N*M + 1);
        for (int i = 0; i < N*M/2 + 1; i++) cin >> v[i*2];
        int ans = 0;

    } 
    exit(0);
}

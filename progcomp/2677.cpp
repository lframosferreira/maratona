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
    while (1){
        int N; cin >> N;
        if (N==0) break;
        vector<int> v(2*N);
        for (int &i: v) cin >> i;
        int l=0,r=2*N-1;
        int ans=0;
        vector<int> dp(2*N, 2);
        cout << ans << endl;
    }
    exit(0);
}

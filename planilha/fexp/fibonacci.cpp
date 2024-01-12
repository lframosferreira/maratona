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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const ll MOD = 1e9 + 7;

int main(){ _
    ll n; cin >> n;
    ll a = 0;
    ll b = 1;
    ll c;
    for (int i = 2; i < n+1; i++){
        c = (a+b)%MOD;
        a = b;
        b = c;
    }
    cout << (n == 0 ? 0 : b) << endl;
    exit(0);
}

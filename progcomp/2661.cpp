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

const ll MAX = 1e6 + 10;

int main(){ _
    ll n; cin >> n;
    ll cnt=0;
    for (ll i = 2; i*i<n;i++){
        if (n%i==0){
            cnt++;
            while (n%i==0)n/=i;
        }
    }
    if(n>1)cnt++;
    ll ans = pow(2, cnt) - cnt - 1;
    cout << ans << endl;
    exit(0);
}

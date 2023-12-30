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

ll tot(int n){
    ll ret = n;
    for (ll p = 2; p * p <= n; p++){
        if (n % p == 0){
            while (n%p == 0) n /= p;
            ret-=ret/p;
        }
    }
    if (n>1) ret-=ret/n;
    return ret;

}
int main(){ _
    int n; while (cin >> n) cout << tot(n)/2 << endl;
    exit(0);
}

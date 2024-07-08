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

int gcd_extended(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

ll fexp(ll a, ll b, ll mod){
    a %= mod;
    ll res = 1;
    while (b>0){
        if (b & 1) res = res*a%mod;
        a=a*a%mod;
        b >>=1;
    }
    return res;
}


int main(){ _
    int N, E, C; cin >> N >> E >> C; 
    
    int P, Q;
    for (int i = 2; i*i <= N; i++){
        if (N % i == 0){
            P = i;
            Q = N/i;
            break;
        }
    }
    
    int phi = (P-1)*(Q-1);

    int x, y;
    gcd_extended(E, phi, x, y);
    x = (x%phi + phi) % phi;
     
    cout << fexp(C, x, N) << endl;
    exit(0);
}

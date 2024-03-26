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

const int MAX = 1e6+10;

bool prime[MAX];

void sieve(){
    memset(prime, true, sizeof prime);
    prime[0]=prime[1]=false;
    for (int i = 2; i*i <= MAX-5; i++){
        if (prime[i]){
            for (int j = i*i; j <= MAX-5; j+=i){
                prime[j]=false;
            }
        }
    }
}

ll fexp(ll a, ll b) {
    a %= 2;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % 2;
        a = a * a % 2;
        b >>= 1;
    }
    return res;
}

int main(){ _
    sieve();
    int A, B; cin >> A >> B;
    if (A == B){
        cout << "?" << endl;
    }else {
        int cnt=0;
        if (A>B){
            int aux=B;
            B=A;
            A=aux;
        }
        dbg(A);dbg(B);
        for (int i = A; i <= B; i++) if (prime[i]) cnt++;
        dbg(cnt);
        if (fexp(cnt, B-A)%2 == 0) cout << "Bob" << endl;
        else cout << "Alice" << endl;
    }
    exit(0);
}

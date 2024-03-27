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

const int MAX = 2e7+10;
const ll MOD = 2;

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

ll c[MAX];

int main(){ _
    sieve();
    c[0]=1;c[1]=0;c[2]=1;
    for (int i = 3; i <= MAX-5; i++) c[i]=c[i-1]+__builtin_ctz(i & -i);

    ll A, B; cin >> A >> B;
    if (A == B){
        cout << "?" << endl;
    }else {
        int cnt=0;
        if (A>B){
            int aux=B;
            B=A;
            A=aux;
        }
        for (int i = A; i <= B; i++) if (prime[i]) cnt++;
        if (cnt==0){
            cout << "Bob" << endl;
        } else {
            ll n = cnt;
            ll k = B-A;
            if (c[n+k-1]-c[k]-c[n-1] >= 1) cout << "Bob" << endl;
            else cout << "Alice" << endl;
        }
    }
    exit(0);
}

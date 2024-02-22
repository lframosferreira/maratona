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

const int MAX = 1e5 + 10;
bool prime[MAX];

void sieve(int lim){
    memset(prime, true, sizeof prime);
    prime[0]=prime[1]=false;
    for (int i = 2; i <= lim; i++) {
        if (prime[i]){
            for (int j = i+i; j <= lim; j+=i) prime[j]=false;
        }
    }
}

bool superprime(int n){
    while (n > 0){
        int r = n%10;
        if (prime[r]) {
            n = (n-r)/10;
        }else {
            return false;
        }
    }
    return true;
}

int main(){ _
    sieve(MAX-5);
    int n; 
    while (cin >> n){
        if (!prime[n]) cout << "Nada" << endl;
        else cout << (superprime(n) ? "Super" : "Primo") << endl; 
    }
    exit(0);
}

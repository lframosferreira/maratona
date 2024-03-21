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

const int MAX = 1e7 + 10;


bool prime[MAX];

void sieve(){
    prime[0]=prime[1]=false;
    memset(prime, true, sizeof prime);
    for (int i = 2; i*i <= MAX-5; i++) {
        if (prime[i]){
            for (int j = i*i; j <= MAX-5; j+=i){
                prime[j]=false;
            }
        }
    }
}

int main(){ _
    int t; cin >> t;
    sieve();
    while (t--){
        int n; cin >> n;
        set<int> v;
        for (int i = 0; i < n; i++){
            int aux; cin >> aux;
            v.insert(aux);
        }
        int ans=0;
        if (v.find(1)==v.end()){
            cout << 0 << endl;
            continue;
        }
        for (int i = 2; i < MAX; i++){
            if (prime[i]){
                if (v.find(i) == v.end()){
                    ans=i-1;
                    break;
                }
            } 
        }
        cout << ans << endl; 
    }
    exit(0);
}


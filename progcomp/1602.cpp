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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll; 
typedef vector<int> vi;
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e6 + 10;
int dp[MAX];
int hp[MAX];
int prime[MAX];

void crivo(int lim){
    for (int i = 1; i <= lim; i++) prime[i]=1;
    prime[0]=prime[1]=0;
    for (int i = 2; i <= lim; i++) if (prime[i]==1) {
        for (int j = i+i; j<= lim; j+=i) prime[j]=0;
    }
}

int count_div(int n){
    if (prime[n]) return 2;
    int cnt = 0;
    for (int i = 1; i * i <= n; i++){
        if (n % i == 0) {
            if (n/i==i) cnt++;
            else cnt+=2;
        }
    }
    return cnt;
}

int main(){
    crivo(MAX-5);
    for (int i = 2; i < MAX ; i++) hp[i]=prime[i];
    for (int i = 1; i*i < MAX; i++){
        if (prime[count_div(i*i)]) hp[i*i] = 1;
    }
    int n;
    dp[2] = 1;
    for (int i = 3; i < MAX; i++) dp[i] = dp[i-1] + (int)(hp[i]);
    while (cin >> n){
        cout << dp[n]  << endl;
    }
    exit(0);
}

// pescoço pra baixo é canela
// exercicio basicamente copiado da aula disponibilizada em 

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

const int MAX = 1.5e7 + 10;
int divi[MAX];

int gcd(int a, int b){
    while (b != 0){
        int aux = a;
        a = b;
        b = aux % b;
    }
    return a;
}

void crivo(){
    for (int i = 1; i <= MAX-5; i++) divi[i] = 1;
    for (int i = 2; i<=MAX-5;i++){
        if (divi[i] == 1){
            for (int j = i; j <=MAX-5; j+=i) divi[j] = i;
        }
    } 
}

vector<int> fact(int n){
    vector<int> ret;
    while (n>1){
        ret.pb(divi[n]);
        n/=divi[n];
    }
    return ret;
}

int main(){ _
    int n; cin >> n;
    vector<int> v(n);
    int d = 0;
    for (int &i: v) {
        cin >> i;
        d=gcd(d, i);
    }
    for (int &i: v) i/=d;
    crivo();
    map<int, int> primos_cnt;
    for (auto a: v){
        vector<int> primos = fact(a);
        if (!primos.empty()) primos_cnt[primos[0]]++;
        for (int i = 1; i < primos.size(); i++){
            if (primos[i] != primos[i-1]){
                primos_cnt[primos[i]]++;
            }
        }
    }
    int ans = n;
    for (auto [p, ci] : primos_cnt){
        ans=min(ans, n-ci);
    }
    if (ans==n) cout << -1 << endl;
    else cout << ans << endl;
    exit(0);
}

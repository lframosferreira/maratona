// pescoço pra baixo é canela
//
// OBS: questão basicamente copiada da aula de teoria dos números do canal da maratona da UFMG
// https://www.youtube.com/watch?v=EiEmhW8_Stw

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

const int MAX = 1e6+10;
const int MOD=1e9 + 7;

ll fat[MAX];

ll fexp(ll a, ll b){
    if (b==0) return 1;
    if (b%2==0) return fexp(a*a%MOD, b/2);
    return a * fexp(a, b-1)%MOD;
}

ll inv(ll x) {
    return fexp(x, MOD-2);
}

ll escolhe(int n, int i){
    return fat[n]*inv(fat[i]) % MOD * inv(fat[n-i]) % MOD;
}

int main(){ _
    fat[0] = 1;
    for (int i = 1; i < MAX; i++) fat [i] = i* fat[i-1] % MOD;
    int a, b, n; cin >> a >> b >> n;
    ll ans = 0;
    for (int i = 0; i <=n; i++){
        int cnt_a = i, cnt_b = n-i;
        ll soma = cnt_a*a + cnt_b*b;
        bool fmz = true;
        while (soma > 0){
            if (soma%10 != a and soma%10 != b) fmz=false;
            soma /=10;
        }
        if (fmz){
            ans = (ans + escolhe(n, i)) %MOD;
        }
    }
    cout << ans << endl;
    exit(0);
}

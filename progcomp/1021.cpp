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

const double LIM = 1e-6;

int main(){ _
    cout << fixed << setprecision(2);
    double n; cin >> n;
    for (double v: {100.0, 50.0, 20.0, 10.0, 5.0, 2.0, 1.0, 0.5, 0.25, 0.1, 0.05, 0.01}){
        int cnt = 0;
        while (n > v || abs(n-v) < LIM){
            cnt++;
            n -= v;
        }
        if (v == 100.0) cout << "NOTAS:" << endl;
        if (v == 1.00) cout << "MOEDAS:" << endl;
        cout << cnt << " " << (v > 1.5 ? "nota(s)" : "moeda(s)") << " de R$ " << v << endl;
    }
    exit(0);
}

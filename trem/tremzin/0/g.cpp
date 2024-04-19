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
typedef vector<double> vd;
typedef vector<vd> vdd;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    int n; cin >> n;
    vi v(n+1);
    for (int i = 1; i <= n; i++) cin >> v[i];    
    int il=v[1];
    int cnt=1;
    while (il !=2){
        if (il==1) {
            cnt=-1;
            break;
        }
        il=v[il]; 
        cnt++;
    }
    cout << cnt << endl;
    exit(0);
}

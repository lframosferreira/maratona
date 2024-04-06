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

int main(){ _
    int n; cin >> n;    
    vi v(n);
    ll soma=0;
    for (int &i : v){
        cin >> i;
        soma+=(ll)i;
    }
    if (soma%2==1){
        cout << "NO" << endl;exit(0);
    }
    sort(v.begin(), v.end());
    if (soma-v[n-1] >= v[n-1]) cout << "YES" << endl;
    else cout << "NO" << endl;
    exit(0);
}

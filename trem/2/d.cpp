
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
    string a, b, c;
    cin >> a >> b >> c;
    int ans=0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i] and a[i] != c[i] and b[i] != c[i]) ans+=2;
        else if (a[i] != b[i] or a[i] != c[i] or b[i] != c[i]) ans+=1;
    }
    cout << ans << endl;
    exit(0);
}


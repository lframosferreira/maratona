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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    int t; cin >> t;
    while (t--){
        int n, f, a, b;
        cin >> n >> f >> a >> b;
        vector<int> v(n);
        for (int &i: v) cin >> i;
        int prev = 0;
        bool impossible = false;
        for (int i = 0; i < n; i++){
            f-=min((ll)b, (ll)a * (ll)(v[i] - prev));
            prev = v[i];
            if (f <= 0){
                impossible=true;
                break;
            }
        }
        if (!impossible) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    exit(0);

}

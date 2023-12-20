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
    int n; cin >> n;
    vector<pii> v(n);
    for (int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        v[i] = {l,r};
    }
    sort(v.begin(), v.end(), [](auto a, auto b){
            if (a.s == b.s) return a.f < b.f;
            return a.s < b.s;
            });
    int ans = 0;
    int prev = -1;
    for (auto &p: v){
        if (p.f > prev){
            ans++;
            prev = p.s;
        } 
    }
    cout << ans << endl;
    exit(0);
}

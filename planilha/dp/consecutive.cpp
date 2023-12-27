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
    vector<ll> v(n);
    
    map<ll, int> hm;
    int ans = -INF;
    ll val;

    for (int i = 0; i < n; i++){
        cin >> v[i];
        ll curr = v[i];
        ll prev = v[i] - 1;
        hm[curr] = hm[prev] + 1;
        if (hm[curr] > ans){
            ans = hm[curr];
            val=curr;
        }
    }

    cout << ans << endl;
    vector<int> ind;

    for (int i = n-1; i >= 0;i--){
        if (ans==0) break;
        if (v[i] == val){
            ind.pb(i);
            ans--;
            val--;
        } 
    }
    for (int i = ind.size() -1; i >= 0;i--){
        cout << ind[i]+1 << " ";
    }
    cout <<endl;

    exit(0);
}

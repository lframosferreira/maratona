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
    int n, m; cin >> n >> m;
    vector<int> v(n);
    for (int &i: v) cin >> i;
    ll ans = 0;
    int prev = -INF;
    for (int i = 0; i < n; i++){
      if (min(v[i], m-v[i]) >= prev){
        ans += min(v[i],m-v[i]);
        prev = min(v[i], m-v[i]);
      }else if (max(v[i], m-v[i]) >= prev){
        ans += max(v[i],m-v[i]);
        prev = max(v[i], m-v[i]);
      }else {
        ans = -1; 
        break;
      } 
    }    
    cout << ans << endl;
    exit(0);
}

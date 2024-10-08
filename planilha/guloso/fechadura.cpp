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
    int l=0; int r=n-1;
    int idx = -1;
    int ans = 0;
    while (l <= r){
       if (l==m) idx = r;
       else if (r==m) idx = l;
       else idx = v[l] < v[r] ? l : r;
       ans += abs(m - v[idx]);
       if (idx==l) v[idx+1] += m - v[idx];
       else v[idx-1] += m - v[idx];
       v[idx] = m;
       if (idx==l)l++;
       else r--;
    }
    cout << ans << endl;
    exit(0);
}

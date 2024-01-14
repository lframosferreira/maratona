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
    vector<int> v(n);
    for (int &i : v) cin >> i;
    sort(v.begin(), v.end());
    int k; cin >> k;
    int a, b;
    while (k--){
       cin >> a >> b; 
       auto lb = lower_bound(v.begin(), v.end(), a);
       auto ub = upper_bound(v.begin(), v.end(), b);
       cout << ub - lb << " ";
    }
    cout << endl;
    exit(0);
}
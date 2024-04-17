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
    string p; cin >> p;
    
    vi dp1(p.size()+1);
    vi dp2(p.size()+1);
    for (int i = 0; i < p.size(); i++) {
        if (islower(p[i])) dp1[i+1]=dp1[i]+1;
        else dp1[i+1]=dp1[i];
    }
    for (int i = p.size()-1; i >=0; i--) {
        if (isupper(p[i])) dp2[i]=dp2[i+1]+1;
        else dp2[i]=dp2[i+1];
    }
    int ans=INF;
    for (int i = 0; i <= p.size(); i++) ans=min(ans, dp1[i]+dp2[i]);
    cout << ans << endl;
    exit(0);
}

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
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        string r, b; cin >> r >> b;
        vi vr, vb;
        for (int i = 0; i < n; i++){
            vr.pb(r[i]-'0');vb.pb(b[i]-'0');
        }
        int cnt_r=0, cnt_b=0;
        for (int i = 0; i < n; i++){
            if (vr[i]>vb[i]) cnt_r++;
            else if(vr[i]<vb[i]) cnt_b++;
            else {cnt_r++;cnt_b++;}
        }
        if (cnt_r==cnt_b) cout << "EQUAL" << endl;
        else if (cnt_r > cnt_b) cout << "RED" << endl;
        else cout << "BLUE" << endl;
    }    
    exit(0);
}

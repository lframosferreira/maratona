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
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<char> ans;

void pos_order(string pre, string in){
    char root = pre[0];
    int in_root_idx = -1;
    for (int i = 0; i < in.length(); i++) if (in[i] == root){
        in_root_idx = i;
        break;
    }
    if (in_root_idx != 0) pos_order(pre.substr(1, in_root_idx), in.substr(0, in_root_idx));  
    if (in_root_idx != in.length() - 1) pos_order(pre.substr(in_root_idx + 1, string::npos), in.substr(in_root_idx + 1, string::npos));  
    ans.pb(pre[0]);
}

int main(){ _
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        string pre, in; cin >> pre >> in;
        pos_order(pre, in);
        for (auto e: ans) cout << e;
        cout << endl;
        ans.clear();
    }
    exit(0);
}

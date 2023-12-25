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

const int MAX = 2e2 + 10;

unordered_map<string, vector<string>> nyt;
unordered_map<string, bool> vis;

void dfs(string a, string b){
    if (vis.count(a)) return;
    vis[a] = true;
    if (a == b) return;
    for (auto e: nyt[a]){
        dfs(e, b);
    }
}

int main(){ _
    int n, m; cin >> n >> m;
    for (int i = 0; i < n;i++){
       string a, x1, x2, x3, b;
       cin >> a >> x1 >> x2 >> x3 >> b;
       nyt[a].pb(b);
    }
    for (int i = 0; i < m;i++){
        string a, x1, x2, x3, b;
        cin >> a >> x1 >> x2 >> x3 >> b;
        vis.clear();
        dfs(a, b);
        if (vis.count(b)) {
            cout << "Fact" << endl;
        }
        else {
            vis.clear();
            dfs(b, a);
            if (vis.count(a)) {
                cout  << "Alternative Fact" << endl;
            }
            else cout << "Pants on Fire" << endl;
        }
    }

    
    exit(0);
}

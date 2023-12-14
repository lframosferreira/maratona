#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second
#define pb pushback()

typedef long long ll;
typedef pair<int , int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ 
    int n,m;
    cin >>n >>m;
    vector<bool> visited(n, false);
    vector<vector<int>> g(n+1);
    vector<vector<int>> paths;
    int a, b;
    while (m--){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    queue<pii> q;
    q.push({1, 0});
    int res = -1;
    while (!q.empty()){

        pii k = q.front();
        q.pop();
        visited[k.f] = true;
        if (k.f == n){
            res = k.s;
            break;
        }
        for (auto neigh : g[k.f]){
            if (!visited[neigh]){
                q.push({neigh, k.s + 1});
            }
        }

    }
    if (res == -1){
        cout << "IMPOSSIBLE\n" << endl;
    } else {
        cout << res + 1<< endl;
    }
    exit(0);
}

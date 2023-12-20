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
    int n, m, d; cin >> n >> m >> d;
    vector<int> plat(m);
    vector<int> ans(n+2);
    for (int &p: plat) cin >> p;
    if (d > n){
        cout << "YES" << endl;
        int c = 0;
        for (int &p: plat){
           for (int i = c; i <= c + p - 1; i++){
             ans[i] = p;
           }  
           c +=p;
        }
        for (int &a: ans) cout << a << " ";
        cout << endl;
        exit(0);
    }
    int idx = 0;
    int c = 1;
    for (int &p: plat){
        for (int i = idx + d; i <= idx + d + p - 1; i++){
           ans[i] = c;  
        }
        c++;
        idx+=d+p-1; 
    }
    idx +=d;
    if (idx > n){
        cout << "YES" << endl;
        for (int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
    exit(0);
}

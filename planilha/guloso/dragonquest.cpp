// pescoço pra baixo é canela

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int , int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    int t; cin >> t;
    while (t--){
        int x, n, m; cin >> x >> n >> m;
        while (n--){
            x = min(x, x/2 + 10);
        }    
        if (x-(m*10) <= 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    exit(0);
}

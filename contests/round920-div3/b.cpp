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
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        string s; cin >> s;
        string f; cin >> f;
        int x = 0;
        int y = 0;
        for (int i = 0; i < n; i++){
            if (s[i] == f[i]) continue;
            if (s[i] == '1') x++;
            else y++;
        }
        cout << max(x, y) << endl;
    }
    exit(0);
}

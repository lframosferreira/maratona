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
    int n, m, k; cin >> n >> m >> k;
    vector<string> s(n);
    int ans = 0;
    for (int i = 0; i < n; i++)
            cin >> s[i];
    if (k == 1){
        for (auto &x: s) ans += count(x.begin(), x.end(), '.');
        cout << ans << endl;
        exit(0);
    }
    for (int i = 0; i < n; i++){ 
        int l = 0; int r = k-1;
        bool bad = true;
        while (r < m){
            if (bad){
                for (int a = r; a >= l; a--){
                    if (s[i][a] == '*'){
                        bad = true;
                        l = a+1;
                        r=l+k-1;
                        break;
                    }
                    bad = false;
                }
            } else {
                ans++;
                l++;r++;
                if (r==m) break;
                if (s[i][r] == '*'){
                    l = r+1;
                    r=l+k-1;
                    bad = true;
                }
            }
        }
    }
    
    for (int j = 0; j < m; j++){ 
        int l = 0; int r = k-1;
        bool bad = true;
        while (r < n){
            if (bad){
                for (int a = r; a >= l; a--){
                    if (s[a][j] == '*'){
                        bad = true;
                        l = a+1;
                        r=l+k-1;
                        break;
                    }
                    bad = false;
                }
            } else {
                ans++;
                l++;r++;
                if (r==n) break;
                if (s[r][j] == '*'){
                    l = r+1;
                    r=l+k-1;
                    bad = true;
                }
            }
        }
    }
    cout << ans << endl;
    exit(0);
}

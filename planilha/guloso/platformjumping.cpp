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

int main(){ 
    int n, m, d; cin >> n >> m >> d;
    vector<int> plat(m);
    vector<int> ans(n+2);
    int plat_count = 0;
    for (int &p: plat){
        cin >> p;
        plat_count+=p;
    }
    int idx = 0;
    for (int i = 0; i < m; i++){
        int p = plat[i];
        int pos_idx = idx + d + p - 1;
        int diff = n - pos_idx - (plat_count-p);
        if (diff >= 0){
            plat_count -= p;
            idx += min(n, pos_idx);
        } else {
            if (abs(diff) > d){
                cout << "NO" << endl;
                exit(0);
            }else {
                plat_count -= p;
                idx += min(n, pos_idx - abs(diff));
            }
        }
        for (int j = idx; j < idx+p; j++){
            ans[j] = i+1;
        }
        idx+=p-1;
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
    exit(0);
}

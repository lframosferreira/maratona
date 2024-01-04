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

int max_idx(vector<int> v){
    int idx = 0;
    int mxn = v[idx];
    for (int i = 1;i < v.size(); i++){
        if (v[i] > mxn){
            mxn = v[i];
            idx=i;
        }
    }
    return idx;
}

int main(){ _
    int n; cin >> n;
    vector<int> v(n);
    for (int &i: v) cin >> i;
    int ans = -INF;
    for (int i = 0; i < n - 1; i++){
        int h = 0;
        int idx = i;
        bool can;
        while (idx < n and v[idx] > h){
            h++;
            idx++;
        }
        while (h){
            can=true;
            if (ans > h) break;
            if (i + h - 1 + h - 1 >= n){
                h--;
                continue;
            }
            int aux = h-1;
            for (int j = i+h-1; j < i+2*h-2;j++){
                if (v[j+1] < aux){
                    can = false;
                    break;
                } 
                aux--;
            }
            if (!can) h--;
            else break;
        }
        ans=max(ans, h);
    }
    cout << ans << endl;
    exit(0);
}

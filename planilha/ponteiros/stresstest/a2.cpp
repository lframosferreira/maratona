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
    int n; cin >> n;
    vector<int> v(n);
    vector<int> ans(n+1);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }  
    for (int i = 0; i < n; i++){
       vector<bool> valid(n, true);
        for (int j = i; j < n; j++){
            if (v[j] > 0){
                if (valid[v[j]]){
                    ans[i]++;
                } else {
                    break;
                }
            }else {
                ans[i]++;
                valid[abs(v[j])] = false;
            } 
        }
    } 
    for (int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    exit(0);
}

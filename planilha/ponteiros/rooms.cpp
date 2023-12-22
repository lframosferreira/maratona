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
    vector<int> count(n+1, 1);
    vector<int> ans(n+1);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }  
    int l = 0;
    int r = 0;
    while (l < n){
        if (r == n){
            if(v[l] < 0) count[abs(v[l])]++;
            ans[l+1]=ans[l] - 1;
            l++;
            continue; 
        }
        int curr = v[r];
        if (curr > 0){
            if (count[abs(curr)] > 0){
                ans[l]++;
                r++;
            } else {
                if(v[l] < 0) count[abs(v[l])]++;
                ans[l+1]=ans[l] - 1;
                l++;
            }
        } else {
            count[abs(curr)]--;
            ans[l]++;
            r++;
        }
    } 
    for (int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    exit(0);
}

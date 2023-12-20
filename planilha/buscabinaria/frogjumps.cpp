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
    string s;
    while (t--){
       cin >> s;
       int ans = -INF;
       int prev = -1;
       for (int i = 0; i < s.length(); i++){
            if (s[i] == 'R'){
                ans = max(ans, i-prev);
                prev=i;
            } 
       }
       ans = max(ans, (int)s.length()-prev);
       cout << ans << endl;
    }    
    exit(0);
}

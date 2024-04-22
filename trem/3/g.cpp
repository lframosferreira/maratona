// pescoço pra baixo é canela

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int , int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<vd> vdd;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vi v(n); for (int &i: v) cin >> i;
        int ans=-1;
        for (int i = 0; i < n; i++){
            int l = i-1,r=i+1;
            int val=v[i];
            if (ans!=-1) break;
            while (1){
                if (l<0 and r >= n){
                    ans=i;
                    break;
                }
                if (l >= 0 and val > v[l]){
                    l--;
                    val+=1;
                    continue;
                }
                if (r < n and val > v[r]){
                    r++;
                    val+=1;
                    continue;
                }
                break; 
            } 
        }
        cout << (ans == -1 ? ans : ans+1) << endl;
    }    
    exit(0);
}

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
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    int m; string txt;
    while (1){
        cin >>m;
        if(m==0)break;
        getline(cin, txt);
        getline(cin, txt);
        vector<int> v(150);
        int cnt=0;
        int ans=-INF;
        int l = 0;
        int r = 0;
        while (l < txt.length()-m){
            if (cnt > m || r==txt.length()){
                int idx=(int)txt[l];
                v[idx]--;
                if (!v[idx])cnt--;
                l++;
            }else {
                int idx=(int)txt[r];
                if (!v[idx]) cnt++;
                v[idx]++;
                if (r < txt.length()) r++;
            }
            if (cnt<=m) ans=max(ans, r-l);
        }
        cout << max(0, ans) << endl;
    }
    exit(0);
}

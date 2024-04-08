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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    int t; cin >> t;
    while (t--){
    int n;ll k; cin >> n >> k;
        vi v(n); for (int &i : v) cin >> i;
        int cnt=0;
        ll val2=k/2LL;  
        ll val1=k/2LL + (k%2);  
        int idx1=-1;
        int idx2=n;
        for (int i = 0; i < n; i++){
            if (v[i] <= val1){
                cnt++;
                val1-=v[i];
                idx1=i;
            } else{
                idx1=i;
                break;
            }
        }
        for (int i = n-1; i >= 0; i--){
            if (v[i] <= val2){
                cnt++;
                val2-=v[i];
                idx2=i;
            } else{
                idx2=i;
                break;
            }

        }
        cout << (idx2 == idx1? n - (val1+val2 < v[idx1]) : (idx2 < idx1 ? n : cnt)) << endl;
    }
    exit(0);
}

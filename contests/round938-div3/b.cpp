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
    int t;cin>>t;
    while (t--){
        int n, c, d; cin >> n >> c >> d;
        vi nums;
        for (int i = 0; i < n*n; i++) {
            int val; cin >> val;
            nums.pb(val);
        }
        sort(nums.begin(), nums.end());
        int a11=nums[0];
        vvi v(n, vi(n));
        int a11=v[0][0];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i==j) continue;
                if (i-1 >= 0) v[i
                
            }
        }

    }
    exit(0);
}

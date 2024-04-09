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

const int MAX = 5e3 + 10;
int dp[MAX][MAX];

int main(){ _
    string a, b;
    cin >> a >> b;
    memset(dp, 0, sizeof dp);    
    for (int i = a.size()-1; i>=0; i--){
        for (int j = b.size()-1; j >= 0; j--){
            if (a[i]==b[j]){
                dp[i][j]=dp[i+1][j+1]+1;
            } else {
                dp[i][j]=max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    cout << dp[0][0] << endl;
    exit(0);
}

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
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    while (1){
        int N; cin >> N;
        if (N==0) break;
        vector<int> v(2*N);
        for (int &i: v) cin >> i;
        vector<vector<int>> dp(2*N, vector<int>(2*N));
        for (int i = 0; i < 2*N; i++) dp[i][i]=0;
        for (int j = 0; j < 2*N; j++){
            for (int i = j; i >= 0; i--){ 
                if (i==j){
                    dp[i][j]=0;
                    continue;
                }
                int myturn = (i-j+1)%2==0; 
                int a=dp[i+1][j] + (v[i]%2==0) * myturn; 
                int b=dp[i][j-1] + (v[j]%2==0) * myturn; 
                dp[i][j]= myturn ? max(a, b) : min(a, b);
            }
        }
        cout << dp[0][2*N-1] << endl;
    }
    exit(0);
}

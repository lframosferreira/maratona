    // pescoço pra baixo é canela
     
    #include <bits/stdc++.h>
     
    using namespace std;
     
    #define _ ios_base::sync_with_stdio(0);cin.tie(0);
    #define endl '\n'
    #define sz(v) (int)v.size()
    #define f first
    #define s second
    #define pb push_back
    #define eb emplace_back
    #define mp make_pair
    #define bs bitset
    #define umap unordered_map
    #define uset unordered_set
    #define all(v) begin(v), end(v)
    #define rall(v) rbegin(v), rend(v)
     
    #define dbg(x) cout << #x << " = " << x << endl
     
    typedef long long ll;
    typedef pair<int , int> ii;
    typedef tuple<int, int, int> iii;
    typedef vector<int> vi;
    typedef vector<vi> vvi;
    typedef vector<ll> vll;
    typedef vector<vll> vvll;
    typedef vector<double> vd;
    typedef vector<vd> vvd;
     
    const int INF = 0x3f3f3f3f;
    const ll LINF = 0x3f3f3f3f3f3f3f3fll;
     
    const int MAX = 2010;
    string v[MAX];
    int dp[MAX][MAX];
     
    int main(){ _ 
        int n, m; cin >> n >> m;
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < n; i++){
            cin >> v[i];
        } 
        // de cima é 1 da esquerda é 0, inicial é -1
        dp[0][0]=-1;
        for (int i = 1; i < m; i++) dp[0][i]=0;
        for (int i = 1; i < n; i++) dp[i][0]=1;
        for (int i = 1; i < n; i++){
            for (int j = 1; j < m; j++){
                if (v[i-1][j]==v[i][j-1]){
                    int a1=i-1,a2=i,b1=j,b2=j-1;
                    while (v[a1][b1]==v[a2][b2]){
                        if (dp[a1][b1]==1) a1--;
                        else b1--; 
                        if (dp[a2][b2]==1) a2--;
                        else b2--;
                        if (dp[a1][b1]==-1) break;
                    } 
                    if (v[a1][b1] < v[a2][b2]) dp[i][j]=1;
                    else dp[i][j]=0; 

                    continue;
                }
                if (v[i-1][j] < v[i][j-1]) dp[i][j]=1;
                else dp[i][j]=0; 
            }
        }
        vector<char> ans;
        int i = n-1,j=m-1;
        while (dp[i][j] != -1){
            ans.pb(v[i][j]);
            if (dp[i][j]==1) i--;
            else j--;
        }
        ans.pb(v[0][0]);
        for (int idx = sz(ans)-1; idx >=0; idx--) cout << ans[idx];
        cout << endl;
        exit(0);
    }

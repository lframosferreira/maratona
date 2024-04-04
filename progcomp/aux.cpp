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

const int MAX = 110;

struct subp {
    int val;
    int cnt_null;
    int cnt_neg;
    bool calc;

    bool operator < (const subp &other) const{
        if (val==other.val) return cnt_null < other.cnt_null;
        return val < other.val;
    }
};

int v[MAX][MAX];
subp dp[MAX][MAX];

int N, M, X, Y;

void reset_dp(){
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            dp[i][j]=subp{INF, 0, 0};
}

void print_dp(){
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            cout << dp[i][j].val << " ";
        }
        cout << endl;
    }
}

int solve(int i, int j){
    if (dp[i][j].calc) return dp[i][j].val;
    subp a={INF,0,0,false}, b={INF,0,0,false}, c={INF, 0,0,false};
    if (i+1 <= M){
        if (v[i+1][j] == 0 and dp[i][j].cnt_null+1<=X){
            auto aux = subp{dp[i][j].val + v[i+1][j], dp[i][j].cnt_null+1, dp[i][j].cnt_neg};
            a =dp[i+1][j];
        }
        if (v[i+1][j] < 0 and dp[i][j].cnt_neg+1<=Y){
            auto aux = subp{dp[i][j].val + v[i+1][j], dp[i][j].cnt_null, dp[i][j].cnt_neg+1};
            a=dp[i+1][j];
        }
        if (v[i+1][j] > 0) {
            auto aux = subp{dp[i][j].val + v[i+1][j], dp[i][j].cnt_null, dp[i][j].cnt_neg};
            a=dp[i+1][j];
        }
    }
    // i, j+1
    if (j+1 <= N){
        if (v[i][j+1] == 0 and dp[i][j].cnt_null+1<=X){
            auto aux = subp{dp[i][j].val + v[i][j+1], dp[i][j].cnt_null+1, dp[i][j].cnt_neg};
            b=dp[i][j+1];
        }
        if (v[i][j+1] < 0 and dp[i][j].cnt_neg+1<=Y){
            auto aux = subp{dp[i][j].val + v[i][j+1], dp[i][j].cnt_null, dp[i][j].cnt_neg+1};
            b=dp[i][j+1];
        }
        if (v[i][j+1] > 0) {
            auto aux = subp{dp[i][j].val + v[i][j+1], dp[i][j].cnt_null, dp[i][j].cnt_neg};
            b=dp[i][j+1];
        }
    }
    // i, j-1
    if (j-1 >= 1){
        if (v[i][j-1] == 0 and dp[i][j].cnt_null+1<=X){
            auto aux = subp{dp[i][j].val + v[i][j-1], dp[i][j].cnt_null+1, dp[i][j].cnt_neg};
            c=dp[i][j-1];
        }
        if (v[i][j-1] < 0 and dp[i][j].cnt_neg+1<=Y){
            auto aux = subp{dp[i][j].val + v[i][j-1], dp[i][j].cnt_null, dp[i][j].cnt_neg+1};
            c=dp[i][j-1];
        }
        if (v[i][j-1] > 0) {
            auto aux = subp{dp[i][j].val + v[i][j-1], dp[i][j].cnt_null, dp[i][j].cnt_neg};
            c=dp[i][j-1];
        }
    }
    dp[i][j].calc=true;
    dp[i][j]=min({a, b, c});
    return dp[i][j].val;

}

int main(){ _
    while (cin >> N >> M >> X >> Y){
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                cin >> v[i][j];
        reset_dp();
        dp[1][1] = subp{v[1][1], v[1][1] == 0, v[1][1] < 0, true};
        solve(N, M);
        print_dp();
    }
    exit(0);
}

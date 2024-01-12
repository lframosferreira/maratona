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

const int MOD = 1e9 + 7;

struct Matrix {
    ll m[2][2]; 
    Matrix operator * (const Matrix &other){
        Matrix ret{{{0, 0}, {0,0}}};
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 2; j++){
                for (int k = 0; k < 2; k++){
                    ret.m[i][k] += m[i][j] * other.m[j][k];
                    ret.m[i][k]%= MOD;
                }
            }
        }
        return ret;
    }
};

int main(){ _
    ll n; cin >> n;
    Matrix base{{{0,1}, {1,1}}};
    Matrix ans{{{0,1}, {1,1}}};
    while (n){
        if (n % 2 == 1){
            ans = ans * base;
        }
        base=base*base;
        n /=2;
    }
    cout << ans.m[0][0] << endl;
    exit(0);
}

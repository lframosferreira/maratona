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
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        vector<int> weights(N+1);
        for (int i = 1; i <= N; i++) cin >> weights[i];
        int wa=0,wb=0;
        bool can=true;
        for (int i=1; i <=N;i++){
            if (abs((weights[i]+wa)-wb) > 5){
                wb+=weights[i];
            }else {
                wa+=weights[i];
            }
            if(abs(wa-wb) > 5){
                can=false;break;
            }
        }
        if (can) cout << "Feliz Natal!" << endl;
        else cout << "Ho Ho Ho!" << endl;
    }
    exit(0);
}

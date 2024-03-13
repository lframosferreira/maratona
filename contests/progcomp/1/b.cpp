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
    int n; cin >> n;
    vector<int> v(n);
    for (int &i: v) {
        cin >> i;
    }
    int ans = INF;
    int ans_m=-1;
    for (int m = 1; m <= 100; m++){
        int cost=0;
        for (int i : v){
            if(abs(i-m)<=1) continue;
            cost+=abs(i-m)-1; 
        }
        if (cost < ans){
            ans=cost;
            ans_m=m;
        }
    }
    cout << ans_m << " " << ans << endl;
    exit(0);
}

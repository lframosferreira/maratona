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

void pv(vi v){for (int i: v) cout << i << " "; cout << endl;}

int solve(vi &v, vi &w){
    if (v==w) return 1;
    if (v.size()==w.size()) return 0;
    int b=0;
    for (int i = 1; i < v.size(); i++){
        vi aux(v.begin()+i, v.end());
        reverse(aux.begin(), aux.end());
        for (int j = 0; j < i; j++){
            aux[aux.size()-j-1]+=v[j];
        }
        vi rev(aux.rbegin(), aux.rend());
        b = b || (solve(aux, w) || solve(rev, w));
    }
    return  b;
}

int main(){ _
    int N, M;
    while (cin >> N){
        vector<int> v(N);
        for (int &i : v) cin >> i;
        cin >> M;
        vector<int> w(M);
        for (int &i : w) cin >> i;
        if (solve(v, w)) cout << "S" << endl;
        else cout << "N" << endl;    
    }
    exit(0);
}

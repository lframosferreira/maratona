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

vector<double> v;

bool valid(double d, int k){
    int cnt = 0; 
    for (auto rope: v){
        double aux = d;
        while (aux < rope){
            aux+=d;
            cnt++;
            if (cnt==k) return true;
        }
    }
    return false;
}

int main(){ _
    cout << fixed << setprecision(10);
    int n, k; cin >> n >> k;
    double eps = 1e-9;
    v.resize(n);
    for (auto &d: v) cin >> d;
    sort(v.begin(), v.end());
    double l = 0; double r = v[n-1];
    double m;
    while (r-l > eps){
        m = (l+r)/2;
        if (valid(m, k)) l = m;
        else r = m;
    }
    cout << m << endl;
    exit(0);
}

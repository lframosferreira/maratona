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

int main(){ _ 
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector<int> a(n), b(m);
        for (int &i: a) cin >> i;
        for (int &i: b) cin >> i;
        ll D = 0;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<int>());
        int l = 0;
        int ra = n-1;
        int rb = m-1;
        for (int i = 0; i < n; i++) {
            int esq = abs(a[l] - b[l]);
            int dir = abs(a[ra] - b[rb]);
            if (esq > dir){
                D += esq;
                l++;
            } else {
                D += dir;
                ra--;rb--;
            }
        }
        cout << D << endl;
    }
    exit(0);
}

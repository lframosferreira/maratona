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
        int x, y;
        cin >> x >> y;
        int l = x;
        int r;
        int aux = y;
        for (int i = 0; i < 3; i++){
            cin >> x >> y;
            if (y==aux) r = x;
        } 
        cout << abs(l-r) * abs(l-r) << endl;
    }
    exit(0);
}

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

const int MAX = 20 + 1;
ll fact[MAX];

ll escolhe(int n, int m) {
    return fact[n] / (fact[m] * fact[n-m]);
}

int main(){ _
    fact[0] = 1;
    for (int i = 1; i < MAX; i++) fact[i] = fact[i-1] * (ll)i;
    fstream f;
    f.open("popcorn.in");
    int t; f >> t;
    while (t--){
        int n, m; f >> n >> m;
        cout << escolhe(n, m) << endl;
    }
    f.close();
    exit(0);
}

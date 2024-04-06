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

int a, b;

int checa(int x){
    int cnt=0;
    for (int i = x; i <= b; i+=x){
        if (i>=a && i <= b) cnt++;
    }
    if (cnt>=2) return 1;
    return 0;
}

int main(){ _
    cin >> a >> b;
    a=min(a,b);b=max(a,b);
    int l = 1;int r = b-a;
    int ans=-INF;
    for (int m = 1; m <= b; m++)
        if (checa(m)){
            ans=max(ans, m);
    }
    cout << ans << endl;
    exit(0);
}


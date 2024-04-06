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

void print(const vi &v){
    for (int i: v) cout << i <<  " ";
    cout << endl;
}

int main(){
    int n; cin >> n;
    string txt; cin >> txt;
    vi black(n+1);
    vi white(n+1);    
    black[0]=0;
    for (int i = 1; i <= n; i++) black[i]=black[i-1]+(txt[i-1]=='#');
    white[n]=0;
    for (int i = n-1;i >=0;i--) white[i]=white[i+1]+(txt[i]=='.');
    int ans=INF;
    for (int i = 0; i <= n; i++) ans=min(ans, black[i] + white[i]);
    cout << ans << endl;
    exit(0);
}

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
    int n, k; cin >> n >> k;
    vector<int> nece(n);
    for (int &i : nece) cin >> i;
    vector<int> disp(n);    
    for (int &i : disp) cin >> i;
    int ans=0;
    int mn=-INF; 
    for (int i = 0; i < n; i++){
        mn=min(mn, disp[i]/nece[i]); 
    }
    ans+=mn; 
    while (k>0){
          
    }
    exit(0);
}

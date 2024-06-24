// pescoço pra baixo é canela

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define sz(v) (int)v.size()
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define umap unordered_map
#define uset unordered_set
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int , int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<double> vd;
typedef vector<vd> vvd;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e6+10;
ull d[MAX];
ull divi[MAX];

void crivo(){
   for (ull i = 1; i < MAX; i++) divi[i]=1;
   for (ull i = 2; i < MAX  ; i++){
    if (divi[i]==1) for (ull j = i; j < MAX; j+=i){
        divi[j]=i;
    }
   }
}

int main(){ _
    ull n;
    crivo();
    d[1]=1;
    d[2]=3;
    d[3]=4;
    for (ull i = 4; i < MAX; i++){
        if (divi[i]==i) d[i]=i+1;
        else d[i] = d[i/divi[i]] + i;
    }
    for (ull i = 2; i < MAX; i++) d[i]+=d[i-1];
    while (true){
        cin >> n;
        if (n==0) break;
        cout << d[n] << endl;
    }    
    exit(0);
}

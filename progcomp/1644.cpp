// pescoço pra baixo é canela

#include <bits/stdc++.h>
#include <string>

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

int main(){ 
    ll n, m;
    for (;;){
        cin >> n >> m;
        if (!n and !m) break;
        vi perm(n+1);
        vi marked(n+1);
        for (int i = 1;i <=n;i++) cin >> perm[i];
        string txt;
        cin.get();
        getline(cin, txt);
        txt="$"+txt;
        for (int i = 1; i <=n;i++){
            if (marked[i]) continue;
            vi aux;
            marked[i]=1;
            int j=i;
            aux.pb(i);
            while (perm[j]!=i) {
                j=perm[j];
                marked[j]=1;
                aux.pb(j);
            } 
            int r=m%sz(aux);
            if (!r) continue;
            string txt2=txt;
            for (int f=0; f < sz(aux);f++) txt[aux[f]] =txt2[aux[f-r>=0?f-r:sz(aux)+(f-r)]];
        } 
        string ans=txt.substr(1, string::npos);
        cout << ans << endl;
    }
    exit(0);
}

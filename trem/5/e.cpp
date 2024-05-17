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
#define bs bitset
#define umap unordered_map
#define uset unordered_set
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
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

int main(){ _
    int t; cin >> t;
    while (t--){
        int n, k; cin >> n >> k;
        string inst; cin >> inst;
        ii pos=mp(0,0);
        int mx=-INF;
        ii aux=mp(0,0);
        for (auto& c: inst){
            switch(c){
                case 'L':
                    pos.f--;
                    break;
                case 'R':
                    pos.f++;
                    break;
                case 'U':
                    pos.s++;
                    break;
                case 'D':
                    pos.s--;
                    break;
                }
            if (abs(pos.f)+abs(pos.s) > mx){
                mx=abs(pos.f)+abs(pos.s);
                aux=pos;
            }
        }
        
        int d =abs(pos.f)+abs(pos.s);d*=k;
        d+= abs(pos.f-aux.f)+abs(aux.s-pos.s);
        cout << d << endl;
    }    
    exit(0);
}

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

const int MAX = 6000;

int divi[MAX];
vi primos;

void sieve(){
    for (int i=1;i <MAX;i++) divi[i]=1;
    for (int i = 2; i*i<MAX; i++){
        if (divi[i]==1){
            primos.pb(i);
            for (int j = i*i; j< MAX; j+=i) {
                divi[j]=i;
            }
        }
    }
}

int main(){ _
    sieve();
    int n;
    while (1){
        cin >> n;
        if (n==0) break;
        list<int> l(n);
        iota(all(l), 1);
        int pos=-1;
        for (auto &idx: primos){
            if (sz(l) ==1)break;
            pos=(pos+idx)%sz(l);
            l.erase(next(l.begin(),pos)); 
            pos--;
        } 
        cout << *l.begin() << endl;
    } 
    exit(0);
}

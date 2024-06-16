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

int x, y;
int oob(int i, int j){
    return i < 0 or i >= y or j <0 or j >= x;
}

int main(){ _
    cin >> x >> y; 
    vector<vector<char>> v(y, vector<char>(x));
    for (int i = 0; i < y;i++){ 
        for (int j = 0;j< x;j++){
            cin >> v[i][j];
        }
    }
    vvi vis(y, vi(x));  
    if (v[0][0] == '.'){
        cout << "!"<< endl;
        exit(0);
    }
    int a=0,b=0;
    ii dir= {0, 0};
    while (1){
        if (oob(a, b)){
            cout << "!" <<endl;
            break;
        }
        if (vis[a][b]){
            cout << "!"<<endl;
            break;
        }
        vis[a][b]=1;
        if (v[a][b] == '*'){
            cout << "*"<< endl;
            break;
        }
        if (v[a][b]=='.'){
            a+=dir.f;
            b+=dir.s;
            continue;
        }
        if (v[a][b]=='>'){
            dir.f=0;
            dir.s=1;
        }
        if (v[a][b]=='<'){
            dir.f=0;
            dir.s=-1;
        }
        if (v[a][b]=='v'){
            dir.f=1;
            dir.s=0;
        }
        if (v[a][b]=='^'){
            dir.f=-1;
            dir.s=0;
        }
        a+=dir.f;
        b+=dir.s;
    }
    exit(0);
}

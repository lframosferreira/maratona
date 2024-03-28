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

int main(){ _
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vvi v(2*n, vi(2*n));
        for (int i =0; i < 2*n; i+=4){
           for (int j = 0; j < 2*n; j+=4){
                v[i][j]=1;
                v[i][j+1]=1;
                v[i+1][j]=1;
                v[i+1][j+1]=1;
            } 
        }
        for (int i =2; i < 2*n; i+=4){
           for (int j = 2; j < 2*n; j+=4){
                v[i][j]=1;
                v[i][j+1]=1;
                v[i+1][j]=1;
                v[i+1][j+1]=1;
            } 
        }
        for (int i = 0; i < 2*n; i++){
            for (int j = 0; j < 2*n; j++){
                cout << (v[i][j] ? '#' : '.');
            }
            cout << endl;
        } 
    }
    exit(0);
}

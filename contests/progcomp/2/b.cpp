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
    int n; cin >> n;
    vector<int> v(n);
    for (int &i: v) cin >> i;
    sort(v.begin(), v.end());
    int y = v.back();
    int x;
    set<int> aux;
    aux.insert(y);
    for (int i=n-2; i >=0; i--){
        if (y%v[i]==0){
            if (aux.find(v[i]) != aux.end()) {
                x=v[i];
                break;
            }
            aux.insert(v[i]);
        } else {
            x=v[i];
            break;
        }
    }
    cout << x << " " << y << endl;
    exit(0);
}
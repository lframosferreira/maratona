// pescoço pra baixo é canela

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int , int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    string cifra; cin >> cifra;
    string crib; cin >> crib;
    int ans = 0;
    for (int i = 0; i < cifra.length() - crib.length() + 1; i++){
        bool pos = true;
        for (int j = 0; j < crib.length(); j++){
            if (cifra[i+j]==crib[j]){
                pos=false;
                break;
            } 
        }
        if (pos) ans++;
    }
    cout << ans << endl;
    exit(0);
}

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
    char c[3] = {'R', 'G', 'B'};
    map<char, int> mp;
    mp['R']=0;
    mp['G']=1;
    mp['B']=2;
    string colors; cin >> colors;
    int ans=0;
    for (int i = 0; i < n-1; i++){
        if (colors[i] == colors[i+1]){
           for (int j = 0; j < 3; j++){
                if (c[j] != colors[i] and (i + 2 < n or i==n-2) and c[j] != colors[i+2]){
                    colors[i+1]=c[j];
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    cout << colors << endl;
    exit(0);
}

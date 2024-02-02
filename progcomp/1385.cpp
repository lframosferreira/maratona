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
typedef vector<vi> vvi;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    int C; cin >> C;
    while (C--){
        vvi vals(4);
        string line; cin >> line;
        // header
        int i = 1;
        int vend=0;
        while (isdigit(line[i])){
            cout << line.substr(i-1, 2) << " ";
            i+=2;
            vend++;
        }
        cout << line.substr(i-1, string::npos) << endl;;
        while (1){
            cin >> line;
            if (line[0] == 'T' and line[1] == 'P'){
                cout << "TP ";
                // cout sum cols
                break;
            }
            i = 0;
            while (!isdigit(line[i])) i++;
            cout << line.substr(0, i) << " ";
            string nums = line.substr(i, string::npos);
            vector<int> n(vend+1);
            while (1){
                int prev = 0;
                for (int s = 1; s < vend+1; s++){
                    for (int m = 1; m < 4; m++){
                        n[s] = stoi(nums.substr(prev, m));
                        prev = m;
                    }
                }
                if (accumulate(n.begin()+1, n.begin()+vend, 0) == n[vend]) break;
            }
            cout << n[1] << " " << n[2] << " " << n[3] << " " << n[4] << endl;
        } 
    }
    exit(0);
}

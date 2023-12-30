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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    string s; cin >> s;
    bool first = true;
    while (s.length()){
        bool can = false;
        for (int i = 0; i < s.length() - 1; i++){
            if (s[i] == s[i+1]){
                s.erase(i, 2);
                first=!first;
                can=true;
                break;
            }
        }
        if (!can){
            break;
        }
    }
    if (first) cout << "No" << endl;
    else cout << "Yes" << endl;
    exit(0);
}

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
    int n; cin >> n;
    string name;
    stack<string> st;
    set<string> s;
    while (n--){
       cin >> name;
       st.push(name);
       s.insert(name);
    }
    int k = st.size(); 
    for (int i = 0; i < k; i++){
        name = st.top();
        if (s.count(name) == 1){
            cout << name << endl;
            s.erase(name);
        }
        st.pop();
    }
    exit(0);
}

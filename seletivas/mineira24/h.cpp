// pescoço pra baixo é canela

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define bs bitset
#define umap unordered_map
#define uset unordered_set
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int , int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<vd> vdd;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 3e5 + 10;

int main(){ _
    int n; cin >> n;
    
    ll ans=0;
    int nxt=1;
    int last;
    priority_queue<int, vector<int>, greater<int>> pq;
    stack<int> st;
    bool ord=true;
    for (int i = 0; i < 2*n; i++){
       string com; cin >> com;
       int a;
       while (st.size() and st.top() < nxt) st.pop();
       if (com=="add"){
           cin >> a; 
           if (a > last) ord=false;
           last=a;
           pq.push(a);
           st.push(a);
       }else{
           if (last!=nxt){
               ans++;
               ord=true;
               pq.pop();
               last=pq.top();
           }else {
               pq.pop();
               if (ord) last = pq.top();
               else{
                   st.pop();
                   last = st.size() ? st.top() : -1;
               }
               
           }
           nxt++;
       }

    }    
    cout << ans << endl;
    exit(0);
}

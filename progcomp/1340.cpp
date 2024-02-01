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
    int n;
    while (cin >> n){
        int is_stack = 1;
        int is_queue = 1;
        int is_pq = 1;
        stack<int> st;
        priority_queue<int> pq;
        queue<int> q;
        while (n--){
            int c, x;
            cin >> c >> x;
            if (c==1){
                if (is_stack) st.push(x);
                if (is_pq) pq.push(x);
                if (is_queue) q.push(x);
            } else {
                int aux;
                if (is_stack) {
                    aux = st.top();
                    st.pop();
                    if (aux != x) is_stack = 0;
                }
                if (is_queue){
                    aux = q.front();
                    q.pop();
                    if (aux != x) is_queue = 0;
                }
                if (is_pq){
                    aux = pq.top();
                    pq.pop();
                    if (aux != x) is_pq = 0;
                }
            }
        }
        if (!is_stack and !is_queue and !is_pq){
            cout << "impossible" << endl;
        }
        if (is_stack + is_queue + is_pq > 1){
            cout << "not sure" << endl;
        }
        else {
            if (is_stack) cout << "stack" << endl;
            if (is_queue) cout << "queue" << endl;
            if (is_pq) cout << "priority queue" << endl;
        }
    }
    exit(0);
}

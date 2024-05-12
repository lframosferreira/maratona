// pescoço pra baixo é canela

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define sz(v)  (int)v.size()

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int , int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<vd> vvd;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 110;

int N, M;
int g[MAX][MAX];
int is_in_A[MAX];
int w[MAX];
int rm[MAX];
int ajuda[MAX][MAX];

stack<tuple<int, int, int>> edges;

int ans, size_V;

int minimum_cut_phase(){
    memset(is_in_A, 0, sizeof is_in_A);
    memset(w, 0, sizeof w);
    is_in_A[1]=1;
    vi A = {1};
    int cnt=1;
    int ret=0;
    priority_queue<ii> pq;
    for (int i = 1; i <= N; i++) if (!rm[i] and g[1][i]){
        w[i]=g[1][i];
        pq.push(mp(w[i], i)); 
    }
    while (cnt != size_V){
        auto [we, nxt] = pq.top();pq.pop();
        if (is_in_A[nxt] or rm[nxt]) continue;
        is_in_A[nxt]=1;
        A.pb(nxt);
        for (int i = 1; i <=N; i++) {
            if (!rm[i] and !is_in_A[i] and g[nxt][i]) {
                w[i]+=g[nxt][i];
                pq.push(mp(w[i],i));
            }
        }
        cnt++;
    }
    ret = w[A.back()];
    int p1=A[sz(A)-2]; 
    int p2=A[sz(A)-1]; 
    g[p1][p2] = 0;
    g[p2][p1] = 0;
    for (int i = 1; i <= N;i++){
        if (!rm[i] and g[p1][i] and g[p2][i]){
            g[p1][i]+=g[p2][i];
            g[i][p1]+=g[p2][i];
        }
        else if (!rm[i] and g[p2][i]){
            g[p1][i]=g[p2][i];
            g[i][p1]=g[p2][i];
        }
    }
    rm[p2]=1;
    return ret;
}

int main(){ _
    int t; cin >> t;
    while (t--){
        cin >> N >> M;
        memset(g,0, sizeof g);
        for (int i = 0; i < M; i++){
            int u, v, c; cin >> u >> v >> c;
            edges.push({u,v,c});
        }
        int min_edg=INF;
        while (!edges.empty()){
            auto [u, v, c] = edges.top();edges.pop();
            if(g[u][v] or g[v][u]) continue;
            min_edg=min(min_edg, c);
            g[u][v]=c;g[v][u]=c;
            ajuda[u][v]=c;ajuda[v][u]=c;
        }
        if (N-1==M){
            cout << min_edg <<endl;
            continue;
        }
        ans = INF;
        size_V=N;
        memset(rm, 0, sizeof rm);
        // sw
        while (size_V > 1){
            int mcp = minimum_cut_phase();
            ans=min(ans,mcp);
            size_V--;
        } 
        cout << ans << endl;
    }    
    exit(0);
}

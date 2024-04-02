// pescoço pra baixo é canela
// ADD SOME KIND OF SPECIAL LAZY PROPRAGATION TO AVOID TLE

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

const int MAX = 1e5 + 10;
int nums[MAX];
bitset<51> seg[4*MAX];

bitset<51> build(int p, int l, int r){
    if (l==r){
        bitset<51> aux;
        aux[nums[l]]=true;
        return seg[p]=aux;
    }
    int m = (l+r)/2;
    return seg[p] = build(2*p, l, m) | build(2*p+1, m+1, r);
}

int query(int a, int b, int p, int l, int r){
    if (b < l or r < a) return 0;
    if (l >= a and r <= b) return seg[p].count();
    int m = (l+r)/2;
    return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
}

bitset<51> update(int i, int x, int p, int l, int r){
    if (i < l or r < i) return seg[p]; 
    if (l==r){
        seg[p][nums[i]]=false;
        seg[p][x]=true;
        return seg[p];
    }
    int m = (l+r)/2;
    return seg[p] = update(i, x, 2*p, l, m) | update(i, x, 2*p+1, m+1, r);
}

int main(){ _
    int N;
    cin >> N;
    int Q; cin >> Q;
    int M; cin >> M;
    for (int i = 1; i <= N; i++) cin >> nums[i];
    build(1, 1, N); 
    while (Q--){
        int t; cin >> t;
        int a, b; cin >> a >> b;
        if (t==1){
            cout << query(a, b, 1, 1, N) << endl;
        }else {
            update(a, b, 1, 1, N);
        }
    }
exit(0);
}

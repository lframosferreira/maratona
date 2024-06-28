// pescoço pra baixo é canela

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define sz(v) (int)v.size()
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define umap unordered_map
#define uset unordered_set
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int , int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<double> vd;
typedef vector<vd> vvd;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vi prefix(const string &v){
    vi ret(v.size());
    int j = 0;
    for (int i = 1; i < v.size(); i++){
        while (j > 0 and v[i] != v[j]) j=ret[j-1];
        if (v[i]==v[j]) j++;
        ret[i]=j;
    } 
    return ret;
}

bool match(const string &txt, const string &pat){
    vi pi = prefix(pat);
    int j = 0; 
    for (int i = 0; i < txt.size(); i++){
        while (j > 0 and pat[j] != txt[i]) j = pi[j-1];
        if (txt[i]==pat[j]) j++;
        if (j==pat.size()) return true;
    }
    return false;
}


int main(){ _
    string in;
    int i=1;
    for (;;)
    {
        cin >> in;
        if (in == "0") break;
        if (i!=1)         cout << endl;
        string out; cin >> out;
        cout <<"Instancia " << i++ << endl;
        if (match(out, in)) cout << "verdadeira"<<endl;
        else cout << "falsa" <<endl;
    }
    exit(0);
}

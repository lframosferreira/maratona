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
typedef vector<vi> vvi;
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

template <class T>
void print(const vector<T> &v){
    for (auto s: v) cout << s << " ";
    cout << endl;
}


map<std::string, int> mp = {
        {"A", 0},
        {"A#", 1},
        {"Bb", 1},
        {"B", 2},
        {"Cb", 2},
        {"B#", 3},
        {"C", 3},
        {"C#", 4},
        {"Db", 4},
        {"D", 5},
        {"D#", 6},
        {"Eb", 6},
        {"E", 7},
        {"Fb", 7},
        {"E#", 8},
        {"F", 8},
        {"F#", 9},
        {"Gb", 9},
        {"G", 10},
        {"G#", 11},
        {"Ab", 11},
    };

vi prefix(const vector<int> &v){
    vi ret(v.size());
    int j = 0;
    for (int i = 1; i < v.size(); i++){
        while (j > 0 and v[i] != v[j]) j=ret[j-1];
        if (v[i]==v[j]) j++;
        ret[i]=j;
    } 
    return ret;
}

bool match(const vi &txt, const vi &pat){
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
    while (1){
        int M, T; cin >> M >> T;
        if (M==0 and T==0) break;
        vector<string> melody(M);
        vector<string> snippet(T);
        for (int i = 0; i < M; i++){
            string note; cin >> note;
            melody[i]=note;
        }
        for (int i = 0; i < T; i++){
            string note; cin >> note;
            snippet[i]=note;
        }

        vector<int> txt, pat;
        auto func = [&](int a, const vector<string> &g){
            int a1=mp[g[a]];
            int a2=mp[g[a+1]];
            if (a1 <= a2) return a2-a1;
            return 12 - abs(a1-a2);
        };
        for (int i = 0; i < M-1; i++) txt.pb(func(i,melody));
        for (int i = 0; i < T-1; i++) pat.pb(func(i, snippet));
        
        if (match(txt, pat)) cout << "S" << endl;
        else cout << "N" << endl;
    }
    exit(0);
}

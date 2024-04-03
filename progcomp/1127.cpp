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

string btosharp(char x){
    char aux;
    switch (x){
        case 'D':
            aux = 'C';
            break;
        case 'E':
            aux = 'D';
            break;
        case 'G':
            aux = 'F';
            break;
        case 'A':
            aux = 'G';
            break;
        case 'B':
            aux = 'A';
            break;
        default:
            break;
    }
    return string(1, aux);
}

template <class T>
void print(const vector<T> &v){
    for (auto s: v) cout << s << " ";
    cout << endl;
}


map<std::string, int> mp = {
        {"A", 0},
        {"A#", 1},
        {"B", 2},
        {"C", 3},
        {"C#", 4},
        {"D", 5},
        {"D#", 6},
        {"E", 7},
        {"F", 8},
        {"F#", 9},
        {"G", 10},
        {"G#", 11}
    };

int main(){ _
    vector<string> notes = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};
    while (1){
        int M, T; cin >> M >> T;
        if (M==0 and T==0) break;
        vector<string> melody(M); // i is dist from i to i + 1, same for below
        vector<string> snippet(T);
        for (int i = 0; i < M; i++){
            string note; cin >> note;
            if (note.length()==2 and note[1]=='b'){
                note=btosharp(note[0])+"#";
            }
            melody[i]=note;
        }
        for (int i = 0; i < T; i++){
            string note; cin >> note;
            if (note.length()==2 and note[1]=='b'){
                note=btosharp(note[0])+"#";
            }
            snippet[i]=note;
        }

        vector<int> txt, pat;
        for (int i = 0; i < M; i++) txt.pb(min(abs((mp[melody[i]] - mp[melody[(i+1)%M]])%12), abs((mp[melody[(i+1)%M]] - mp[melody[i]])%12)));
        for (int i = 0; i < T; i++) txt.pb(min(abs((mp[snippet[i]] - mp[snippet[(i+1)%T]])%12), abs((mp[snippet[(i+1)%T]] - mp[snippet[i]])%12)));
        print(txt);
        print(pat);
    }
    exit(0);
}

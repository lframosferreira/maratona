// pescoço pra baixo é canela

#include <bits/stdc++.h>

using namespace std;

#define  ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll; 
typedef vector<int> vi;
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int N = 1e5 + 10;
const int A = 26;

int trie[N][A];
bool fim[N];

int main(){ 
    while (true){
        memset(trie, 0, sizeof trie);
        memset(fim, false, sizeof fim);
        int n; cin >> n;
        if (n==0) break;
        bool bad = false;
        int prev_node=0;
        int next_node=1;
        while (n--){
            string word; cin >> word;
            if (bad) continue;
            prev_node=0;
            for (int i = 0; i < word.size(); i++){
                if (fim[prev_node]) bad=true;
                if (trie[prev_node][word[i]-97] == 0){
                    trie[prev_node][word[i]-97] = next_node;
                    prev_node=next_node;
                    next_node++;
                }else {
                    prev_node=trie[prev_node][word[i]-97];
                    if (i==word.size()-1)bad=true;
                }
            }
            fim[prev_node]=true;
        }
        if (bad) cout << "Conjunto Ruim" << endl;
        else cout << "Conjunto Bom" << endl;
    }
    exit(0);
}


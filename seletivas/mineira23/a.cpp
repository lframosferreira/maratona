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

set<string> cjt;

int main(){ _
    string F, M, S;
    cin >> F >> M >> S;
    cjt.insert(F);cjt.insert(M);cjt.insert(S);
    if (cjt.size() != 2) cout << '?' << endl;
    else {
        if (F=="rock" and M == "scissors" and S == "scissors") cout << "F" << endl;
        else if (S=="rock" and M == "scissors" and F == "scissors") cout << "S" << endl;
        else if (M=="rock" and F == "scissors" and S == "scissors") cout << "M" << endl;
        else if (F=="scissors" and M == "paper" and S == "paper") cout << "F" << endl;
        else if (S=="scissors" and M == "paper" and F == "paper") cout << "S" << endl;
        else if (M=="scissors" and F == "paper" and S == "paper") cout << "M" << endl;
        else if (F=="paper" and M == "rock" and S == "rock") cout << "F" << endl;
        else if (S=="paper" and M == "rock" and F == "rock") cout << "S" << endl;
        else if (M=="paper" and F == "rock" and S=="rock") cout << "M" << endl;
        else cout << '?' << endl;
    }
    exit(0);
}

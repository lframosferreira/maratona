#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int , int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    int n; cin >> n;
    int ans=0;
    map<char, int> mp;
    string txt; cin >> txt;
    for (char c: txt) mp[c]++;
    for (auto [c, i]: mp) if (i%2==1)ans++;
    cout << (ans == 0 ? 1 : ans) << endl;
    exit(0);
}


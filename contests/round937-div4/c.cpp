// pescoço pra baixo é canela

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
    int t; cin >> t;
    while (t--){
        string time; cin >> time;
        int pos=time.find(':');
        int h=stoi(time.substr(0, pos));
        int mn =stoi(time.substr(pos+1, string::npos));
        if (h < 12){
            cout << time << " AM" << endl;
        }else {
            cout << setfill('0') << setw(2) << (h == 12 ? 12 : h%12) << ":" << setfill('0') << setw(2) << mn << " PM" << endl;
        }
    }
    exit(0);
}

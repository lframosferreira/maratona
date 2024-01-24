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
typedef unsigned long long ull;
typedef pair<int , int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define mycout cout << setfill('0') << setw(2)

int main(){ _
    ll n; cin >> n; 
    ll hr = 0;
    ll mn = 0;
    ll sec = 1;
    for (ll i = 1; i <= n; i++){
        ll extra_mn = (2 * sec) / 60;
        sec = 2 * sec % 60;
        ll extra_hr = (2 * mn + extra_mn) / 60;
        mn = (2*mn + extra_mn) % 60;
        hr = (hr + extra_hr) % 24;
    }
    if (sec != 0) sec--;
    else {
        sec = 59;
        if (mn != 0) mn--;
        else {
            mn = 59;
            if (hr !=0) hr--;
            else hr = 23;
        }
    }
    mycout << hr << ":";
    mycout << mn << ":";
    mycout << sec << endl;
    exit(0);
}

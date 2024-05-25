#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
    int e, v; cin >> e >> v;
    int h = e/v;
    long double m = (long double)(e%v)/(long double) v;
    m = m*(60.0);
    m=floor(m);

    int hh = (19+h)%24;
    int mm = m;

    if(hh < 10) cout << 0;
    cout << hh << ":";
    if(mm < 10) cout << 0;
    cout << mm << endl;

    return 0;
}  

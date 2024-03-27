#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
 
#define f first
#define s second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
 
 
int main() { _
    int x; cin >> x;
    if (x<=24){
        int prev_x = x;
        cout << 1 << endl;
        x*=2;
        cout << x + 1 << endl;
        for (int i = 0; i < x; i++) cout << 1 << " ";
        cout << prev_x << endl;
    } else {
        cout << 1 << endl;
        cout << 50 << endl;
        for (int i = 0; i < 50; i++) cout << 5 << " ";
        cout << endl;
    }
 
	exit(0);
}

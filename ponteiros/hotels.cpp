#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back()

typedef long long ll;
typedef pair<int , int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    int n, m; cin>>n>>m;
    vector<int> v(n);
    for (int  i = 0; i < n;i++)cin>>v[i];
    if (n == 1) {
    	cout << 1 << endl; exit(0);
    }
    int ans = -INF;
    int i = 0; int j = 0;
    int sum = 0;
    while (j < n){
	cout << i << " " << j << endl;
	cout << sum << endl;
	cout << "---------" << endl;
	if (sum == m){
	    ans = m;
	}
	else if (sum < m) {
	    ans = max(ans, sum);
	    sum += v[j];
	    j++;
	} else {
	    sum -= v[i];
	    i++;
	}
    }
    cout << ans << endl;
    exit(0);
}

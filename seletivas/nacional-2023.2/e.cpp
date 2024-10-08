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
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n;i++)cin >> v[i];
    vector<int> counter(1001, 0);
    if (n == 1) {cout << "YES" << endl;exit(0);}
    else {
        for (auto e: v) counter[e]++;
    }
    int c = *max_element(counter.begin(), counter.end()); 
    if (n - c >= c - 1) {
        cout << "YES"<<endl;
    } else cout << "NO" << endl;
    exit(0);
}

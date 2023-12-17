#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int , int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// trying with selection sort

int main(){ _
  
    int n; cin >> n;
    vector<int> v(n, 0);
    for (int i = 0;i <n;i++) cin >> v[i];
    cout << n << endl;
    for (int i = 0; i <n ; i++){
      auto it = min_element(v.begin() + i, v.end());
      int aux = v[i];
      v[i]  = *it;
      *it = aux;
      cout << i << " " << distance(v.begin(), it) << endl;
    }
    exit(0);
}

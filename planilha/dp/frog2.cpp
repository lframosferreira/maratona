#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back()

typedef long long ll;
typedef pair<int , int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  for (int i = 0; i < n; i++){
    cin >> h[i];
  }
  vector<int> best(n, INF);
  best[0] = 0;
  for (int i = 1; i < n; i++){
    for (int j = 1; j<=k; j++){
      if (i - j < 0) continue;
      best[i] = min(best[i-j] + abs(h[i] - h[i-j]), best[i]);
    }
  }
   cout << best[n-1] << endl;

  exit(0);
}

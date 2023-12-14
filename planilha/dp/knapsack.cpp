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

int best[100][10001] = {0};

int main(){ _
  
  int n, W;
  cin >> n >> W;
  vector<int> w(n);
  vector<int> v(n);
  for (int i = 0; i < n; i++){
    cin >> w[i] >> v[i];
  }
  best[0][0] = 0;
  for (int i = 1; i < n; i++){
    for (int j = 0; j <= W; j++){
      best[i][j] = best[i-1][j]; 
      if (w[i] < j && best[i-1][j-w[i]] + v[i] > best[i][j]){
        best[i][j] = best[i-1][j-w[i]] + v[i]; 
      }
    }
  }
  cout << best[n][W] << endl; 
  
  exit(0);
}

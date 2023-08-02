#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n';
#define f first;
#define s second;
#define pb push_back();

typedef long long ll;
typedef pair<int , int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    int t;cin>>t;
    int n, k;
    while (t--){
        cin>>n>>k;
        vector<int> v(n);
        for (int i = 0; i < n; i++){
            cin>>v[i];
        }
        int beautiful = 0;
        int firstSum = reduce(v.begin(), v.begin() + k);
        for (int  i = 0; i < n - k; i++){
            int currSum = firstSum - v[0] + v[n - k + i + 1];
            if (currSum != firstSum) {
                beautiful = 1; break;
            }

        }
    }
    exit(0);
}

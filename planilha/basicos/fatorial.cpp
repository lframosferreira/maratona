// pescoço pra baixo é canela

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

const int MAX = 1e6+10;
int fat[MAX];

int main(){ _
    fat[0] = 1;
    fat[1] = 1;
    fat[2] = 2;
    fat[3] = 6;
    fat[4] = 4;
    fat[5] = 2;
    fat[6] = 2;
    fat[7] = 4;
    fat[8] = 2;
    fat[9] = 8;
    for (int i = 10; i < MAX; i++) {
        int k = i % 100;
        k = k / 10;
        if (k%2 ==0) fat[i] = 6 * fat[i/5] * fat[i%10] % 10;
        else fat[i] = 4 * fat[i/5] * fat[i%10] % 10;
    }
    int n;
    int c = 1;
    int ans;
    while (cin >> n){
        cout << "Instancia " << c << endl;
        ans = fat[n];
        cout << ans << endl;
        c++;
    }
    exit(0);
}

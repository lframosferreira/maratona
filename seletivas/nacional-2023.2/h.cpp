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
    int v[5][5];
    int x, y;
    for (int i = 0; i <5;i++){
        for (int j = 0; j < 5; j++){
            cin >> v[i][j];
            if (v[i][j]){
                x = i + 1;
                y = j + 1;
            }
        }
    }
    cout << abs(3-x) + abs(3-y) << endl;

    exit(0);
}

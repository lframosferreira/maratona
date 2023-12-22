// pescoço pra baixo é canela

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int , int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int rand(int a, int b){
    return rand()%(b-a+1) + a;
}

int main(int argc, char ** argv){ _
    srand(atoi(argv[1])); 
    int n = rand(1, 100);
    cout << n << endl;
    for (int i = 0; i < n; i++){
        int a = rand(1, n);
        int aux = rand(1, 2);
        if (aux==1) cout << a << " ";
        else cout << -a << " ";
    } 
    exit(0);
}

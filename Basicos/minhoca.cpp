#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    int v[n][m];
    int soma_linha = 0;
    int max_linha = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            soma_linha += v[i][j];
        }
        if (soma_linha > max_linha) max_linha = soma_linha;
        soma_linha = 0;
    }
    int soma_coluna = 0;
    int max_coluna = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            soma_coluna += v[j][i];
        }
        if (soma_coluna > max_coluna) max_coluna = soma_coluna;
        soma_coluna = 0;
    }
 
    cout << max(max_linha, max_coluna) << endl;

    return 0 ;
};
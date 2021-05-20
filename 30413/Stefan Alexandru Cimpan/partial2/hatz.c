#include <stdio.h>

int phats(int m, int n)
{
    int kk[m][n];

    for (int i = 0; i < m; i++)
        kk[i][0] = 1;

    for (int j = 0; j < n; j++)
        kk[0][j] = 1;

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++)

            kk[i][j] = kk[i - 1][j] + kk[i][j - 1];
    }
    return kk[m - 1][n - 1];
}

int main()
{
    printf("%d",phats(3, 8));
    return 0;
}

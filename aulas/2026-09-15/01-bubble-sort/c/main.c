#include <stdio.h>

void bubbleSort(int v[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (v[j] > v[j + 1])
            {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}
void imprime(int v[], int n)
{
    printf("\n(");
    for (int i = 0; i < n; i++) {
        if (i == n-1) 
            printf("%d", v[i]);
        else 
            printf("%d, ", v[i]);
    }

    printf(")\n");
}
int main(void)
{
    int v[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(v) / sizeof(v[0]);
    bubbleSort(v, n);
    imprime(v, n);
    return 0;
}
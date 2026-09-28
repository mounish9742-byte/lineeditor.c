#include <stdio.h>
#include <stdlib.h>

int *compareTriplets(int a_count, int *a, int b_count, int *b, int *result_count)
{
    int alice = 0;
    int bob = 0;

    for (int i = 0; i < 3; i++)
    {
        if (a[i] > b[i])
        {
            alice++;
        }
        else if (a[i] < b[i])
        {
            bob++;
        }
    }

    *result_count = 2;

    int *result = new int[2];

    result[0] = alice;
    result[1] = bob;

    return result;
}

int main()
{
    int a[3], b[3];

    for (int i = 0; i < 3; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i < 3; i++)
        scanf("%d", &b[i]);

    int result_count;

    int *result = compareTriplets(3, a, 3, b, &result_count);

    printf("%d %d\n", result[0], result[1]);

    free(result);

    return 0;
}
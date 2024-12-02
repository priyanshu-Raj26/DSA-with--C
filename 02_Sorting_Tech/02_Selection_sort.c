#include <stdio.h>

int main()
{
    int arr[100], range;
    int p, s, temp, index, min;

    printf("Enter a range: ");
    scanf("%d", &range);

    printf("Enter %d numbers: ", range);
    for (p = 0; p < range; p++)
    {
        scanf("%d", &arr[p]);
    }

    for (p = 0; p < range - 1; p++)
    {
        min = arr[p];
        index = p;
        for (s = p+1; s < range; s++)
        {
            if (min > arr[s])
            {
                min = arr[s];
                index = s;
            }
        }
        temp = arr[p];
        arr[p] = arr[index];
        arr[index] = temp;
    }
    printf("After sorting: \n");

    for (p = 0; p < range; p++)
    {
        printf("%d ", arr[p]);
    }

    return 0;
}
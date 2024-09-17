#include <stdio.h>

int main(){
    int arr[200];
    int l=0,r,mid,search,range;

    printf("Enter a range: ");
    scanf("%d",&range);

    r = range-1;
    printf("Enter %d numbers: ",range);
    for (int i = 0; i <range; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    printf("Enter a number that you want to search: ");
    scanf("%d",&search);

    while (l<=r)
    {
        mid = (l+r)/2;
        if(arr[mid]==search)
        {
            printf("The Number is found at position %d",mid+1);
            break;
        }
        else if(arr[mid]>search)
        {
            r = mid-1;
        }
        else if(arr[mid]<search)
        {
            l = mid+1;
        }

    }
    
    if(l>r)
    {
        printf("The number is not found.");
    }

    return 0;
}





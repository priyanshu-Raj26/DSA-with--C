#include <stdio.h>

void Bubble_Sort(int arr[],int range);

int main(){
    
    int arr[20];
    int i,range;

    printf("Enter a range: ");
    scanf("%d",&range);

    printf("Enter %d numbers: ",range);
    for (i = 0; i <range; i++)
    {
        scanf("%d",&arr[i]);
    }

    Bubble_Sort(arr,range);

    return 0;
}

void Bubble_Sort(int arr[],int range){
    int temp,i,j;

    for (i = 0; i <range-1; i++)
    {
        for (j = 0; j <range-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                arr[j] = arr[j] ^ arr[j+1];
                arr[j+1] = arr[j] ^ arr[j+1];
                arr[j] = arr[j] ^ arr[j+1];
                // temp=arr[j+1];
                // arr[j+1]=arr[j];
                // arr[j]=temp;
            }
        }
        
    }
    printf("After Sorting: \n");
    for (i = 0; i <range; i++)
    {
        printf("%d ",arr[i]);
    }

}






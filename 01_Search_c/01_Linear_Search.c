#include <stdio.h>

void LinearSearch(int arr[],int r,int search);

int main(){
    int arr[100];
    int search,r;

    printf("Enter a range: ");
    scanf("%d",&r);

    printf("Enter %d numbers: ",r);
    for (int i = 0; i < r; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    printf("Enter the number that you want to search: ");
    scanf("%d",&search);

    LinearSearch(arr,r,search);


    return 0;
}


void LinearSearch(int arr[],int r,int search){
    int count=0;

    for (int j = 0; j < r; j++)
    {
        if(arr[j] == search){
            printf("Number is found at position %d",j+1);
            count++;
            break;
        }

    }
    if(count==0) {
        printf("The Number is not found.");
    }
}




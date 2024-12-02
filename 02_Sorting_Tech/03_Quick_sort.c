#include <stdio.h>

void Quick_sort(int arr[],int N);
void Quick(int arr[],int N,int beg,int end,int *loc);

int main()
{
    int arr[] = {78,5,21,90,81,73,59,61,35,20,50,71};
    int N = 12;
    Quick_sort(arr,N);

printf("Sorted Array is: \n\n");
for (int i = 0; i < N; i++)
{
    printf("%d\t",arr[i]);
}


    return 0;
}



void Quick_sort(int arr[],int N)
{
    int beg,end,top=-1;
    int lower[10],upper[10],loc;
    if(N>1)
    {
        top++;
        lower[top]=0;
        upper[top]=N-1;
    }
    while (top!=-1)
    {
        beg = lower[top];
        end = upper[top];
        top--;
        Quick(arr,N,beg,end,&loc);

        if(beg<loc-1)
        {
            top++;
            lower[top] = beg;
            upper[top] = loc-1;
        }
        if(loc+1<end)
        {
            top++;
            lower[top] = loc+1;
            upper[top] = end;
        }
    }
    

}



void Quick(int arr[],int N,int beg,int end,int *loc)
{
    int left,right,temp;
    left = beg;
    right = end;
    *loc = beg;

    step1:
    while (arr[*loc]<=arr[right] && right!=*loc)
    {
        right--;
    }
    if(right==*loc)
    {
        return;
    }
    if(arr[*loc]>arr[right])
    {
        temp = arr[*loc];
        arr[*loc] = arr[right];
        arr[right] = temp;
        *loc = right;
    }
    goto step2;

    step2:
    while (arr[*loc]>=arr[left] && left!=*loc)
    {
        left++;
    }
    if(left==*loc)
    {
        return;
    }
    if(arr[*loc]<arr[left])
    {
        temp = arr[*loc];
        arr[*loc] = arr[left];
        arr[left] = temp;
        *loc = left;
    }
    goto step1;
}







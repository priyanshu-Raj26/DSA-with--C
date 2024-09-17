// #include <stdio.h>

// int main(){
//     int arr[200];
//     int l=0,r,mid,search,range;

//     printf("Enter a range: ");
//     scanf("%d",&range);

//     r = range-1;
//     printf("Enter %d numbers: ",range);
//     for (int i = 0; i <range; i++)
//     {
//         scanf("%d",&arr[i]);
//     }
    
//     printf("Enter a number that you want to search: ");
//     scanf("%d",&search);

//     while (l<=r)
//     {
//         mid = (l+r)/2;
//         if(arr[mid]==search)
//         {
//             printf("The Number is found at position %d",mid+1);
//             break;
//         }
//         else if(arr[mid]>search)
//         {
//             r = mid-1;
//         }
//         else if(arr[mid]<search)
//         {
//             l = mid+1;
//         }

//     }
    
//     if(l>r)
//     {
//         printf("The number is not found.");
//     }

//     return 0;
// }









// #include <stdio.h>

// int binarySearch(int arr[], int size, int target) {
//     int low = 0, high = size - 1;

//     while (low <= high) {
//         int mid = (low + high) / 2;

//         if (arr[mid] == target) {
//             return mid;  // Element found
//         } else if (arr[mid] < target) {
//             low = mid + 1;  // Search in the right half
//         } else {
//             high = mid - 1;  // Search in the left half
//         }
//     }

//     return -1;  // Element not found
// }

// int main() {
//     int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     int target = 10;

//     int result = binarySearch(arr, size, target);

//     if (result != -1) {
//         printf("Element found at index %d\n", result);
//     } else {
//         printf("Element not found\n");
//     }

//     return 0;
// }

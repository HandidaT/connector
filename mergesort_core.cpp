#include "test.hpp"

void merge(int in_arr[size],int p, int q, int r, int out_arr[size]){
    int i,j,k;
    i=p;
    j=q;
    k=p;
    //merging arrays in sorted order
    while(k<r){
        if(j==r || (i<q && in_arr[i]<=in_arr[j])){
            out_arr[k]=in_arr[i];
            i++;
        }
        else{
            assert(j<r);
            out_arr[k]=in_arr[j];
            j++;
        }
        k++;
    }
}



// Iterative mergesort function
void mergesort(int arr[size])
{
   int temp[size];
   int curr_size;  // For current size of subarrays to be merged
                   // curr_size varies from 1 to n/2
   int left_start; // For picking starting index of left subarray
                   // to be merged

   // Merge subarrays in bottom up manner.
   for (curr_size=1; curr_size<=size; curr_size = 2*curr_size)
   {
       // Pick starting point of different subarrays of current size
       for (left_start=0; left_start<size; left_start += 2*curr_size)
       {
           // Find ending point of left subarray. mid+1 is starting
           // point of right
           int mid=(left_start + curr_size);
           int right_end=(left_start + 2*curr_size);
           if(mid>=size) mid = size;
           if(right_end>=size) right_end = size;
           //std::cout<<"\nleft_start "<<left_start<<" curr_size "<<curr_size<<" mid "<<mid<<" right_end "<<right_end;
           // Merging left and right subarrays
           merge(arr, left_start, mid, right_end, temp);
       }
       //std::cout<<"\n";
       for(int i=0;i<size;i++){
           //std::cout<<temp[i]<<" ";
           arr[i]=temp[i];
       }
   }
}

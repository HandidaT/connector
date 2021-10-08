#include "test.hpp"



// Iterative mergesort function
void merge(int in_arr[size], int curr_size, int out_arr[size]){
   	int f1=0;
   	int f2=curr_size;
        int mid=curr_size;
        int right_end=2*curr_size;
        if(mid>=size) mid = size;
        if(right_end>=size) right_end = size;
       // Pick starting point of different subarrays of current size
       for (int left_start=0; left_start<size; left_start ++)
       {
#pragma HLS PIPELINE II=1
    	   int t1 = in_arr[f1];
    	   int t2 = (f2==right_end)?0:in_arr[f2];
           if(f2==right_end || (f1<mid && t1<=t2)){
               out_arr[left_start]=t1;
               f1++;
           }
           else{
               assert(f2<right_end);
               out_arr[left_start]=t2;
               f2++;
           }
           if(f1==mid && f2==right_end){
   		f1        = right_end;
   		mid      += 2*curr_size;
   		right_end += 2*curr_size;
   		if(mid>=size) mid = size;
   		if(right_end>=size) right_end = size;
   		f2=mid;
           }
       }
}

void mergesort(int A[size], int B[size]) {
#pragma HLS dataflow
	int temp[STAGES-1][size];
#pragma HLS ARRAY_PARTITION variable=temp type=complete dim=1
	int width = 1;
	merge(A, width, temp[0]);
	width *= 2;
	for (int stage = 1; stage < STAGES-1; stage++) {
#pragma HLS unroll
	  merge(temp[stage-1], width, temp[stage]);
	  width *= 2;
	}
	merge(temp[STAGES-2], width, B);
}

/*
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
   	int f1=0;
   	int f2=curr_size;
        int mid=curr_size;
        int right_end=2*curr_size;
        if(mid>=size) mid = size;
        if(right_end>=size) right_end = size;
       // Pick starting point of different subarrays of current size
       for (left_start=0; left_start<size; left_start ++)
       {
           //std::cout<<"\nleft_start "<<left_start<<" curr_size "<<curr_size<<" mid "<<mid<<" right_end "<<right_end;
           //merge(arr, left_start, mid, right_end, temp);
#pragma HLS PIPELINE II=1
    	   int t1 = arr[f1];
    	   int t2 = (f2==right_end)?0:arr[f2];
           if(f2==right_end || (f1<mid && t1<=t2)){
               temp[left_start]=t1;
               f1++;
           }
           else{
               assert(f2<right_end);
               temp[left_start]=t2;
               f2++;
           }
           if(f1==mid && f2==right_end){
   		f1        = right_end;
   		mid      += 2*curr_size;
   		right_end += 2*curr_size;
   		if(mid>=size) mid = size;
   		if(right_end>=size) right_end = size;
   		f2=mid;
           }
       }
       //std::cout<<"\n";
       for(int i=0;i<size;i++){
#pragma HLS PIPELINE II=1
           //std::cout<<temp[i]<<" ";
           arr[i]=temp[i];
       }
   }
}*/

#include "search_core.hpp"

void search(int val,int in_arr[size],int out_arr[size]){
#pragma HLS INTERFACE mode=ap_fifo port=in_arr
	for(int j=0;j<size;j++){
		if(in_arr[j]==val){
			out_arr[j]=1;
		}
		else{
			out_arr[j]=0;
		}
	}
}

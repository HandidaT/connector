#include "test.hpp"

int main()
{
    	int arr_in[size] = {3, 7, 6, 4, 5, 8, 0, 2, 1, 0};
    	int arr_out[size];
 
    	mergesort(arr_in,arr_out);
 
    	std::cout <<"\nSorted array is \n ";
	for(int i=0;i<size;i++){
		std::cout<<arr_out[i]<<" ";
	}
    	return 0;
}

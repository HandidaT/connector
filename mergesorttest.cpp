#include "test.hpp"

int main()
{
    	int arr[size] = {3, 7, 6, 55, 5, 8, 1, 2, 1, 0};
 
    	mergesort(arr);
 
    	std::cout <<"\nSorted array is \n ";
	for(int i=0;i<size;i++){
		std::cout<<arr[i]<<" ";
	}
    	return 0;
}

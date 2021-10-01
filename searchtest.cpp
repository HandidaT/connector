#include "search_core.hpp"

int main(){
	int arr1[size]={5,6,7,2,1,9,8,3,4,0};
	int arr2[size];
	int value=3;
	search(value,arr1,arr2);
	for(int i=0;i<size;i++){
		printf("value is %d\n",arr2[i]);
	}
}

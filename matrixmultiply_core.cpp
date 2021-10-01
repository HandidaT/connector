#include "matrixmultiply_core.hpp"

void matrixmultiply(int mat1[][dim2], int mat2[][dim2], int res[][dim2]){
	int i,j,k,dim1=dim2;
	for(i=0;i<dim1;i++){
		for(j=0;j<dim2;j++){
			res[i][j]=0;
			for(k=0;k<dim2;k++){
#pragma HLS UNROLL
				res[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}
}

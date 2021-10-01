#include "matrixmultiply_core.hpp"

int main(){
	int mat1[3][3]={{1,2,3},{1,2,3},{4,5,6}};
	int mat2[3][3]={{1,2,3},{1,2,3},{4,5,6}};
	int res[3][3];
	matrixmultiply(mat1,mat2,res);

}

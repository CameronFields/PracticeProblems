#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>




int *calcArray(int array[5]){

	

	/* take each element in array and create a product at pos i, that excludes the value of i
	*  for example:
	*  currLoc = array[i]
	*  int currProd
	*  array[i] = 1, therefore curr = 1
	*  r[i] = for(i<length;i++){ if(array[i] != curr){ currProd = array[i]*currProd}  
	*/

	static int r[5];

	int currentLocation;
	for(int i=0; i<5; i++){
		currentLocation = array[i];
		int currentProduct = 1;
		for(int j=0; j<5; j++){
			if(array[j]!=currentLocation){
				currentProduct = array[j] * currentProduct;
			}
			else{
				continue;
			}
			r[i]=currentProduct;
		}
	}
	return r;
}


int main(){
	
	int *returnArray;
	int test[5];
	for(int i=0; i<5; i++){
		test[i]=(i+1);
	}

	returnArray = calcArray(test);
	for(int i=0; i<5; i++){
		printf("%d ", returnArray[i]);
	}	
	printf("\n");
}

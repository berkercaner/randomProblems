#include <stdlib.h>

/*
	c solution for counting valleys problem from hackerrank.com
	questions URL => https://hackerrank.com/challenges/counting-valleys/problem
	time complexity  = O(n)
*/

int countingValleys(int steps, char* path){
	int yAxis = 0;
	int enter = 0, leave = 0, valleyCount = 0; //enter = 1 => entered the valley || leave = 1 => left the valley
	int firstEnter = 0;
	int* xAxis = calloc(sizeof(int),steps);
	for(int i=0; i<steps; i++){
		if(path[i] == 'U')
			yAxis++;
		else
			yAxis--;
		xAxis[i] = yAxis;
	}
	/*
		for sample input = [UDDDUDUU] 
		xAxis will be = 1 0 -1 -2 -1 -2 -1 0
	*/
	
	while(xAxis[firstEnter] > 0)
		firstEnter++;
		
	for(int i=firstEnter; i<steps; i++){
		if(xAxis[i] < 0)
			enter = 1;
		else if(xAxis >= 0 && enter == 1)
			leave = 1;
		
		if(enter == 1 && leave == 1){
			enter = 0;
			leave = 0;
			valleyCount++;
		}
	}
	return valleyCount;
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum { none, left, up, diagonal } path;

int colSize=0;
void bublesort(int items[],int size);
int max(int a, int b);
void print2DArr(int table[][colSize],int row);

int main(){
	
	FILE *fp;
	int num = 0,tableSize=0,numElementSeq=0;
	int input = 0;
	fp = fopen("List.txt","r");
	
	//read number of elements
	fscanf(fp, "%d", &num);
	tableSize = num+1;
	colSize = tableSize;
	int inputListRow [tableSize],inputListCol[tableSize];
	int i=1,j=1;
	inputListRow[0]=0;
	inputListCol[0]=0;
	//duplicate the test file
	while(fscanf(fp, "%d", &input)==1 && i<=num){
		inputListRow[i] = input;
		inputListCol[i] = input;
		i++;
	}
	fclose(fp);

	//sort the col numbers in order to find longest increasing sequence
	bublesort(inputListCol,tableSize);
	int table[tableSize][tableSize];
	path direction[tableSize][tableSize];    // to store path of lcs
	//make metrix table
	//init first col and row to 0s
	for(i=0;i<tableSize;i++){
		table[i][0] = 0;    //col 1
		table[0][i] = 0;	//row i 1

		direction[i][0] = 0;    //col 1
		direction[0][i] = 0;	//row i 1
	}
	
	//find lcs 
	for(i=1;i<tableSize;i++){        //iterate vertically (col)
		for(j=1;j<tableSize;j++){	 //iterate horizontally (row)
		
			
			if(inputListCol[i] == inputListRow[j]){
				table[i][j] = table[i-1][j-1]+1;
				//save direction
				direction[i][j] = diagonal;			
			}
			else{
				
				if(table[i-1][j]>=table[i][j-1]){
					table[i][j] = table[i-1][j];
					//save direction
					direction[i][j] = up;					
				}
				else{
					table[i][j] = table[i][j-1];
					//save direction
					direction[i][j] = left;
				}				
			}
			//printf("  %d",table[i][j]);
		}
		//printf("\n");
	}

	//get the number element in longest sequence found
	numElementSeq = table[tableSize-1][tableSize-1];
	int lcs[numElementSeq];
	
	
	//backtracks the choices taken when computing the lcs table
	i=tableSize-1;
	j=tableSize-1;
	int sequenceSize = numElementSeq;
	while(direction[i][j]>0){
		if(direction[i][j]==diagonal){
			sequenceSize--;
			lcs[sequenceSize]=inputListRow[j];   //save the number into lcs
			i=i-1;
			j=j-1;
			
		}
		else if(direction[i][j]==up){
			i=i-1;
		}
		else if(direction[i][j]==left){
			j=j-1;
		}

	}

	//printing out the results	
	printf("Num of numbers found in correct sequence: %d \n",numElementSeq);
	printf("The sequence:\n");
	for(i=0;i<numElementSeq;i++){
		printf(" %d",lcs[i]);
		if((i%10)==0 && i>0){
			printf("\n");
		}
	}
	printf("\n");
	return 0;
}

void print2DArr(int table[][colSize],int row){
	int i=0,j=0;
	for(i = 0;i<row;i++){
		for(j = 0;j<colSize;j++){
			printf(" %d", table[i][j]);
		}
		printf("\n");   //start new row
	}

}

int max(int a, int b){
	if(a>=b){
		return a;
	}
	else{
		return b;
	}
}

void bublesort(int items[],int size){
	int i=0,j=0,temp=0;
	for(i=0;i<size;i++){
		for(j=i;j<size;j++){
			if(items[i]>items[j]){
				temp = items[i];
				items[i] = items[j];
				items[j] = temp;
			}
		}
	}


}


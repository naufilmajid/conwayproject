#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


FILE *filePtr;
bool **grid_in; 
bool **grid_out;
int neighabor;
int generations;
char fileName[20];



void print(bool *ptr[],int len);
void next(bool *in[], bool *out[], int len);
bool living(bool *in[],int x, int y, int len);


int main(int argc, char const *argv[]) {
	printf("%ld, %ld, %ld, %ld\n",sizeof(int),sizeof(bool),sizeof(double),sizeof(char) );
	if (argc < 4) {
		printf("%s\n","ERROR: Wrong usage of the program! Sample Correct usage is:-\n:\\conway.txt 1 10\n");
		return 0;
	}
	strcpy(fileName,argv[1]);
	generations = atoi(argv[2]);
	if (generations<0)
	{
		printf("%s\n","ERROR: Wrong usage of the program! Number of generations can not be negative.\n:\\conway.txt 1 10\n");
		return 0;
	}
	neighabor = atoi(argv[3]);
	if (neighabor<5)
	{
		printf("%s\n","ERROR: Grid Size can not be less than 5.\n:\\conway.txt 1 10\n");
		return 0;
	}

	printf("%s\n","Initializing the GRIDS" );
	bool *grid_in = (bool *)malloc(neighabor * sizeof(bool *));
	bool *grid_out = (bool *)malloc(neighabor * sizeof(bool *));
	for (int i = 0; i < n; ++i)	{
		grid_in[i] = (bool *)malloc(neighabor * sizeof(bool));
		grid_out[i] = (bool *)malloc(neighabor * sizeof(bool));
		for (int j = 0; j < neighabor; ++j){
			grid_in[i][j] = false;
			grid_out[i][j] = false;
		}
	}


	printf("%s\n","Reading File!" );
	filePtr = fopen(fileName,"r");
	if(filePtr == NULL){
		printf("%s\n","ERROR: Invalid File name or file not found!\n" );
		return 0;
	}
	ssize_t charRead ; size_t len=0;
	char *line, *token;
	printf("%s\n","Entering While Loop!" );
	int row = 0;
	while ((charRead = getline(&line, &len, filePtr))!=-1){
		token = strtok(line,", ");
		for (int i = 0; i < neighabor-1; ++i)	{
			grid_in[row][i] = atoi(token);
			token = strtok(NULL,", ");
		}
		++row;
	}
	print(grid_in,neighabor);
	bool **temp;
	for (int i = 0; i < generations-1; ++i)
	{
		printf("%s\n","Entered Generation Calc Loop!" );
		next(grid_in,grid_out,n);
		temp = grid_in;
		grid_in = grid_out;
		grid_out = temp;
	}
	printf("%s\n","Calculating Last Gen!" );
	next(gridIn,grid_out,n);
	printf("%s\n","Printing Grid to File" );
	print(grid_out,nneighabor);
	return 0;
}
void next(bool *in[], bool *out[], int len){
	int aliveNebr=0;
	bool this;
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < len; ++j)
		{
			aliveNebr = 
			living(in,i-1,j-1,len)+
			living(in,i-1, j ,len)+ 
			living(in,i-1,j+1,len)+ 
			living(in,i, j-1, len)+ 
			living(in,i, j+1, len)+ 
			living(in,i+1,j-1,len)+ 
			living(in,i+1, j, len)+  
			living(in,i+1,j+1,len);
			if(aliveNebr<2 || aliveNebr>3) out[i][j] = 0;
			else if(aliveNebr == 3) out[i][j] = 1;
			else out[i][j] = in[i][j];
		}
	}
}

bool living(bool *in[],int x, int y, int len){
	printf("( %d, %d) , ",x,y );
	if (x<0 || y<0 || x>=len || y>=len) return false;
	else return in[x][y];
	return false;

void print(bool *ptr[],int len){
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < len-1; ++j)
		{
			printf("%d, ", ptr[i][j]);
		}
		printf("%d\n", ptr[i][len]);
	}
}

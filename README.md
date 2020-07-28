# Project Title: Conway’s Game Of Life 
~ implemented in C 
### Group Members:
##### std_id & names
63361     Naufil Majid,
62765     Ayesha Aman,
63372     Rabbiya Mehmood

## Phase-01:
- program should take input from file
- Take command line arguments | int main (int argc, char* argv[]){}
- Output file shows the final state of the window after the generation mentioned in command line argument

## What is Conway's Game Of Life??
The Game of Life, additionally recognized actually as Life, is a cell automaton devised via way of means of the British mathematician John Horton Conway in 1970. It is a zero-participant game, that means that its evolution is decided via way of means of its preliminary state, requiring no in addition input. One interacts with the Game of Life via way of means of developing an preliminary configuration and gazing the way it evolves. It is Turing whole and might simulate a time-honored constructor or some other Turing machine.

## Rules:
- cell with fewer than two alive pals dies because of under-population.
- cell with or 3 alive pals lives directly to the subsequent generation.
- cell with extra than 3 stay pals dies because of overpopulation.
- lifeless cell with precisely 3 stay pals will become a stay mobileular through reproduction.

## Sample Code:
important libraries are:
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

methods:
print()
life()
main()

int main( int argc, char* argv[] ) {
// code implementation here like
user input through filling
}

for (int l = 1; l < M - 1; l++)
	{
		for (int m = 1; m < N - 1; m++)
		{
		
			int aliveNeighbours = 0;
			for (int i = -1; i <= 1; i++)
			{
				for (int j = -1; j <= 1; j++)
				{
					aliveNeighbours += grid[l + i][m + j];
				}
			}
			aliveNeighbours -= grid[l][m];

			if ((grid[l][m] == 1) && (aliveNeighbours < 2))
			{
				future[l][m] = 0;
			}
			else if ((grid[l][m] == 1) && (aliveNeighbours > 3))
			{
				future[l][m] = 0;
			}
			else if ((grid[l][m] == 0) && (aliveNeighbours == 3))
			{
				future[l][m] = 1;
			}
			else
			{
				future[l][m] = grid[l][m];
			}
		}

Final Phase Comming Soon....!


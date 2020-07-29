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
## concept of used:
Modern multiprocessing operating systems allow many processes to be active, where each process is a “thread” of computation being used to execute a program. One form of multiprocessing is called time-sharing, which lets many users share computer access by rapidly switching between them. Time-sharing must guard against interference between users’ programs, and most systems use virtual memory, in which the memory, or “address space,” used by a program may reside in secondary memory (such as on a magnetic hard disk drive) when not in immediate use, to be swapped back to occupy the faster main computer memory on demand. This virtual memory both increases the address space available to a program and helps to prevent programs from interfering with each other, but it requires careful control by the operating system and a set of allocation tables to keep track of memory use. Perhaps the most delicate and critical task for a modern operating system is allocation of the CPU; each process is allowed to use the CPU for a limited time, which may be a fraction of a second, and then must give up control and become suspended until its next turn. Switching between processes must itself use the CPU while protecting all data of the processes.

The library function malloc is used to allocate a block of memory on the heap. The program accesses this block of memory via a pointer that malloc returns. When the memory is no longer needed, the pointer is passed to free which deallocates the memory so that it can be used for other purposes.

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


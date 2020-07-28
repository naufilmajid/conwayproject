/******************************************************************************
Conways Games Of Life Simple Implementation
show changes in each generation by follow rules we explained in file Readme.
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
 
#define Rows 10
#define Col 10
 
#define get_col(c) (c%Col)
#define get_row(c) (c/Col)
 
#define c_left(c)   ((get_col(c) == 0) ? (Col-1) :  -1)
#define c_right(c)  ((get_col(c) == Col-1) ? (-Col+1) :  1)
#define c_top(c)    ((get_row(c) == 0) ? ((Rows-1) * Col) : -Col)
#define c_bottom(c) ((get_row(c) == Rows-1) ? (-(Rows-1) * Col) : Col)
 
typedef struct _cell
{
    struct _cell* n[8];
    char current_state;
    char next_state;
} cell;
 
typedef struct
{
    int rows;
    int cols;
    cell* cells;
} world;
 
void evolve(cell* c)
{
    int count=0, i;
    for (i=0; i<8; i++)
    {
        if (c->n[i]->current_state) count++;
    }
    if (count == 3 || (c->current_state && count == 2)) c->next_state = 1;
    else c->next_state = 0;
}
 
void update(world* w)
{
    int nrcells = w->rows * w->cols, i;
    for (i=0; i<nrcells; i++)
    {
        evolve(w->cells+i);
    }
    for (i=0; i<nrcells; i++)
    {
        w->cells[i].curr_state = w->cells[i].next_state;
        if (!(i%Col)) printf("\n");
        printf("%c",w->cells[i].curr_state ? '*' : ' ');
    }
}
 
world* init_world()
{
    world* result = (world*)malloc(sizeof(world));
    result->rows = Rows;
    result->cols = Col;
    result->cells = (cell*)malloc(sizeof(cell) * Col * Rows);
     
    int nrcells = result->rows * result->cols, i;
     
    for (i = 0; i < nrcells; i++)
    {
        cell* c = result->cells + i;
             
        c->n[0] = c+c_left(i);
        c->n[1] = c+c_right(i);
        c->n[2] = c+c_top(i);
        c->n[3] = c+c_bottom(i);
        c->n[4] = c+c_left(i)   + c_top(i);
        c->n[5] = c+c_left(i)   + c_bottom(i);
        c->n[6] = c+c_right(i)  + c_top(i);
        c->n[7] = c+c_right(i)  + c_bottom(i);
         
        c->current_state = rand() % 2;
    }
    return result;
}
 
int main()
{
    srand(3);
    world* w = init_world();
     
    while (1)
    {
        update(w);
        getchar();
    }
}


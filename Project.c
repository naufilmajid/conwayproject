/******************************************************************************
Conway's Game of Life Implementation In C 
Console Based Project 
Determining Changes In generations as per as rules
~~~~~~~~~~~~~~~~~~~~~~~~~CONWAYS_PROJECT~~~~~~~~~~~~~~~~~~~~~~~~~
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
 
typedef struct cellT {
    struct cellT *n[8];
    int on;
} cellT;
 
typedef struct worldT {
    cellT **arr;
    int width;
    int height;
    void *memory;
} worldT;
 
void print(worldT *w, FILE *pOp)
{
    int x, y;
 
    for(y = 0; y < w->height; y++) {
        for(x = 0; x < w->width; x++) {
            fprintf(pOp, "%c", (w->arr[y][x]).on ? 254 : ' ');
        }
        fputc((int)'\n', pOp);
    }
    fflush(pOp);
}
 
void stary(worldT *w)
{
    int x, y;
 
    for(y = 0; y < w->height; y++) {
        for(x = 0; x < w->width; x++) {
            (w->arr[y][x]).on = rand() & 1;
        }
    }
}
 
void updateLife(worldT *w)
{
    int x, y, i, n;
 
    for(y = 0; y < w->height; y++) {
        for(x = 0; x < w->width; x++, n = 0) {
            for(i = 0; i < 8; i++)
                if((w->arr[y][x].n[i]) && ((w->arr[y][x]).n[i]->on & 1))
                    n++;
 
            if((n < 2) || (n > 3))
                (w->arr[y][x]).on |= 2;
            else if(n == 3)
                (w->arr[y][x]).on |= 4;
        }
    }
 
    for(y = 0; y < w->height; y++) {
        for(x = 0; x < w->width; x++) {
            if(w->arr[y][x].on & 4)
                w->arr[y][x].on = 1;
            else if(w->arr[y][x].on & 2)
                w->arr[y][x].on = 0;
        }
    }
}
 
void destroyLife(worldT *w)
{
    free(w->memory);
}
 
int createLife(worldT *w, int width, int height)
{
    int i, j;
    unsigned long base   = sizeof(cellT *) * height;
    unsigned long rowlen = sizeof(cellT)   * width;
 
    if(!(w->memory = calloc(base + (rowlen * height), 1)))
        return 0;
 
    w->arr  = w->memory;
    w->width  = width;
    w->height = height;
 
    for(i = 0; i < height; i++) {
        w->arr[i] = w->memory + base + (i * rowlen);
    }
 
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            if(j != 0) {
                (w->arr[i][j]).n[3] = &(w->arr[i][j - 1]);
            }
 
            if(i != 0) {
                (w->arr[i][j]).n[1] = &(w->arr[i - 1][j]);
            }
 
            if(j != (width - 1)) {
                (w->arr[i][j]).n[4] = &(w->arr[i][j + 1]);
            }
 
            if(i != (height - 1)) {
                (w->arr[i][j]).n[6] = &(w->arr[i + 1][j]);
            }
 
            if((i != 0) && (j != 0)) {
                (w->arr[i][j]).n[0] = &(w->arr[i - 1][j - 1]);
            }
 
            if((i != (height - 1)) && (j != (width - 1))) {
                (w->arr[i][j]).n[7] = &(w->arr[i + 1][j + 1]);
            }
 
            if((i != (height - 1)) && (j != 0)) {
                (w->arr[i][j]).n[5] = &(w->arr[i + 1][j - 1]);
            }
 
            if((i != 0) && (j != (width - 1))) {
                (w->arr[i][j]).n[2] = &(w->arr[i - 1][j + 1]);
            }
        }
    }
 
    return 1;
}
 
int main(int argc, char *argv[]) {
    worldT conways_gameoflife;
 
    if(createLife(&conways_gameoflife, 79, 24)) {
        stary(&conways_gameoflife);
        do {
            print(&conways_gameoflife, stdout);
            getchar();
            fflush(stdin);
            updateLife(&conways_gameoflife);
        }while(1);
        destroyLife(&conways_gameoflife);
    }
 
    return 0;
}
}

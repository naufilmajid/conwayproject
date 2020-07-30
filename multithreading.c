*//////////////////////////////////////////////////////////////////////////
multithreading part of conways game implemented here *////////////////////////////

int x[5];
for(i=0;i<100;i=i+10){
    for(j=0;j<100;j=j+10){
        x[0]=i;
        x[1]=i+9;
        x[2]=j;
        x[3]=j+9;
        x[4]=k;
        mult = pthread_create(&(tid[k++]),NULL, &pOpulate, (void *)x);
    }
}

int *x;
for(i=0;i<100;i=i+10){
    for(j=0;j<100;j=j+10){
        x= malloc(5 * sizeof(*x));
        x[0]=i;
        x[1]=i+9;
        x[2]=j;
        x[3]=j+9;
        x[4]=k;
        mult = pthread_create(&(tid[k++]),NULL, &pOpulate, (void *)x);
    }
}

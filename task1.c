/*****************************************************************************************************
This is not complete implementation, working on it *************************************************/


int main( int argc, char* argv[] ) {
  int g = 10;      // number of generations
  int i;
  char **last, **next, **temp;


  cls();   //clear screen

  //--- init the global arrays
  initTests();

  //pointers
  last   = T0;
  next = T1;

  //first generation
  print( last );          
//iteration
  for ( i = 0; i < g; i++) {
    
    //printf( "Generation %d\n", i );
    
    life( last, next );  // generate the next // apply rules

    // display new generation (comment this out if you want
    // the last generation, instead)
    print( last );
    sleep(1);  // delay of 1 sec

    
    temp = last;   // copy future to last
    last = next;
    next = temp;
  }
  
  print(last);  // display the last generation
}

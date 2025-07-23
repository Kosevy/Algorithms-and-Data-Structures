#ifndef _INSERTION_UTIL_
#define _INSERTION_UTIL_


//-------------------------------------
//int* insertionSort(int* v, int n){
void insertionSort(int* v, int n){
   int key, j;
   for (int i = 1; i < n; i++){
       key = v[i];
       j = i-1;
       while (j >= 0 && v[j] > key){
           v[j+1] = v[j];
           j = j-1;
       }
       v[j+1] = key;
   }
  // return(v);
}

/*
key=v[i]=5
   
   j i
 0 1 2 3     j>=0 (ok), v[j]>key
{3,7,5,0}

 j   i
 0 1 2 3     j>=0 (ok), v[j]>key
{3,7,7,0}


*/
//-----------------------------------
void print(int* v, int n){
  for (int i = 0; i < n; ++i)
    std::cout << " " << v[i];
  std::cout << std::endl;
}
//-----------------------------------


#endif

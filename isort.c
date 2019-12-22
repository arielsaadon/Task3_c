#include <stdio.h>
#include "isort.h"
#define Size 50

void shift_element(int* arr,int i){
  for(int j = 0; j < i; j++){
    int temp = *(arr+j);
    *(arr+j) = *(arr-j);
    *(arr+j+1) = temp;
  }
}

void swap(int* arr,int i){
  for(int j = 0; j < i; j++){
    int temp = *(arr-j);
    *(arr-j) = *(arr-j-1);
    *(arr-j-1) = temp;
  }
}

void insertion_sort(int* arr,int len){
  for(int i = 1; i < len; i++){
    int count = 0;
    int j = i-1;
    while((*(arr+j) > *(arr+i)) && j>=0){
      j--;
      count++;
    }
    swap((arr+i),count);
  }
}

#include <stdio.h>
#include "isort.h"
#define Size 50

int main(){
  int arr[Size] = {0};
  int num = 0;
  printf("Enter numbers for sort: \n");
  for(int i = 0; i < Size; i++){
    if(scanf("%d", &num) != 1){
      printf("Enter only numbers");
    }else
      *(arr+i) = num;
  }
  insertion_sort(arr,Size);
  printf("After Sort:\n");
  for(int i = 0; i < Size; i++){
    printf("%d,", *(arr+i));
  }
}

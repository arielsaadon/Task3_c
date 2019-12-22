#include <stdio.h>
#include "txtfind.h"
#define WORD 30

int main(){
  char search[WORD];
  char option;

  printf("Please enter a string to search:");
  scanf("%s",search);

  printf("Enter option 'a' or 'b':");
  scanf(" %c", &option);

  if(option == 'a')
  print_lines(search);

  if(option == 'b')
  print_similar_words(search);

  return 0;
}

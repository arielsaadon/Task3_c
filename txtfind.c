#include <stdio.h>
#include <string.h>
#include "txtfind.h"
#define LINE 256
#define WORD 30

int getLine(char s[]){

  int count = 0;
  char ch = getchar();

  while((ch != '\n') && (ch != EOF) && (count < LINE)){
    s[count++] = ch;
    ch = getchar();
  }
  s[count] = '\0';
  return count;
}

int getword(char w[]){
  int count = 0;
  char ch = getchar();

  while((ch != '\n') && (ch != '\t') && (ch != ' ') && (ch != EOF) && (count < WORD)){
    w[count++] = ch;
    ch = getchar();
  }
  w[count] = '\0';
  return count;
}

int substring(char* str1, char* str2){

  if(strlen(str1) < strlen(str2))
  return 0;

  for(int i = 0; i <= strlen(str1)-strlen(str2); i++){
    for(int j = 0; j < strlen(str2); j++){
      if(str2[j] != str1[i+j])
      break;
      if(j+1 == strlen(str2))
      return 1;
    }
  }
  return 0;
}

int similar(char *s, char *t, int n){
  int count = 0;

  if(n == 0){
    for(int i = 0; i < strlen(s) || i < strlen(t); i++){
      if(s[i] == t[i])
      count++;
    }
    if(count == strlen(t))
    return 1;
    else
    return 0;
  }
  int equalCount[strlen(s)];
  for(int i = 0 ; i < strlen(s); i++){
    equalCount[i] = 0;
  }
  int j = 0;

  for(int i = 0; i < strlen(s); i++){
    if(s[i] == t[j]){
      equalCount[i]++;
      j++;
      if(j > strlen(t))
      break;
    }
  }
  for(int i = 0; i < strlen(s); i++){
    if(equalCount[i] == 1)
    count++;
  }
  if((count == strlen(s)-n) && (count != 0)){
    return 1;
  }
  return 0;
}

void print_lines(char* str){
  char line[LINE];
  
  fgets(line, LINE, stdin); // skip line
  fgets(line, LINE, stdin); // skip line

  printf("Enter the lines: \n");
  while(getLine(line) > 0){
    if(substring(line,str))
    printf("%s\n",line);
  }
}

void print_similar_words(char* str){
  char word[WORD];

  fgets(word, WORD, stdin); // skip line
  fgets(word, WORD, stdin); // skip line

  printf("Enter the words: \n");
  while(getword(word) > 0){
    if(similar(word,str,1))
    printf("%s\n",word);
  }
}

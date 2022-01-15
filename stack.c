#include "stack.h"
#include <stdio.h>
#include <string.h>

enum { STACK_SIZE = 512 };

static char g_array[STACK_SIZE];
static int g_top = 0;

void push(char data) { g_array[g_top++] = data; }

char pop(void) { return g_array[--g_top]; }

int isEmpty(void) { return g_top == 0; }

void reverseWord(char *word);

void main(void) {
  char word[256];

  printf("단어를 입력하세요 : ");
  fgets(word, sizeof(word), stdin);
  word[strlen(word) - 1] = '\0';

  reverseWord(word);

  printf("변환한 값 : %s\n", word);
}

// 매개변수로 전달된 문자열을 스택을 사용해 반대로 뒤집는 함수
void reverseWord(char *word) {
  char *save = word;

  while (*word)
    push(*word++);

  word = save;
  while (!isEmpty())
    *word++ = pop();
}

#ifndef DEBUG
// #define DEBUG
#endif

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define OPT_CHAR_WIDTH 'c'
#define CHAR_WIDTH 7	// in terms of characters in array
#define CHAR_HEIGHT CHAR_WIDTH	// in terms of characters in array
#define CHAR_ARR_LEN (CHAR_WIDTH * CHAR_HEIGHT)	// length of array of character to be displayed
#define PRINTABLE_CHAR 36		// number of printable characters: 26 alphabets + 10 numbers
#define CHAR_GAP 1				// gap between characters
#define LINE_GAP 1              // vertical gap between words
#define FILL_SPACES(arr) for(i = 0; i < CHAR_ARR_LEN; i++) arr[i] = ' ';

enum linePosition{TOP_ROW, MIDDLE_ROW, BOTTOM_ROW, LEFT_COLUMN, CENTER_COLUMN, RIGHT_COLUMN, TOP_LEFT_COLUMN, BOTTOM_LEFT_COLUMN, TOP_RIGHT_COLUMN, BOTTOM_RIGHT_COLUMN};

void print7seg(char *str);
void defineLetterInArray();
void fillCharArr(char *arr, enum linePosition pos);

static int charWidth = CHAR_WIDTH;
static int charHeight = CHAR_HEIGHT;
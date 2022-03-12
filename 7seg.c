#include "7seg.h"

static int isCharArrDefined = 0;	// is character array defined

static char charA[CHAR_ARR_LEN],
			charB[CHAR_ARR_LEN],
			charC[CHAR_ARR_LEN],
			charD[CHAR_ARR_LEN],
			charE[CHAR_ARR_LEN],
			charF[CHAR_ARR_LEN],
			charG[CHAR_ARR_LEN],
			charH[CHAR_ARR_LEN],
			charI[CHAR_ARR_LEN],
			charJ[CHAR_ARR_LEN],
			charK[CHAR_ARR_LEN],
			charL[CHAR_ARR_LEN],
			charM[CHAR_ARR_LEN],
			charN[CHAR_ARR_LEN],
			charO[CHAR_ARR_LEN],
			charP[CHAR_ARR_LEN],
			charQ[CHAR_ARR_LEN],
			charR[CHAR_ARR_LEN],
			charS[CHAR_ARR_LEN],
			charT[CHAR_ARR_LEN],
			charU[CHAR_ARR_LEN],
			charV[CHAR_ARR_LEN],
			charW[CHAR_ARR_LEN],
			charX[CHAR_ARR_LEN],
			charY[CHAR_ARR_LEN],
			charZ[CHAR_ARR_LEN],
			char0[CHAR_ARR_LEN],
			char1[CHAR_ARR_LEN],
			char2[CHAR_ARR_LEN],
			char3[CHAR_ARR_LEN],
			char4[CHAR_ARR_LEN],
			char5[CHAR_ARR_LEN],
			char6[CHAR_ARR_LEN],
			char7[CHAR_ARR_LEN],
			char8[CHAR_ARR_LEN],
			char9[CHAR_ARR_LEN];

char *charArr[] = 
{
	charA,
	charB,
	charC,
	charD,
	charE,
	charF,
	charG,
	charH,
	charI,
	charJ,
	charK,
	charL,
	charM,
	charN,
	charO,
	charP,
	charQ,
	charR,
	charS,
	charT,
	charU,
	charV,
	charW,
	charX,
	charY,
	charZ,
	char0,
	char1,
	char2,
	char3,
	char4,
	char5,
	char6,
	char7,
	char8,
	char9
};

void print7seg(char *str)
{
	int i, j, k, l;
	char ch, *convertedString, *charToPrint;

	/* Converting lowercase characters into uppercase */
	/* Discard characters that are not alphanumeric */
	
	convertedString = malloc( strlen(str) + 1 );
	for(i=0, j=0; str[i] != '\0'; i++)
	{
		if( isalnum(str[i]) || str[i] == ' ')
		{
			convertedString[j] = toupper(str[i]);
			j++;
		}
	}
	convertedString[j] = '\0';

#ifdef DEBUG
	printf("DEBUG MODE: ON\nConverted to string: %s\n\n", convertedString);
#endif

	if(!isCharArrDefined)
	{
		defineLetterInArray();
	}

	for(i = 0; i < LINE_GAP; i++)
	{
		printf("\n");
	}

	/* Displaying wordart one row at a time */
	for(i = 0; i < charHeight; i++)
	{
		for(j = 0, ch = convertedString[0]; ch != '\0'; )	// loop through string to be printed
		{
			switch(ch)
			{
				case ' ':
					for(k = 0; k < charWidth; k++)
					{
						printf(" ");
					}
					break;
				case 'A':
					charToPrint = charA;
					break;
				case 'B':
					charToPrint = charB;
					break;
				case 'C':
					charToPrint = charC;
					break;
				case 'D':
					charToPrint = charD;
					break;
				case 'E':
					charToPrint = charE;
					break;
				case 'F':
					charToPrint = charF;
					break;
				case 'G':
					charToPrint = charG;
					break;
				case 'H':
					charToPrint = charH;
					break;
				case 'I':
					charToPrint = charI;
					break;
				case 'J':
					charToPrint = charJ;
					break;
				case 'K':
					charToPrint = charK;
					break;
				case 'L':
					charToPrint = charL;
					break;
				case 'M':
					charToPrint = charM;
					break;
				case 'N':
					charToPrint = charN;
					break;
				case 'O':
					charToPrint = charO;
					break;
				case 'P':
					charToPrint = charP;
					break;
				case 'Q':
					charToPrint = charQ;
					break;
				case 'R':
					charToPrint = charR;
					break;
				case 'S':
					charToPrint = charS;
					break;
				case 'T':
					charToPrint = charT;
					break;
				case 'U':
					charToPrint = charU;
					break;
				case 'V':
					charToPrint = charV;
					break;
				case 'W':
					charToPrint = charW;
					break;
				case 'X':
					charToPrint = charX;
					break;
				case 'Y':
					charToPrint = charY;
					break;
				case 'Z':
					charToPrint = charZ;
					break;
				case '0':
					charToPrint = char0;
					break;
				case '1':
					charToPrint = char1;
					break;
				case '2':
					charToPrint = char2;
					break;
				case '3':
					charToPrint = char3;
					break;
				case '4':
					charToPrint = char4;
					break;
				case '5':
					charToPrint = char5;
					break;
				case '6':
					charToPrint = char6;
					break;
				case '7':
					charToPrint = char7;
					break;
				case '8':
					charToPrint = char8;
					break;
				case '9':
					charToPrint = char9;
					break;
				default:
					printf("\nError in print7seg()\n");
					break;
			}
			if(ch != ' ')
			{
				for(k = 0, l = i * charWidth; k < charWidth; k++, l++)	// print a row of array
				{
					printf("%c", charToPrint[l]);
				}
			}
			j++;
			ch = convertedString[j];
			for(k = 0; k < CHAR_GAP; k++)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}

void defineLetterInArray()
{
	int i, j, k, l;

	k = sizeof(charArr) / sizeof(charArr[0]);

	// fill array with space character ' '
	for(j = 0; j < k; j++)
	{
		FILL_SPACES(charArr[j]);
	}

	// character 'A'
	fillCharArr(charA, MIDDLE_ROW);
	fillCharArr(charA, LEFT_COLUMN);
	fillCharArr(charA, RIGHT_COLUMN);
	fillCharArr(charA, TOP_ROW);

	// character 'B'
	fillCharArr(charB, TOP_ROW);
	fillCharArr(charB, BOTTOM_ROW);
	fillCharArr(charB, MIDDLE_ROW);
	fillCharArr(charB, LEFT_COLUMN);
	fillCharArr(charB, RIGHT_COLUMN);
	charB[charWidth - 1] = '\\';
	charB[(charWidth * charHeight) - 1] = '/';

	// character 'C'
	fillCharArr(charC, LEFT_COLUMN);
	fillCharArr(charC, TOP_ROW);
	fillCharArr(charC, BOTTOM_ROW);

	// character 'D'
	fillCharArr(charD, LEFT_COLUMN);
	fillCharArr(charD, RIGHT_COLUMN);
	fillCharArr(charD, TOP_ROW);
	fillCharArr(charD, BOTTOM_ROW);
	charD[charWidth - 1] = '\\';
	charD[(charWidth * charHeight) - 1] = '/';

	// character 'E'
	fillCharArr(charE, MIDDLE_ROW);
	fillCharArr(charE, LEFT_COLUMN);
	fillCharArr(charE, TOP_ROW);
	fillCharArr(charE, BOTTOM_ROW);

	// character 'F'
	fillCharArr(charF, TOP_ROW);
	fillCharArr(charF, MIDDLE_ROW);
	fillCharArr(charF, LEFT_COLUMN);

	// character 'G'
	fillCharArr(charG, TOP_ROW);
	fillCharArr(charG, BOTTOM_ROW);
	fillCharArr(charG, LEFT_COLUMN);
	fillCharArr(charG, BOTTOM_RIGHT_COLUMN);
	i = (charWidth * (charHeight / 2)) + (charWidth / 2);	// midpoint of G
	for(j = charWidth / 2, k = 0; k < j; k++)
	{
		charG[i] = '=';
		i++;
	}

	// character 'H'
	fillCharArr(charH, MIDDLE_ROW);
	fillCharArr(charH, LEFT_COLUMN);
	fillCharArr(charH, RIGHT_COLUMN);

	// character 'I'
	fillCharArr(charI, CENTER_COLUMN);
	fillCharArr(charI, TOP_ROW);
	fillCharArr(charI, BOTTOM_ROW);

	// character 'J'
	fillCharArr(charJ, RIGHT_COLUMN);
	fillCharArr(charJ, BOTTOM_LEFT_COLUMN);
	fillCharArr(charJ, TOP_ROW);
	fillCharArr(charJ, BOTTOM_ROW);

	// character 'K'
	fillCharArr(charK, LEFT_COLUMN);
	charK[charWidth - 2] = '/';
	i = charWidth - 1;
	j = charWidth - 1;
	k = 0;
	l = (charHeight / 2) - 1;
	while(k < l)
	{
		charK[i] = '/';
		i += j;
		charK[i] = '/';
		i--;
		charK[i] = '/';

		k++;
	}
	i += j + 1;
	charK[i] = '\\';
	j = charWidth + 1;
	i += j;
	k = 0;
	l = (charHeight / 2) - 1;
	while(k < l)
	{
		charK[i] = '\\';
		charK[++i] = '\\';
		i += j;
		k++;
	}

	// character 'L'
	fillCharArr(charL, LEFT_COLUMN);
	fillCharArr(charL, BOTTOM_ROW);

	// character 'M'
	fillCharArr(charM, LEFT_COLUMN);
	fillCharArr(charM, RIGHT_COLUMN);
	i = charWidth + 1;
	j = charWidth + 1;
	k = 1;
	l = charHeight / 2;
	while(k < l)	// for \ line of M
	{
		charM[i] = '\\';
		i += j;
		k++;
	}
	i = (charWidth * 2) - 2;
	j = charWidth - 1;
	k = 1;
	l = charHeight / 2;
	while(k < l)
	{
		charM[i] = '/';
		i += j;
		k++;
	}

	// character 'N'
	fillCharArr(charN, LEFT_COLUMN);
	fillCharArr(charN, RIGHT_COLUMN);
	k = charWidth + 1;
	i = 0;
	j = charWidth * charHeight;
	while(i < j)
	{
		charN[i] = '\\';
		i += k;
	}

	// character 'O'
	fillCharArr(charO, LEFT_COLUMN);
	fillCharArr(charO, RIGHT_COLUMN);
	fillCharArr(charO, TOP_ROW);
	fillCharArr(charO, BOTTOM_ROW);

	// character 'P'
	fillCharArr(charP, MIDDLE_ROW);
	fillCharArr(charP, LEFT_COLUMN);
	fillCharArr(charP, TOP_RIGHT_COLUMN);
	fillCharArr(charP, TOP_ROW);

	// character 'Q'
	fillCharArr(charQ, LEFT_COLUMN);
	fillCharArr(charQ, RIGHT_COLUMN);
	fillCharArr(charQ, TOP_ROW);
	fillCharArr(charQ, BOTTOM_ROW);
	i = (charWidth * (charHeight / 2)) + (charWidth / 2);	// midpoint of Q
	j = charWidth * charHeight;
	while(i < j)
	{
		charQ[i] = '\\';
		i += charWidth + 1;
	}

	// character 'R'
	fillCharArr(charR, LEFT_COLUMN);
	fillCharArr(charR, TOP_RIGHT_COLUMN);
	fillCharArr(charR, MIDDLE_ROW);
	fillCharArr(charR, TOP_ROW);
	i = ((charHeight / 2) * charWidth) + 1;
	j = charWidth * charHeight;
	k = charWidth + 1;
	while(i < j)
	{
		charR[i] = '\\';
		i += k;
	}
	// character 'S'
	fillCharArr(charS, MIDDLE_ROW);
	fillCharArr(charS, TOP_ROW);
	fillCharArr(charS, BOTTOM_ROW);
	fillCharArr(charS, TOP_LEFT_COLUMN);
	fillCharArr(charS, BOTTOM_RIGHT_COLUMN);

	// character 'T'
	fillCharArr(charT, CENTER_COLUMN);
	fillCharArr(charT, TOP_ROW);

	// character 'U'
	fillCharArr(charU, LEFT_COLUMN);
	fillCharArr(charU, RIGHT_COLUMN);
	fillCharArr(charU, BOTTOM_ROW);

	// character 'V'
	fillCharArr(charV, TOP_LEFT_COLUMN);
	fillCharArr(charV, TOP_RIGHT_COLUMN);
	i = (charWidth*charHeight) - (charWidth/2) - 1;
	j = i;
	k = charWidth + 1;
	while(i % charWidth != 0)
	{
		charV[i] = '\\';
		charV[j] = '/';
		j -= charWidth - 1;
		i -= k;
	}
	i = (charWidth*charHeight) - (charWidth/2) - 1;
	charV[i] = 'V';

	// character 'W'
	fillCharArr(charW, LEFT_COLUMN);
	fillCharArr(charW, RIGHT_COLUMN);
	i = (charWidth*charHeight) - charWidth;
	j = ((charHeight/2) * charWidth) + (charWidth/2);	// midpoint of W
	k = (charWidth * charHeight) - 1;
	while(i > j)
	{
		charW[i] = '/';
		i -= charWidth - 1;
		charW[k] = '\\';
		k -= (charWidth + 1);
	}
	charW[j] = '^';

	// character 'X'
	i = 0;
	j = charWidth * charHeight;
	k = charWidth - 1;
	l = ((charHeight/2) * charWidth) + (charWidth/2);	// midpoint of X
	while(i < j)
	{
		charX[i] = '\\';
		charX[k] = '/';
		i += charWidth + 1;
		k += (charWidth - 1);
	}
	charX[l] = 'X';

	// character 'Y'
	i = 0;
	j = charWidth - 1;
	k = ((charHeight/2) * charWidth) + (charWidth/2);	// midpoint of Y
	while(i < k)
	{
		charY[i] = '\\';
		charY[j] = '/';
		i += charWidth + 1;
		j += (charWidth - 1);
	}
	for(i = k, j = (charWidth * charHeight); i < j; i += charWidth)
	{
		charY[i] = '|';
	}
	charY[k] = 'Y';

	// character 'Z'
	fillCharArr(charZ, TOP_ROW);
	fillCharArr(charZ, BOTTOM_ROW);
	i = charWidth - 1;
	for(j = 0; j < charHeight; j++)
	{
		charZ[i] = '/';
		i += (charWidth - 1);
	}

	// character '0'
	fillCharArr(char0, LEFT_COLUMN);
	fillCharArr(char0, RIGHT_COLUMN);
	fillCharArr(char0, TOP_ROW);
	fillCharArr(char0, BOTTOM_ROW);
	i = (charWidth * (charHeight / 2)) + (charWidth / 2);	// midpoint of 0
	char0[i] = '0';

	// character '1'
	fillCharArr(char1, CENTER_COLUMN);
	fillCharArr(char1, BOTTOM_ROW);
	for(i = 0, j = charWidth / 2; i < j; i++)
	{
		char1[i] = '=';
	}

	// character '2'
	fillCharArr(char2, TOP_ROW);
	fillCharArr(char2, MIDDLE_ROW);
	fillCharArr(char2, BOTTOM_ROW);
	fillCharArr(char2, BOTTOM_LEFT_COLUMN);
	fillCharArr(char2, TOP_RIGHT_COLUMN);

	// character '3'
	fillCharArr(char3, MIDDLE_ROW);
	fillCharArr(char3, RIGHT_COLUMN);
	fillCharArr(char3, TOP_ROW);
	fillCharArr(char3, BOTTOM_ROW);

	// character '4'
	fillCharArr(char4, MIDDLE_ROW);
	fillCharArr(char4, RIGHT_COLUMN);
	fillCharArr(char4, TOP_LEFT_COLUMN);

	// character '5'
	fillCharArr(char5, TOP_ROW);
	fillCharArr(char5, MIDDLE_ROW);
	fillCharArr(char5, BOTTOM_ROW);
	fillCharArr(char5, TOP_LEFT_COLUMN);
	fillCharArr(char5, BOTTOM_RIGHT_COLUMN);

	// character '6'
	fillCharArr(char6, TOP_ROW);
	fillCharArr(char6, BOTTOM_ROW);
	fillCharArr(char6, MIDDLE_ROW);
	fillCharArr(char6, LEFT_COLUMN);
	fillCharArr(char6, BOTTOM_RIGHT_COLUMN);

	// character '7'
	fillCharArr(char7, RIGHT_COLUMN);
	fillCharArr(char7, TOP_ROW);

	// character '8'
	fillCharArr(char8, MIDDLE_ROW);
	fillCharArr(char8, LEFT_COLUMN);
	fillCharArr(char8, RIGHT_COLUMN);
	fillCharArr(char8, TOP_ROW);
	fillCharArr(char8, BOTTOM_ROW);

	// character '9'
	fillCharArr(char9, TOP_ROW);
	fillCharArr(char9, MIDDLE_ROW);
	fillCharArr(char9, BOTTOM_ROW);
	fillCharArr(char9, RIGHT_COLUMN);
	fillCharArr(char9, TOP_LEFT_COLUMN);


	isCharArrDefined = 1;
}

void fillCharArr(char *arr, enum linePosition pos)
{
	int i, j, k;

	switch(pos)
	{
		case TOP_ROW:
			for(i = 0; i < charWidth; i++)
			{
				arr[i] = '=';
			}
			break;
		case MIDDLE_ROW:
			j = charHeight / 2;
			k = j * charWidth;
			for(i = 0; i < charWidth; i++)
			{
				arr[k] = '=';
				k++;
			}
			break;
		case BOTTOM_ROW:
			j = charHeight - 1;
			k = j * charWidth;
			for(i = 0; i < charWidth; i++)
			{
				arr[k] = '=';
				k++;
			}
			break;
		case LEFT_COLUMN:
			j = charWidth * charHeight;
			for(i = 0; i < j;)
			{
				arr[i] = '|';
				i += charWidth;
			}
			break;
		case CENTER_COLUMN:
			j = charWidth * charHeight;
			for(i = charWidth / 2; i < j; )
			{
				arr[i] = '|';
				i += charWidth;
			}
			break;
		case RIGHT_COLUMN:
			j = charWidth * charHeight;
			for(i = charWidth - 1; i < j;)
			{
				arr[i] = '|';
				i += charWidth;
			}
			break;
		case TOP_LEFT_COLUMN:
			j = (charWidth * charHeight) / 2;
			for(i = 0; i < j;)
			{
				arr[i] = '|';
				i += charWidth;
			}
			break;
		case BOTTOM_LEFT_COLUMN:
			i = charWidth * (charHeight / 2);
			j = charWidth * charHeight;
			while(i < j)
			{
				arr[i] = '|';
				i += charWidth;
			}
			break;
		case TOP_RIGHT_COLUMN:
			for(i = charWidth - 1, j = (((charHeight / 2) + 1) * charWidth); i < j; i += charWidth)
			{
				arr[i] = '|';
			}
			break;
		case BOTTOM_RIGHT_COLUMN:
			j = charWidth * charHeight;
			for(i = (charWidth * (charHeight / 2)) + charWidth - 1; i < j;)
			{
				arr[i] = '|';
				i += charWidth;
			}
			break;
		default:
			printf("\nUndefined value passed in fillCharArr()\n");
			break;
	}
}
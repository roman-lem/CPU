#include "./library/WorkWithFiles.h"
#include <string.h>

//==========================================================================

int main (){

	char* fileBuf = NULL;

	char** pToStr = NULL;

	int nOfStr = 0;

	char Input[100] = {0};
	char Output[100] = {0};

	printf("Input file: \n");
	scanf("%s", Input);

	printf("Output file: \n");
	scanf("%s", Output);
	
	pToStr = ReadInBuf (pToStr, fileBuf, Input, &nOfStr);

	int i;
	for (i = 0; i < nOfStr; i++){

		if (strncmp(pToStr[i], "push ", 5) == 0){

			char temp[100];

			sscanf(pToStr[i], "push %s", temp);

			strcpy(pToStr[i], "1 ");
			strcpy(pToStr[i] + 2, temp);
		}

		if (strncmp(pToStr[i], "pop ", 4) == 0){

			char temp[100];

			sscanf(pToStr[i], "pop %s", temp);

			strcpy(pToStr[i], "2 ");
			strcpy(pToStr[i] + 2, temp);
		}

		if (strncmp(pToStr[i], "add", 3) == 0){

			strcpy(pToStr[i], "3");
		}

		if (strncmp(pToStr[i], "sub", 3) == 0){

			strcpy(pToStr[i], "4");
		}

		if (strncmp(pToStr[i], "mul", 3) == 0){

			strcpy(pToStr[i], "5");
		}

		if (strncmp(pToStr[i], "div", 3) == 0){

			strcpy(pToStr[i], "6");
		}

		if (strncmp(pToStr[i], "end", 3) == 0){

			strcpy(pToStr[i], "-1");
		}
	}

	PutToFile(Output, pToStr, nOfStr);

	free(fileBuf);
	free(pToStr);

	return 0;
}

//==========================================================================

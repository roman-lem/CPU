#include "WorkWithFiles.h"

//---------------------------

int sizeOfFile(char* fileName){

	struct stat stBuf;
	
	if(stat(fileName, &stBuf) == -1){

		return -1;
	}

	return stBuf.st_size;
}

//---------------------------

char** ReadInBuf(char** pToStr, char* fileBuf, char* fileName, int* nOfStr){

	FILE *Text = fopen(fileName, "r");

	if(Text == NULL){

		printf("Check existing of file \"%s\"\n", fileName);

		return pToStr;
	}

	int TextSize = sizeOfFile(fileName);

	if(TextSize == -1){

		printf("Imposible to identify size of file %s\n", fileName);
	}

	fileBuf = (char*) calloc(TextSize + 1, sizeof(*fileBuf));
	
	fread(fileBuf, sizeof(char), TextSize, Text);

	fclose(Text);

	pToStr = (char**) calloc(1, sizeof(*pToStr));

	if(pToStr == NULL){

		printf("Dont possible to give memory for array of pointers\n");

		return pToStr;
	}

	*(pToStr) = fileBuf;

	int i = 0, p = 1;
	for(i = 0; i < TextSize; i++){

		if(*(fileBuf + i) == '\n'){

			*(fileBuf + i) = '\0';

			pToStr = (char**) realloc(pToStr, (p + 1) * sizeof(*pToStr));

			*(pToStr + p++) = fileBuf + (i + 1);
		}
	}

	*nOfStr = p;

	return pToStr;
}

//----------------------------

int StrIsEmpty(char* str){

	int i = 0;
	int flag = 1;
	for(i = 0; *(str + i) != '\0'; i++){

		if( *(str + i) != ' ' ){

			flag = 0;

			break;
		}
	}

	return flag;
}

//----------------------------

void PrintFromArr(char** pToStr, int nOfStr){

	int i = 0;
	for(i = 0; i < nOfStr; i++){

		printf("%s\n", *(pToStr + i));
	}
}

//-----------------------------

void PutToFile(char* fileName, char** pToStr, int nOfStr){

	FILE *file = fopen(fileName, "w");

	int i = 0;
	char flag = 0;
	for(i = 0; i < nOfStr; i++){

		if( !StrIsEmpty(*(pToStr + i)) ){
			fputs(*(pToStr + i), file);
			fputc('\n', file);
		}
	}

	fclose(file);
}

//===============================================================================================================================
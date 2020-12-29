#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <ctype.h>

/**
	* @brief This func get size of files
	*
	*	@param fileName - Name of file
	*
	* @return Size of file in chars
	*/

int sizeOfFile(char* fileName);

/**
	* @brief This func read text from file, and write it to buffer
	*
	*	@param pToStr - Array of pointers on strings
	*
	*	@param fileBuf - Buffer
	*
	*	@param fileName - Name of file 
	*
	* @param nOfStr - Pointer on variable, where need save number of strings
	*
	* @return New pointer on array of pointers
	*/

char** ReadInBuf(char** pToStr, char* fileBuf, char* fileName, int* nOfStr);

/**
	* @brief This func check, does str is empty.
	*
	*	@param pointer to begin of string
	*
	* @return 1, if string is empty, 0, if isn't
	*/

int StrIsEmpty(char* str);

/**
	* @brief This func print strings from pToStr
	*
	*	@param pToStr - Array of pointers on strings
	*
	* @param nOfStr - Number of strings, that need to print
	*/

void PrintFromArr(char** pToStr, int nOfStr);

/**
	* @brief This func write text in file
	*
	*	@param fileName - Name of file
	*
	*	@param pToStr - Array of pointers on strings
	*
	* @param nOfStr - Number of strings, that need to write
	*/

void PutToFile(char* fileName, char** pToStr, int nOfStr);

//===============================================================================================================================
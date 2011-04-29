/*
 * dataall.h
 *
 *	Organization: EasyFly S.A
 *
 *  Created on: 29/10/2008   -  14:59:20
 *  Author:		Daniel Azar
 *  Version		1.0.0
 *
 *	Description This file contains the fundamental structures for the main program to work.
 *
 */

#ifndef DATA_H_
#define DATA_H_

/*
 *	System includes
 */
#include <stdio.h>

/*
 * Project includes
 */

#define MAXLINE 120
#define HEADER 40
#define LINE 2000
typedef unsigned char BYTE;

typedef enum {
	encrypt, decrypt, notInitialized
} modeT;

typedef enum {
	ecb, cfb, ofb, cbc, notInitialized1
} encModeT;

typedef enum {
	aes128, aes192, aes256, des, notInitialized2
} primitiveT;

typedef struct {
	char input[MAXLINE]; 	/*Input file name*/
	char output[MAXLINE]; 	/*output file name*/
	modeT mode; 				/*What mode to use encrypt or decrypt*/
	char pass[LINE]; 		/*Password if necesary else it is \0*/
	char key[LINE]; 			/*Password if necesary else it is \0*/
	char vector[LINE]; 		/*Password if necesary else it is \0*/
	encModeT enc_mode; 		/*encryption mode cbc, ebc, etc*/
	primitiveT primitive	;	/*what primitive to use, AES, DES, etc*/
/*primitive to use*/
} data;

typedef struct {
	BYTE head[HEADER]; 		/*header will be copied to output file.*/
	int cantBits; 			/*number of bits to read of sound data in the file*/
	BYTE * bits; 			/*pointer to the data to be encrypted or decrypted.*/

} wave;

/*
 * Function:		NewData
 * Example:			pdata = NewData();
 * Description:		Creates the space for the data structure and intialize all the ADTs.
 * Precondition:	--
 * Postcondition:	space created
 *
 */
data * NewData(void);

data * getdata(void);

void loadFile();
wave * getFile(void);
void writeFile();
#endif /* DATA_H_ */

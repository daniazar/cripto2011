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

typedef unsigned char BYTE;

/*
typedef enum
{
	TEXT, KML
} outT;
*/
typedef struct
{
	/*outT outType;*/
	char input[MAXLINE];
	char output[MAXLINE];

} data;



typedef struct
{
	BYTE head[HEADER];
	int cantBits;
	BYTE * bits;


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

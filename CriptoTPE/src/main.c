/*
 * main.c
 *
 *	Organization: EasyFly S.A
 *
 *  Created on: 29/10/2008   -  14:59:49
 *  Author:		Daniel Azar
 *  Version		1.0.0
 *
 */

/*
 *	System includes
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * Project includes
 */

#include "../include/dataall.h"
#include "../include/command.h"

int login( void)
{
	return 1;
}

int main(int argc, char **argv) {
	data * pdata;
	pdata = NewData();

	linecommand(argc, argv);


	if(!login())
	{
		printf( "Not a valid user\n");
		return EXIT_FAILURE;
	}

	loadFile();
	wave * w = getFile();
	int i;
/*	for(i=0;i < 40 ;i++)
		{
			printf("Header bis %d, %c \n", i, w->head[i]);
		}
	*/printf("Cantidad de bits %d\n" , w->cantBits);

/*	for(i=0;i <= w->cantBits;i++)
	{
		printf("bits %d, %c \n", i, *(w->bits +i));
	}
*/
	return EXIT_SUCCESS;



}



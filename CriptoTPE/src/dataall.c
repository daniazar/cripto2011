/*
 * dataall.c
 *
 *	Organization: EasyFly S.A
 *
 *  Created on: 29/10/2008   -  14:58:59
 *  Author:		Daniel Azar
 *  Version		1.0.0
 *
 */

/*
 *	System includes
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * Project includes
 */

#include "../include/dataall.h"
#include "../include/Error.h"



data *p;
wave * w;



data * getdata(void)
{
	return p;
}

wave * getFile(void)
{
	return w;
}

data * NewData(void)
{
	p = calloc(1, sizeof( data));
	if (p == NULL)
		Error("No memory for data structure");
	return p;
}



wave * NewFile(void)
{
	wave * pointer;
	pointer = calloc(1, sizeof( wave));
	if (pointer == NULL)
		Error("No memory for wave structure");
	return pointer;
}

void loadFile()
{
	w = NewFile();
	static FILE *arch;

	if ((arch =fopen(p->input,"rb")) == NULL)
	{
		Error("In open of configuration file:");
	}

	if (fread(w->head, sizeof( BYTE) , HEADER , arch)  != HEADER)
	{
		Error("Error in configuration file.");
	}


	if (fread( & (w->cantBits), 4 , 1 , arch)  != 1)
	{
		Error("Error in configuration file.");
	}

	w->bits = calloc(w->cantBits, sizeof(BYTE));
	if (w->bits == NULL)
		Error("No memory for wave structure");

	if (fread(w->bits, sizeof( BYTE) , w->cantBits , arch)  != w->cantBits)
	{
		Error("Error in configuration file.");
	}

	if (fclose(arch)== EOF)
	{
		Error("In close of configuration file");
	}

}

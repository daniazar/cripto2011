/*
 * Error.c
 *
 *	Organization: EasyFly S.A
 *
 *  Created on: 31/10/2008   -  00:18:13
 *  Author:		Daniel Azar
 *  Version		1.0.0
 *
 *	Description: Fatal function Error
 */


/*
 *	System includes
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * Project includes
 */

#include "../include/color.h"


void Error(char * message)
{
	perror("Error");
	fprintf(stderr,"%s%s\n%s", BLUE,message, WHITE);
	exit(EXIT_FAILURE);
}

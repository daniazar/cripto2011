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
#include "../include/verify.h"
#include "../include/testingCrypt.h"


int main(int argc, char **argv) {
	data * pdata;

	pdata = NewData();
	printf("aca0");
	fflush(stdin);
	linecommand(argc, argv);
	Verify();
	printf("aca1");
	fflush(stdin);

	loadFile();
	printf("aca2");
	fflush(stdin);

	wave * w = getFile();

	uncipher(w,pdata);

	/*printf("Cantidad de bits %d\n" , w->cantBits);
	 */

	writeFile();
	return EXIT_SUCCESS;



}



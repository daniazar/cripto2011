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
	linecommand(argc, argv);
	Verify();
	loadFile();
	hasPassPass();
	wave * w = getFile();
	if(pdata->mode == encryption){
		cipher(w,pdata);
	}else{
		uncipher(w,pdata);
	}

	/*printf("Cantidad de bits %d\n" , w->cantBits);
	 */

	writeFile();
	return EXIT_SUCCESS;



}



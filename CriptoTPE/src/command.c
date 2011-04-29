/*
 * command.c
 *
 *	Organization: EasyFly S.A
 *
 *  Created on: 07/11/2008   -  01:35:36
 *  Author:		Daniel Azar
 *  Version		1.0.0
 *
 *	Description: command reader using scanf.
 */

/*
 *	System includes
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * Project includes
 */

#include "../include/command.h"
#include "../include/dataall.h"
#include "../include/verify.h"
#include "../include/Error.h"
#include "../include/color.h"

/***************************************************************************
 *
 *
 ***************************************************************************/

void linecommand(int argc, char **argv) {
	data * pdata;
	pdata = getdata();
	int i = 0;
	while(i < argc){
	/*	printf("%s Argument %i  $ %s%s \n", GREEN, i, WHITE, argv[i] );
	*/

		if (strcmp(argv[i], "-in") == 0) {
			i++;
			printf("%s Input File  $ %s%s \n", GREEN, WHITE, argv[i] );
			strcpy(pdata->input, argv[i]);
		}else
		if (strcmp(argv[i], "-out") == 0) {
			i++;
			printf("%s Output File  $ %s%s \n", GREEN, WHITE, argv[i] );
			strcpy(pdata->output, argv[i]);
		}else
		if (strcmp(argv[i], "-e") == 0) {
			printf("%s Mode Encription  $ %s \n", GREEN, WHITE);
			pdata->mode = encryption;
		}else
		if (strcmp(argv[i], "-d") == 0) {
			printf("%s Mode Decription  $ %s \n", GREEN, WHITE);
			pdata->mode = decryption;
		}else
		if (strcmp(argv[i], "-pass") == 0) {
			i++;
			printf("%s Password $ %s%s \n", GREEN, WHITE, argv[i]);
			strcpy(pdata->pass, argv[i]);
		}else
		if (strcmp(argv[i], "-k") == 0) {
			i++;
			printf("%s Key $, %s%s \n", GREEN, WHITE, argv[i]);
			strcpy(pdata->key, argv[i]);
		}else
		if (strcmp(argv[i], "-iv") == 0) {
			i++;
			printf("%s Vector Inicialization $, %s%s \n", GREEN, WHITE, argv[i]);
			strcpy(pdata->vector, argv[i]);
		}else
		if (strcmp(argv[i], "-a") == 0) {
			i++;
			printf("%s Criptographic Primitive $, %s%s \n", GREEN, WHITE, argv[i]);
			if(strcmp("aes128", argv[i]))
				pdata->primitive = aes128;
			if(strcmp("aes192", argv[i]))
				pdata->primitive = aes192;
			if(strcmp("aes256", argv[i]))
				pdata->primitive = aes256;
			if(strcmp("des", argv[i]))
				pdata->primitive = des;
		}else
		if (strcmp(argv[i], "-m") == 0) {
			i++;
			printf("%s Mode $, %s%s \n", GREEN, WHITE, argv[i]);
			if(strcmp("ecb", argv[i]))
				pdata->enc_mode = ecb;
			if(strcmp("ofb", argv[i]))
				pdata->enc_mode = ofb;
			if(strcmp("cfb", argv[i]))
				pdata->enc_mode = cfb;
			if(strcmp("cbc", argv[i]))
				pdata->enc_mode = cbc;

		}


		i++;
	}


}

/*
 * verify.c
 *
 *	Organization: EasyFly S.A
 *
 *  Created on: 03/11/2008   -  17:24:35
 *  Author:		Daniel Azar
 *  Version		1.0.0
 *
 *	Description:
 */


/*
 *	System includes
 */

#include <string.h>

/*
 * Project includes
 */

#include "../include/dataall.h"
#include "../include/Error.h"

void Verify(void)
{
	data * pdata = getdata();
	if(pdata->primitive == notInitialized2)
		Error("Invalid command, encryption primitive.\n\t-a <aes128|aes192|aes256|des>");
	if(pdata->enc_mode == notInitialized1)
		Error("Invalid command, block cipher mode.\n\t-m <ecb|cfb|ofb|cbc>");
	if(pdata->mode == notInitialized)
			Error("Not specified to encrypt or decrypt\n\tuse -e or -d.");
	if(pdata->input[0]== '\0')
		Error("invalid input file.\n\t-in audiofile");
	if(pdata->output[0]== '\0')
		Error("invalid output file.\n\t-out audiofile");
	if(pdata->pass[0]== '\0' && pdata->key[0]== '\0')
		Error("you must specify a password or a key an a vector.\n\t-pass password \n\t-K key -iv initialvector");

}



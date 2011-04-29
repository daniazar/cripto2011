/*
 * command.h
 *
 *	Organization: EasyFly S.A
 *
 *  Created on: 07/11/2008   -  01:35:50
 *  Author:		Daniel Azar
 *  Version		1.0.0
 *
 *	Description:
 */


/*
 *	System includes
 */


/*
 * Project includes
 */
#include "dataall.h"

#ifndef COMMAND_H_
#define COMMAND_H_



void commands(data * d);

/*
 * Function:		linecommand
 * Example:			linecommand(d);
 * Description:		Analize the argument and determinate what to do.
 * Precondition:	there should be arguments.
 * Postcondition:	All input arguments processed.
 *
 */
void linecommand(int argc, char **argv);


#endif /* COMMAND_H_ */

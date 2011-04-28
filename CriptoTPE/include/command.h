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


/*
 * Function:		commands
 * Example:			commands(d);
 * Description:		While there are commands or command End is received, it analyze the input
 * 					 and do the corresponding procedure
 * Precondition:	data initialized.
 * Postcondition:	No more command from input
 *
 */

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

/*
 * Function:		InsertAllflight
 * Example:			void InsertAllflight(d, archivo);
 * Description:		Inserts all the flights that have correct format in file archivo.
 * Precondition:	data initialized, File archivo must exist.
 * Postcondition:	All flights added
 *
 */

void InsertAllflight(data * d, char * archivo);


/*
 * Function:		InsertAllAirp
 * Example:			InsertAllAirp(d, archivo);
 * Description:		Inserts all the airport that have correct format in file archivo.
 * Precondition:	data initialized, File archivo must exist.
 * Postcondition:	All airports added
 *
 */

void InsertAllAirp(data * d, char * archivo);






#endif /* COMMAND_H_ */

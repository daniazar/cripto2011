/*
 * Error.h
 *
 *	Organization: EasyFly S.A
 *
 *  Created on: 31/10/2008   -  00:18:40
 *  Author:		Daniel Azar
 *  Version		1.0.0
 *
 *	Description: Fatal function Error
 */


/*
 *	System includes
 */


/*
 * Project includes
 */

#ifndef ERROR_H_
#define ERROR_H_

/*
 * Function:		Error( message);
 * Example:			Error("No memory")
 * Description:		Prints a message to stderr and call exit(EXIT_FAILURE
 * Precondition:	Fatal Error
 * Postcondition:	Close the program.
 *
 */

void Error (char * message);

#endif /* ERROR_H_ */

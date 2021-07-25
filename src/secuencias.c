/*=============================================================================
 * Author: pablo <pablomorzan@gmail.com>
 * Date: 2021/06/14
 * Version: 1.0
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "secuencias.h"

/*=====[Definition macros of private constants]==============================*/

/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Main function, program entry point after power on or reset]==========*/


void activarSecuencia(punteroSecuencias *ptrSeq1, bool_t sequence){       /* psecuencia apunta a una secuencia de leds o arreglo de gpioMap_t */


	if ( !sequence ){                    //elección de sentido de desplazamiento en sequiencia
	 ptrSeq1->pDesplaza++;
	}
	else{
	 ptrSeq1->pDesplaza--;
	}

	if ( ptrSeq1->pDesplaza < ptrSeq1->pInicio ){
	 ptrSeq1->pDesplaza = ptrSeq1->pFinal;
	}
	if ( ptrSeq1->pDesplaza > ptrSeq1->pFinal ){
	 ptrSeq1->pDesplaza = ptrSeq1->pInicio;
	}

	apagarLeds();
	encenderLed(*(ptrSeq1->pDesplaza));


}



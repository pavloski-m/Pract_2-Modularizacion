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


void activarSecuencia(punteroSecuencias *ptrSeq1, bool_t sequence, uint16_t *tiempos, delay_t *delay, uint8_t seqSize){       /* psecuencia apunta a una secuencia de leds o arreglo de gpioMap_t */

	static uint8_t indice = 0;

	if ( !sequence ){                    //elección de sentido de desplazamiento en sequiencia
	 ptrSeq1->pDesplaza++;
	 indice++;
	}
	else{
	 ptrSeq1->pDesplaza--;
	 indice--;
	}

	if ( ptrSeq1->pDesplaza < ptrSeq1->pInicio ){
	 ptrSeq1->pDesplaza = ptrSeq1->pFinal;
	 indice=seqSize-1;
	}
	if ( ptrSeq1->pDesplaza > ptrSeq1->pFinal ){
	 ptrSeq1->pDesplaza = ptrSeq1->pInicio;
	 indice=0;
	}

	apagarLeds();
	delayWrite(delay, tiempos[indice]);

	if(*(ptrSeq1->pDesplaza)!=0){
		encenderLed(*(ptrSeq1->pDesplaza));
	}


}



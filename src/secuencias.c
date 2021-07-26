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


void activarSecuencia(punteroSecuencias *ptrSeq, bool_t sequence, uint16_t *tiempos, delay_t *delay){       /* psecuencia apunta a una secuencia de leds o arreglo de gpioMap_t */

	static uint8_t indice = 0;

	if ( !sequence ){                    //elección de sentido de desplazamiento en sequiencia
	 ptrSeq->pDesplaza++;
	 indice++;
	}
	else{
	 ptrSeq->pDesplaza--;
	 indice--;
	}

	if ( ptrSeq->pDesplaza < ptrSeq->pInicio ){
	 ptrSeq->pDesplaza = ptrSeq->pFinal;
	 indice=ptrSeq->seqSize;
	}
	if ( ptrSeq->pDesplaza > ptrSeq->pFinal ){
	 ptrSeq->pDesplaza = ptrSeq->pInicio;
	 indice=0;
	}

	apagarLeds();
	delayWrite(delay, tiempos[indice]);

	if(*(ptrSeq->pDesplaza)!=0){
		encenderLed(*(ptrSeq->pDesplaza));
	}


}



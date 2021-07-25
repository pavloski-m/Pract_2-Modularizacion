/*=============================================================================
 * Author: Dany Tito - Pablo Morzán
 * Date: 2021/07/07
 * Version: 1.0
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "main.h"

/*=====[Definition macros of private constants]==============================*/

/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/

uint8_t tecla = 0;
bool_t sequence = 0;

/*=====[Definitions of private global variables]=============================*/

/*=====[Main function, program entry point after power on or reset]==========*/


int main(void){


   /* ------------- INICIALIZACIONES ------------- */

   /* Inicializar la placa */
   boardConfig();

   /* Variable de Retardo no bloqueante */
   delay_t delayLed;

   /* Inicializar Retardo no bloqueante con tiempo en milisegundos
      (500ms = 0,5s) */
   delayConfig( &delayLed, 500 );

   /* Declaración de variables locales */

   uint8_t seqSize = 0;

   /* Declaración de secuencias*/
   gpioMap_t secuencia[] = {LED1, LED2, LED3, LEDB};
   //gpioMap_t secuencia[] = {LED2, LEDB, LED1, LED3, LEDG};



   seqSize = sizeof(secuencia)/sizeof(gpioMap_t);

   punteroSecuencias ptrSec = {.pDesplaza = secuencia, .pInicio = &secuencia[0], .pFinal = &secuencia[seqSize-1]};

 /* ------------- REPETIR POR SIEMPRE ------------- */


    while(1) {


    	tecla = leerTecla();

    	if(tecla != 0){
    		accionTecla(tecla, &delayLed, &sequence);
    	}

    	if ( delayRead( &delayLed ) ){

    		activarSecuencia(&ptrSec, sequence);

	  	}


   } // cierrra while


/* NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa no es llamado
      por ningun S.O. */

    return 0 ;

} // cierra int main(void)



//================================FUNCICONES=================================



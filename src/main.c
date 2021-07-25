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

   uint8_t seqSize1 = 0;
   uint8_t seqSize2 = 0;
   uint8_t seqSize3 = 0;
   uint8_t estado = 0;
   uint8_t flag = 0;

   /* Declaración de secuencias*/
   //gpioMap_t secuencia[] = {LED1, LED_OFF, LED2, LED3};
   //uint16_t tiemposSecuencia[] ={1000, 500, 2000, 3000};
   gpioMap_t secuencia1[] = {LED2, LED1, LED3};
   uint16_t tiemposSecuencia1[] ={3000, 500, 1000};

   gpioMap_t secuencia2[] = {LED1, LED_OFF};
   uint16_t tiemposSecuencia2[] ={500, 500};

   gpioMap_t secuencia3[] = {LED2, LED_OFF};
   uint16_t tiemposSecuencia3[] ={1000, 1000};


   seqSize1 = sizeof(secuencia1)/sizeof(gpioMap_t);
   punteroSecuencias ptrSec1 = {.pDesplaza = secuencia1, .pInicio = &secuencia1[0], .pFinal = &secuencia1[seqSize1-1]};

   seqSize2 = sizeof(secuencia2)/sizeof(gpioMap_t);
   punteroSecuencias ptrSec2 = {.pDesplaza = secuencia2, .pInicio = &secuencia2[0], .pFinal = &secuencia2[seqSize2-1]};

   seqSize3 = sizeof(secuencia3)/sizeof(gpioMap_t);
   punteroSecuencias ptrSec3 = {.pDesplaza = secuencia3, .pInicio = &secuencia3[0], .pFinal = &secuencia3[seqSize3-1]};

 /* ------------- REPETIR POR SIEMPRE ------------- */


    while(1) {


    	tecla = leerTecla();

    	if (tecla==0){
    		flag = 0;
    	}

    	if (tecla==2 && flag==0){
    		estado++;
    		flag=1;

    	   	if (estado>2){
    	   		estado=0;
    	   	}
    	}

//    	if(tecla != 0){
//    		accionTecla(tecla, &delayLed, &sequence);
//    	}

    	if ( delayRead( &delayLed ) ){

    		switch(estado){
    			case 0:
    				activarSecuencia(&ptrSec1, sequence, tiemposSecuencia1, &delayLed, seqSize1);
    				break;
    			case 1:
    				activarSecuencia(&ptrSec2, sequence, tiemposSecuencia2, &delayLed, seqSize2);
    				break;
    			case 2:
    				activarSecuencia(&ptrSec3, sequence, tiemposSecuencia3, &delayLed, seqSize3);
    				break;
    		}


    		//activarSecuencia(&ptrSec, sequence, tiemposSecuencia, &delayLed, seqSize);

	  	}


   } // cierrra while


/* NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa no es llamado
      por ningun S.O. */

    return 0 ;

} // cierra int main(void)



//================================FUNCICONES=================================



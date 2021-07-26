/*=============================================================================
 * Author: Dany Tito - Pablo Morzán
 * Date: 2021/07/26
 * Version: 1.0
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "teclas.h"

/*=====[Definition macros of private constants]==============================*/

/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Main function, program entry point after power on or reset]==========*/


//================================FUNCICONES=================================

//-----------------ACCIÓN DE TECLAS -----------------------

uint8_t leerTecla (){

uint8_t tecla = 0;

	for (int j=1; j<5; j++){
		tecla += j * !(gpioRead(TEC1 + j - 1));
		if (tecla > 0){                            //Se pone para evitar el error de presionar "TEC1" y "TEC2" juntas y que entienda "TEC3"
			break;
		}
	}
return tecla;
}

//-----------------LECTURA DE TECLAS-----------------------

void accionTecla(uint8_t tecla, delay_t *delayLed, bool_t *sequence){

	switch(tecla){

		case 1:
			*sequence=1;
			break;
		case 2:
			 delayWrite( delayLed, 150 );
			 break;
		case 3:
			 delayWrite( delayLed, 750 );
			 break;
		case 4:
			*sequence=0;
			break;
	}

}

   /* delayRead retorna TRUE cuando se cumple el tiempo de retardo */




/*=============================================================================
 * Author: pablo <pablomorzan@gmail.com>
 * Date: 2021/06/14
 * Version: 1.0
 *===========================================================================*/

/*=====[Avoid multiple inclusion - begin]====================================*/

#ifndef __SECUENCIA_H__
#define __SECUENCIA_H__

/*=====[Inclusions of public function dependencies]==========================*/

//#include <stdint.h>
//#include <stddef.h>
#include "leds.h"

/*=====[C++ - begin]=========================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*=====[Definition macros of public constants]===============================*/

/*=====[Public function-like macros]=========================================*/

/*=====[Definitions of public data types]====================================*/

typedef struct {              // definimos este struct para manejo de los punteros a secuencias
	gpioMap_t *pDesplaza;
	gpioMap_t *pInicio;
	gpioMap_t *pFinal;
	uint8_t seqSize;
}punteroSecuencias;


/*=====[Prototypes (declarations) of public functions]=======================*/

/*=============================================================================
 * Function: activarSecuencia
 * Description: Se recorre la secuencia y se comprueba que no se sobrepasen el
 *   principio y final de la misma. Se mantiene el cambio de sentido de los
 *   puntos 1 y 2.
 * Input: estructura en donde se encuentran los punteros de inicio, fin y desplazamiento de la secuencia y el tamaño de la misma.
 * 		  variable que hace referencia al sentido de desplazamiento (puntos 1 y 2)
 * 		  puntero al arreglo en donde se colocan los tiempos de la secuencia
 * 		  puntero al delay para poder modificar los tiempos desde la función.
 * Output: no se devuelve nada por parametro. Al finalizar la función se modifica
 * 		  la posición del puntero de desplazamiento, el valor del delay y el índice
 * 		  que hace referencia al puntero de tiempos.
 *===========================================================================*/

void activarSecuencia(punteroSecuencias *ptrSeq, bool_t sequence, uint16_t *tiempos, delay_t *delay);

/*=====[Prototypes (declarations) of public interrupt functions]=============*/

/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Avoid multiple inclusion - end]======================================*/

#endif /* __SECUENCIA_H__ */

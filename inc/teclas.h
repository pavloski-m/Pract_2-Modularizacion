/*=============================================================================
 * Author: pablo <pablomorzan@gmail.com>
 * Date: 2021/06/14
 * Version: 1.0
 *===========================================================================*/

/*=====[Avoid multiple inclusion - begin]====================================*/

#ifndef __TECLAS_H__
#define __TECLAS_H__

/*=====[Inclusions of public function dependencies]==========================*/
#include "sapi.h"
/*=====[C++ - begin]=========================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*=====[Definition macros of public constants]===============================*/

/*=====[Public function-like macros]=========================================*/

/*=============================================================================
 * Function: leerTecla
 * Description: Realiza un chequeo del estado de las teclas de la placa EDU-CIAA (TEC1,..,TEC4)
 * Inpunt: No se le pasan parámetros. Accede al estado de las teclas 0 presionado - 1 sin presionar
 * Output: Devuelve que tecla está presionada. En caso de presionar dos, se devuelve la de valor de referencia mas bajo.
 *===========================================================================*/
uint8_t leerTecla ();


/*=============================================================================
 * Function: accionTecla
 * Description: Dependiendo la tecla que se presiona se realizan distintas acciones
 * 		TEC1:secuencia con desplazamiento decreciente
 * 		TEC2:tiempo de permanencia de encendido del led: 150 ms
 * 		TEC3:tiempo de permanencia de encendido del led: 750 ms
 * 		TEC4:secuencia con desplazamiento creciente
 * Inpunt: tecla presionada, puntero a varible que configura el retardo y al sentido de la secuencia
 * Output: No se devuelve nada. Se modifican las variables de input
 *===========================================================================*/
void accionTecla(uint8_t tecla, delay_t *delayLed, bool_t *sequence);

/*=====[Definitions of public data types]====================================*/

/*=====[Prototypes (declarations) of public functions]=======================*/

/*=====[Prototypes (declarations) of public interrupt functions]=============*/

/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Avoid multiple inclusion - end]======================================*/

#endif /* __LEDS_H__ */

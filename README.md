# Pract_2-Modularizacion

--------------------

Practica clase 3 - Asignatura: Programación de microcontroladores



Integrantes:  

   -Tito, Dany
   
   -Morzán, Pablo

--------------------


En este código se evoluciona sobre las actividades solicitadas en el trabajo práctico 2, por lo que el código para cumplir con los puntos 1 y 2 se pueden observar en commits previos al entregado.

Se realiza un desarrollo diferente al propuesto en el ejemplo. Según nuestro punto de vista al pensar el ejercicio la jerarquía aquí planteada nos pareció mas fácil de implementar sin perder funcionalidad.


           main
        _____|_____
       |           |
    teclas     secuencias
                   |
                  leds
      

--------------------

==== Condiciones de funcionamiento ====

Dependencias externas:

 -sAPI.h

 -Usar delay no bloqueantes

--------------------

==== Objetivo =====

---------------------------------

1) Modularizar el ejercicio 1 de la práctica 1 en los siguientes módulos de software:

  a) main.c, main.h

  b) secuencias.c secuencias.h

  c) led.c, led.h
 
  d) teclas.c teclas.h

  Asignar las funciones solicitadas en la práctica 1 al módulo que corresponda y aplicar los conceptos de público y privado para funciones, variables y constantes de cada módulo.

---------------------------------
  
2) Modificar la función activarSecuencia para que admita un segundo parámetro que indique el tiempo de destello de cada led de la secuencia individualmente

---------------------------------

3) Implementar una aplicación de semáforo como secuencias de leds:

  El semáforo debe tener los siguientes modos de operación:
    Normal: secuencia de leds: rojo 3 s, amarillo 500 mS, verde 1s, rojo nuevamente....
    Desconectado: led amarillo intermitente cada 500 mS.
    Alarma: rojo intermitente cada 1 s

  Con la tecla 2 de la EDU-CIAA-NXP se debe poder cambiar el modo de operación del semáforo a normal. Cada vez que se pulse, se debe cambiar en el siguiente orden:

  Normal, desconectado, alarma, normal, etc...

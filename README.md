# Proyecto PSP 1er Trimestre - Documentación de Cambios

## comandosExpandido
Se ha introducido una nueva opción para elegir entre las funciones `system()` y `execvp` al ejecutar comandos en la shell.

## primerTestUnitario
Se modificó el código principal para que, en lugar de ejecutar únicamente el comando `ls`, ahora ejecute el comando que el usuario ingrese por pantalla.

A partir del código modificado anteriormente, se corrigió el código original del método para evitar falsos positivos.

## test_unitario_con_historial
Se ha tomado el código del primerTestUnitario y se realizaron dos modificaciones para permitir la introducción de un array bidimensional de historial. Se agregaron dos comandos para añadir comandos al historial y para leer el historial.

- El test unitario ahora verifica la longitud del historial.
- La función comandos ahora comprueba el tiempo de ejecución.

## comandosPersonalizados
Se han añadido más comandos que afectan la configuración de la shell, como `changeNameShell`, que cambia el nombre de la shell. Se agregó un comando adicional, `opextra`, para consultar todos los comandos disponibles.

- Se implementó un control de excepciones que informa al usuario sobre posibles errores.

Además, se menciona la existencia de un comando oculto llamado `comandoOculto` y se sugiere su revisión a Oscar.

## test_negativo
Se corrigió el archivo test_unitario_2.c. Para que la prueba sea considerada "pasada", se ajustó la lógica de manejo de errores en la función `ejecutarComando`. En lugar de retornar -1 en caso de error al crear el proceso hijo, ahora se imprime un mensaje de error y se sale con un código de error correspondiente.

Se incluye una captura de pantalla para ilustrar el cambio.
<div>
 <img width="427" alt="Captura de pantalla 2023-12-02 a las 19 41 00" src="https://github.com/OxidoDeNiquel/proyecto_psp/assets/119584115/484e81a2-3d28-47c2-b612-af1f9e552cbe">
</div>

## test_negativo_letra
Se agregó una verificación para confirmar si el primer carácter del comando es una letra antes de continuar con la ejecución. En caso de que no sea una letra, se imprime un mensaje de error.

Se incluye una captura de pantalla para ilustrar esta modificación.

<div>
 <img width="443" alt="Captura de pantalla 2023-12-02 a las 20 01 19" src="https://github.com/OxidoDeNiquel/proyecto_psp/assets/119584115/c30f2e4c-b86c-4c0a-9b15-98f28f05ec92">
</div>

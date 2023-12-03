# Proyecto PSP 1er Trimestre - Documentación de Cambios

## comandosExpandido
Se ha introducido una nueva opción para elegir entre las funciones `system()` y `execvp` al ejecutar comandos en la shell.
<div>
 <img width="336" alt="Captura de pantalla 2023-12-03 a las 14 16 39" src="https://github.com/OxidoDeNiquel/proyecto_psp/assets/119584115/29535804-73cd-401e-b5f0-ff2e50d9f422">
</div>
<div>
 <img width="1215" alt="Captura de pantalla 2023-12-03 a las 14 19 35" src="https://github.com/OxidoDeNiquel/proyecto_psp/assets/119584115/51031d7c-688e-457d-8a13-69edaf9df84b">
</div>
<div>
<img width="1204" alt="Captura de pantalla 2023-12-03 a las 14 22 16" src="https://github.com/OxidoDeNiquel/proyecto_psp/assets/119584115/f20af9ce-3c4e-4b6c-8e11-d35043c53c17">
</div>

## primerTestUnitario
Se modificó el código principal para que, en lugar de ejecutar únicamente el comando `ls`, ahora ejecute el comando que el usuario ingrese por pantalla.
<div>
 <img width="540" alt="Captura de pantalla 2023-12-03 a las 14 30 35" src="https://github.com/OxidoDeNiquel/proyecto_psp/assets/119584115/b02ae8f9-2bdc-479a-898b-3b055d6f9c1c">
</div>

A partir del código modificado anteriormente, se corrigió el código original del método para evitar falsos positivos.


<div>
 <img width="513" alt="Captura de pantalla 2023-12-03 a las 14 35 50" src="https://github.com/OxidoDeNiquel/proyecto_psp/assets/119584115/1cd1169f-d6a7-4118-a19e-d23f23836a36">
</div>

## test_unitario_con_historial
Se ha tomado el código del primerTestUnitario y se realizaron dos modificaciones para permitir la introducción de un array bidimensional de historial. Se agregaron dos comandos para añadir comandos al historial y para leer el historial.
<div>
 <img width="402" alt="Captura de pantalla 2023-12-03 a las 14 48 20" src="https://github.com/OxidoDeNiquel/proyecto_psp/assets/119584115/8fb9803f-f196-4f15-84ec-d6afc74ae521">
</div>
- El test unitario ahora verifica la longitud del historial.
  <div>
   <img width="491" alt="Captura de pantalla 2023-12-03 a las 14 34 28" src="https://github.com/OxidoDeNiquel/proyecto_psp/assets/119584115/74159d37-7c0a-49b1-b243-90d38d48a298">
  </div>

- La función comandos ahora comprueba el tiempo de ejecución.
  <div>
   <img width="1204" alt="Captura de pantalla 2023-12-03 a las 14 22 16" src="https://github.com/OxidoDeNiquel/proyecto_psp/assets/119584115/6cc0f1c6-0171-430a-a157-2d6800ef0027">
  </div>

## comandosPersonalizados
Se han añadido más comandos que afectan la configuración de la shell, como `changeNameShell`, que cambia el nombre de la shell. Se agregó un comando adicional, `opextra`, para consultar todos los comandos disponibles.

<img width="218" alt="Captura de pantalla 2023-12-03 a las 12 36 48" src="https://github.com/OxidoDeNiquel/proyecto_psp/assets/119584115/3e3866e1-14ce-472d-ac34-dc69f3aa1e37"> <img width="358" alt="Captura de pantalla 2023-12-03 a las 12 35 29" src="https://github.com/OxidoDeNiquel/proyecto_psp/assets/119584115/eab42332-47e8-4126-b473-410d58eab0a3">

- Se implementó un control de excepciones que informa al usuario sobre posibles errores.
<div>
 <img width="412" alt="Captura de pantalla 2023-12-03 a las 14 41 00" src="https://github.com/OxidoDeNiquel/proyecto_psp/assets/119584115/4eb061ef-f31e-4fdb-a834-b706fcf0ac51">
</div>
Además, se menciona la existencia de un comando oculto llamado `comandoOculto` y se anima su ejecución a Oscar.

## test_negativo
Se corrigió el archivo test_unitario_2.c. Para que la prueba sea considerada "pasada", se ajustó la lógica de manejo de errores en la función `ejecutarComando`. En lugar de retornar -1 en caso de error al crear el proceso hijo, ahora se imprime un mensaje de error y se sale con un código de error correspondiente.

<div>
 <img width="427" alt="Captura de pantalla 2023-12-02 a las 19 41 00" src="https://github.com/OxidoDeNiquel/proyecto_psp/assets/119584115/484e81a2-3d28-47c2-b612-af1f9e552cbe">
</div>

## test_negativo_letra
Se agregó una verificación para confirmar si el primer carácter del comando es una letra antes de continuar con la ejecución. En caso de que no sea una letra, se imprime un mensaje de error.
<div>
 <img width="443" alt="Captura de pantalla 2023-12-02 a las 20 01 19" src="https://github.com/OxidoDeNiquel/proyecto_psp/assets/119584115/c30f2e4c-b86c-4c0a-9b15-98f28f05ec92">
</div>

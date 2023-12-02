# Proyecto PSP 1er Trimestre
## comandos_expandido
 
introduce una nueva opcion para elegir para poder seleccionar entre system() y execvp

## primerTestUnitario
he cambiado el main para que en vez de que se ejecute solo el comando 'ls' se ejecute el comando que el usuario meta por pantalla

## primerTestUnitario
a partir del codigo anterior se ha arreglado el codigo original del metodo para que no de falsos positivos

## test_unitario_con_historial 
he cogido el codigo del primerTestUnitario y he hecho dos modificaciones para poder introducir un array bidimensional de historial, 
dos comandos con los que agregar al historial y leer el historial

-- test unitario ahora comprueba la longitud

--comandos ahora comprueba el tiempo de ejecucion 

## comandosPersonalizados 
he añadido más comandos los cuales editan la shell como `changeNameShell`, que lo que hace es cambiar el nombre a la shell, para consultar todos los comandos he puesto un comando adicional que es `opextra`.

## comandosPersonalizados 
hago un control de excepciones que informe al usuario

Además hay una comando oculto llamado "comandoOculto" que recomiendo que revises Oscar

## test_negativo
he corregido el test_unitario_2.c,  Para que la prueba sea considerada como "pasada", se debe ajustar la lógica de manejo de errores en la función `ejecutarComando`. En lugar de retornar -1 en caso de error al crear el proceso hijo, se debe imprimir el mensaje de error y salir con un código de error correspondiente.
<div>
 <img width="427" alt="Captura de pantalla 2023-12-02 a las 19 41 00" src="https://github.com/OxidoDeNiquel/proyecto_psp/assets/119584115/484e81a2-3d28-47c2-b612-af1f9e552cbe">
</div>

## test_negativo_letra  
se verifica si el primer carácter del comando es una letra antes de continuar con la ejecución. Si no es una letra, se imprime un mensaje de error 

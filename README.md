# proyecto_psp


- Comandos Expandido introduce una nueva opcion para elegir para poder seleccionar entre system() y execvp

--> test_unitario_1 : he cambiado el main para que en vez de que se ejecute solo el comando 'ls' se ejecute el comando que el usuario meta por pantalla

--> primerTestUnitario : a partir del codigo anterior se ha arreglado el codigo original del metodo para que no de falsos positivos

-- test_unitario_con_historial : he cogido el codigo del primerTestUnitario y he hecho dos modificaciones para poder introducir un array bidimensional de historial, 
dos comandos con los que agregar al historial y leer el historial

-- comandosPersonalizados : he añadido más comandos los cuales editan la shell como "changeNameShell", que lo que hace es cambiar el nombre a la shell, para consultar todos los comandos he puesto un comando adicional que es "opextra".

Además hay una comando oculto llamado "comandoOculto" que recomiendo que revises Oscar
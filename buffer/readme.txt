vamos a explicar mediante un programa y a recordar ademas como funciona esto del buffer
el buffer es como un lugar donde se almacenan cosas temporalmente
cuando pedimos que se almacene un dato, este primero entra al buffer.en el buffer se guarda
de la siguiente manera:

    lo primero que escribamos se guarda en el "primer espacio del buffer",
    luego cuando escribamos un espacio, nos va a generar como una "division" en el buffer, para seguir
    lo que tenemos siguiente, y asi sucesivamente si escribimos mas de una palabra en la entrada)

de esta manera, cuando guardemos los datos que se ingresaron pero solamente vamos a almacenar la
primer palabra, el resto de cosas que ingresaron quedan en el buffer y la primer palabra "se elimina".

Teniendo claro esto, ya sabemos por que hay veces que se generan errores en nuestros programas del tipo
que tenemos una entrada tipo int, pero el usuario ingresa "3 23", la primer variable la almacena donde 
queremos, pero el resto lo almacena en otra entrada (si es que la tenemos), generandonos errores, 
pero aqui vamos a ver la manera de limpiar el buffer para que esto no pase
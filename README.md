# Generic Base Converter #

Converte da uint -> stringa in qualsiasi base, e da stringa in qualsiasi base -> uint - Libreria in C


## Esempio ##

In src/ [c'è un piccolo esempio](src/test.c) che converte prima un int in una stringa,
quindi riconverte la stringa in int. Questa è una parte dell'output.

```
src(beta|✚ 1)% ./a.out 
Utilizzando il charset: "01"

Dec = 0, Str = "0"
Str = "0", Dec = 0

Dec = 1, Str = "1"
Str = "1", Dec = 1

Dec = 2, Str = "10"
Str = "10", Dec = 2

Dec = 3, Str = "11"
Str = "11", Dec = 3

Dec = 4, Str = "100"
Str = "100", Dec = 4
...
```

## Funzioni ##

Sono disponibili due funzioni:

 * int_to_str()
 * str_to_int()
 
L'utilizzo mi sembra abbastanza ovvio, comunque in caso di dubbi il sorgente è 
commentato.


## Altre informazioni ##

> This is the Unix philosophy: Write programs that do one thing and do it well.
  Write programs to work together. Write programs to handle text streams, because
  that is a universal interface.


Aggiornamenti: [GitHub](https://github.com/matteoalessiocarrara/generic-base-converter)  
Email: sw.matteoac@gmail.com

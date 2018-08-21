#include <stdio.h>
#include <stdlib.h>

int sonNumeros(char *numeritos)
{
    char *aux = numeritos;
    while(*aux)
    {
        if(!(*aux >= '0' && *aux <= '9'))
        {
            return 0;
        }
        *aux++;
    }
    return 1;
}

escribirTipo(char*numero,int primero){

    FILE *f;

    f=fopen("destruccion.txt","w");

    int tamanio = strlen(numero);
    fwrite(numero , 1 , tamanio , f);

    if(numero[0]=='0'){
        if(numero[1]=='x' || numero[1]=='X'){
            if(sonNumeros(numero+2)&& (numero[2]!=NULL)) fprintf (f, ": Hexadecimal\n");
            else fprintf (f, ": Error\n");

        }
        else{
            if(sonNumeros(numero+1)&& (numero[1]!=NULL)) fprintf (f, ": Octal\n");
            else fprintf (f, ": Error\n");
        }
    }
    else{
       if(sonNumeros(numero)) fprintf (f, ": Decimal\n");
       else fprintf (f, ": Error\n");
    }
    fclose(f);
}

int main ()
{
  char cadena[100];
  char *aux;
  int i=0;
  printf ("Ingrese la cadena para identificar entre Decimal,Octal y Hexadecimal\n",cadena);
  scanf("%s", cadena);
  aux = strtok (cadena,"#");

  while (aux != NULL)
  {
    escribirTipo(aux,i);
    aux = strtok (NULL, "#");
    i++;
  }
  return 0;
}

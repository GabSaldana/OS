
/*******
Programa que crea n archivos con un array de cadenas dentro de ellos, usando llamadas al sistema de ubuntu
GABS
*********
********/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>		
#include <semaphore.h>
 
int main(int args, char *arhv[]){
 
    int files[100];//guarda el file descriptor de cada archivo
    int i;
    char nombre[100];
    int b=0, c=0, l=0;
    char resultado[100];
    char filename[100];
    char cadenas[10][50];
    for(i=0; i<6; i++){
  	     sprintf(filename,"file-%d.txt", i);
  	     files[i]= open(filename ,O_CREAT | O_WRONLY, 0600); 
  	     if(files[i] == -1){
       	   printf("fallo crear y abrir del archivo: %s\n",filename);
             exit(1);
         }
         printf("Dame tu nombre con espacios\n");
         gets(nombre);
         b = 0, c = 0;
         while(nombre[b]!=NULL){   
            if(nombre[b]!=' '){
                  resultado[c]=nombre[b];
                  b++;
                  c++;
             }
             else{
               resultado[c]='\0';
               c=0;
               strcpy(cadenas[l], resultado);
               write(files[i],resultado,strlen(resultado));
               printf("\nEn el array %d tenemos: \n%s",l,cadenas[l]);
               b++;
               l++;
                }
          }//fin while
          resultado[c]='\0';
          strcpy(cadenas[l], resultado);
          write(files[i],resultado,strlen(resultado));
          printf("\nEn el array %d tenemos: %s\n",l,cadenas[l]); 
          close(files[i]);
    }
 
    return 0;
}

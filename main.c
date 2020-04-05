#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void) {
  long * array_a;
  long * result;
	int size = 5;

	array_a = malloc(size * sizeof(long));
  memset(array_a, 4, size * sizeof(long));

	// allochiamo lo spazio di memoria per la copia
	result = malloc(size * sizeof(long));

	memcpy(result, array_a, size * sizeof(long));

  printf("\n\nArray copiato tramite memcpy:\n");
  for(int i=0; i<size; i++){
    printf("%d) %ld \n", i+1, result[0]);
  }


  // INVECE DI MEMCPY POTREI FARE COSì:
  long * destination = result;
  long * source = array_a;
  for (unsigned int i = 0; i < size; i++) {
    destination[i] = source[i];
  }
  
  printf("\n\nArray copiato col metodo alternativo:\n");
  for(int i=0; i<size; i++){
    printf("%d) %ld \n", i+1, result[0]);
  }

  // IMPORTANTE: chi riceve il risultato, dovrà occuparsi di liberare
  // la memoria allocata per la copia dell'array
  free(array_a);
}
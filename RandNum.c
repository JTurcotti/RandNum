#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>


int rand_int() {

  int *buffer = malloc(sizeof(int));
  int dev_ran = open("/dev/random", O_RDONLY);

  read(dev_ran, buffer, sizeof(buffer));

  int rand_int = *buffer;

  free(buffer);
  close(dev_ran);

  return rand_int;
}

int main() {

  int i;
  int rand[10];
  
  printf("Initial set of random ints:\n");
  for (i = 0; i < 10;
       printf("%d ", rand[i++] = rand_int()));
  printf("\n");

  int file = open("rand_out", O_CREAT | O_WRONLY, 0600);
  write(file, rand, sizeof(rand));
  close(file);

  int sand[10];
  
  file = open("rand_out", O_RDONLY, 0600);
  read(file, sand, sizeof(sand));
  close(file);

  printf("Readen and Written set of random ints:\n");
  for (i = 0; i < 10;
       printf("%d ", sand[i++]));
  printf("\n");

  return 0;
}

/***********************************************************
**                        C Tools                         **
**                      Version 2.0                       **
**                                                        **
**             Written by Giuseppe Fiorentino             **
**                 (fiorent@dm.unipi.it)                  **
***********************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "mps_tools.h"

#ifndef RAND_SOURCE
#define RAND_SOURCE "/dev/random"
#endif

/* random functions */
void
randomize(unsigned int seed)
{
  FILE * rf = NULL;
  int read_bytes;

  if (!seed) {
    seed = 1;
    rf = fopen(RAND_SOURCE, "rb");
    if (rf != NULL) {
      read_bytes = fread(&seed, sizeof(int), 1, rf);
      if (read_bytes != 1) {
	warn("Error while acquiring random seed!\n");
      }
      fclose(rf);
    }
  }
  srand(seed);
}

double
drand(void)
{
#ifdef RAND_VAL
  return RAND_VAL;
#else
  return (double) rand() / RAND_MAX;
#endif
}

/* accessing doubles */
double
dbl_set_2dl(double d, long int l)
{
  return ldexp(d, (int) l);
}

void
dbl_get_2dl(double *rd, long int *rl, double d)
{
  int i;

  *rd = frexp(d, &i);
  *rl = i;
}

double
dbl_get_mant(double d)
{
  int i;

  return frexp(d, &i);
}

int
dbl_get_exp(double d)
{
  int i;

  frexp(d, &i);
  return i;
}

/* vector support functions */
void
boolean_vinit(boolean v[], unsigned long int size)
{
  unsigned long int i;

  for (i = 0; i < size; i++)
    v[i] = false;
}

void
char_vinit(char v[], unsigned long int size)
{
  unsigned long int i;

  for (i = 0; i < size; i++)
    v[i] = '\0';
}

void
int_vinit(int v[], unsigned long int size)
{
  unsigned long int i;

  for (i = 0; i < size; i++)
    v[i] = 0;
}

void
long_vinit(long v[], unsigned long int size)
{
  unsigned long int i;

  for (i = 0; i < size; i++)
    v[i] = 0L;
}

void
float_vinit(float v[], unsigned long int size)
{
  unsigned long int i;

  for (i = 0; i < size; i++)
    v[i] = 0.0F;
}

void
double_vinit(double v[], unsigned long int size)
{
  unsigned long int i;

  for (i = 0; i < size; i++)
    v[i] = 0.0;
}
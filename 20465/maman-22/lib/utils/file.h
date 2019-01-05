#ifndef file_h
#define file_h

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  FILE *file;
  char *contents;
  int actualSize;
  int maxSize;
} File;

File *fileConstructor (char *filePath, int initialSize);
void populateContents (File *file);
void destroyFile (File *file);

#endif /* file_h */

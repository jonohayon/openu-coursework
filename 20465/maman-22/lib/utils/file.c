#include <string.h>
#include "file.h"

File *fileConstructor (char *filePath, int initialSize) {
  File *ptr = (File *) malloc(sizeof(File));

  ptr->file = fopen(filePath, "r");
  ptr->contents = (char *) malloc(initialSize * sizeof(char *));
  ptr->actualSize = 0;
  ptr->maxSize = initialSize;

  return ptr;
}

void populateContents (File *file) {
  char c;

  do {
    c = fgetc(file->file);
    if (c == feof(file->file) || c == EOF) break;

    if (file->actualSize == file->maxSize) {
      file->maxSize *= 2;
      file->contents = (char *) realloc(file->contents, file->maxSize * sizeof(char));
    }

    file->contents[file->actualSize++] = c;
  } while (1);
}

void destroyFile (File *file) {
  free(file->contents);
  fclose(file->file);

  file->contents = NULL;
  file->maxSize = file->actualSize = 0;

  free(file);
}

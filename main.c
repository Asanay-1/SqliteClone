#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *buffer;
  size_t buffer_length;
  ssize_t input_length;
} InputBuffer;

// create input buffer: create and initialize InputBuffer struct
InputBuffer *create_input_buffer() {
  InputBuffer *input_buffer = (InputBuffer *)malloc(sizeof(InputBuffer));
  input_buffer->buffer = NULL;
  input_buffer->buffer_length = 0;
  input_buffer->input_length = 0;

  return input_buffer;
}
// print prompt
void print_prompt() { printf("db > "); }

int main(int argc, char *argv[]) {
  InputBuffer *input_buffer = create_input_buffer();

  while (true) {
    print_prompt();
    read_input(create_input_buffer);

    if (strcmp(input_buffer->buffer, ".exit") == 0) {
      close_input_buffer(input_buffer);
      exit(EXIT_SUCCESS);
    } else {
      printf("Unrecognized command '%s' .\n", input_buffer->buffer);
    }
  }
}

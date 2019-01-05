#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "parser.h"

Command *commandConstructor (char *token, void (*function)(void), int numOfArgs) {
  Command *cmd = (Command *) malloc(sizeof(Command));

  cmd->token = token;
  cmd->function = function;
  cmd->numOfArgs = numOfArgs;

  return cmd;
}

Command *findCommandByToken (char *token, Command *commands[]) {
  int i, numOfCommands = (int) sizeof(commands) / sizeof(commands[0]);

  for (i = 0; i < numOfCommands; i++) {
    if (commands[i]->token == token) {
      return commands[i];
    }
  }

  printf("Undefined command %s; Exiting\n", token);
  return NULL;
}

void destroyCommands (Command *commands[]) {
  int i, numOfCommands = (int) sizeof(commands) / sizeof(commands[0]);

  for (i = 0; i < numOfCommands; i++) {
    free(commands[i]);
  }
}

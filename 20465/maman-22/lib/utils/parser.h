#ifndef parser_h
#define parser_h

typedef enum {
  ReadComp,
  PrintComp,
  AddComp,
  SubComp,
  MultCompReal,
  MultCompImg,
  MultCompComp,
  AbsComp,
  Stop
} CommandToken;

typedef struct {
  char *token;
  void (*function)(void);
  int numOfArgs;
} Command;

Command *commandConstructor (char *token, void (*function)(void), int numOfArgs);
Command *findCommandByToken (char *token, Command *commands[]);
void destroyCommands (Command *commands[]);

#endif /* parser_h */

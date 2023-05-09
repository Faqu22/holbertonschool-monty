#include "monty.h"

int main(int argc, char **argv)
{
    instruction_t function[] = {{"push", _push},
                                {"pall", _pall},
                                {"pint", _pint},
                                {"pop", _pop},
                                {"swap", _swap},
                                {"add", _add},
                                {"nop", _nop},
                                {NULL, NULL}};
    stack_t *list = NULL;
    char *command = NULL;
    char **opcode = NULL;
    int i = 0;
    unsigned int line_number = 1;
    FILE *x;

    if(argc != 2)
    {
        fprintf(stderr, "USAGE: monty file");
        exit(EXIT_FAILURE);
    }
    x = fopen(argv[1], "r");
    if(x == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s", argv[1]);
        exit(EXIT_FAILURE);
    }

    while(1)
    {
        command = get_command();

        opcode = split_command(command, " \n\t");
        free(command);

        for(i = 0; function[i].opcode != NULL; i++)
            if(strcmp(function[i].opcode, opcode[0]) == 0)
                {
                    free_ar(opcode);
                    opcode = NULL;
                    function[i].f(list, line_number);
                }

        line_number++;
        if (opcode != NULL)
            free_ar(opcode);

    }
    fclose(argv[1]);

}
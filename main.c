#include "monty.h"

char **segm = NULL;

int main(int argc, char **argv)
{
    instruction_t function[] = {{"push", _push},
                                {"pall", _pall},
                                {"pint", _pint},
                                {"pop", _pop},
                               /* {"swap", _swap},
                                {"add", _add},
                                {"nop", _nop},*/
                                {NULL, NULL}};
    stack_t *list = NULL;
    char *command = NULL;
    int i = 0;
    unsigned int line_number = 1;
    FILE *file;

    if(argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    file = fopen(argv[1], "r");
    if(file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while(1)
    {
        command = get_command(file);
        if (command == NULL)
        {
            break;
        }

        split_command(command, " \n\t");
        free(command);
        if (segm == NULL)
            continue;

        for(i = 0; function[i].opcode != NULL; i++)
            if(strcmp(function[i].opcode, segm[0]) == 0)
            {
                function[i].f(&list, line_number);
                break;
            }
        if (function[i].opcode == NULL)
            {
                fprintf(stderr, "L%i: unknown instruction %s\n", line_number, segm[0]);
                exit(EXIT_FAILURE);
            }

        line_number++;
        if (segm != NULL)
            free_arr(segm);
    }
    fclose(file);
    free_stack(list);
}
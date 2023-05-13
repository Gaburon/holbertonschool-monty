#include "monty.h"

/**
 * main - Programa principal para el intérprete Monty
 *
 * @argc: Cantidad de argumentos en la línea de comandos
 * @argv: Array de argumentos en la línea de comandos
 *
 * Return: 0 en caso de éxito, 1 en caso de error
 */
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: monty file\n");
        return (EXIT_FAILURE);
    }

    read_file(argv[1]);

    return (EXIT_SUCCESS);
}

/**
 * read_file - Lee un archivo de Monty línea por línea y ejecuta los comandos
 *
 * @filename: Nombre del archivo a leer
 */
void read_file(char *filename)
{
    char buf[BUFFSIZE];
    FILE *fp;
    size_t nread;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while ((nread = fread(buf, 1, sizeof(buf), fp)) > 0)
    {
        char *line_start = buf;
        char *line_end = buf + nread;
        char *line;

        /* Procesar cada línea de texto en el bloque actual */
        while ((line = get_next_line(&line_start, line_end)) != NULL)
        {
            execute_line(line);
        }
    }

    fclose(fp);
}

/**
 * execute_line - Ejecuta un comando de Monty
 *
 * @line: Línea de texto que contiene el comando
 */
void execute_line(char *line)
{
    char *token;
    stack_t *stack = NULL;

    line = strtrim(line);
    token = strtok(line, " \t\n");
    if (token == NULL || strncmp(token, "#", 1) == 0)
    {
        free(line);
        return;
    }
if (strcmp(token, "push") == 0)
    {
        /* Obtener el valor a insertar */
        token = strtok(NULL, " \t\n");
        if (token == NULL || !is_numeric(token))
        {
            fprintf(stderr, "L%u: usage: push integer\n", line_number);
            free(line);
            exit(EXIT_FAILURE);
        }

        /* Insertar el valor en la pila */
        push(&stack, atoi(token));
    }
    else if (strcmp(token, "pall") == 0)
    {
        /* Imprimir la pila */
        pall(stack);
    }
    else if (strcmp(token, "pint") == 0)
    {
        /* Imprimir el valor en la cima de la pila */
        pint(stack);
    }
    else if (strcmp(token, "pop") == 0)
    {
        /* Eliminar el valor en la cima de la pila */
        pop(&stack);
    }
    else if (strcmp(token, "swap") == 0)
    {
        /* Intercambiar los dos valores superiores de la pila */
        swap(&stack);
    }
    else if (strcmp(token, "add") == 0)
    {
        /* Sumar los dos valores superiores de la pila */
        add(&stack);
    }
    else if (strcmp(token, "nop") == 0)
    {
        /* No hacer nada */
    }
    else
    {
        fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
        free(line);
        exit(EXIT_FAILURE);
    }

    free(line);
}

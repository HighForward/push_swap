#include "../includes/push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int str_error(char *str, int code)
{
    printf("%s\n", str);
    return (code);
}

int check_args(char **argv)
{
    int i = 0;
    int y;

    while (argv[i])
    {
        y = 0;
        while (argv[i][y])
        {
            if (!ft_isdigit(argv[i][y]))
                return (0);
            y++;
        }
        i++;
    }
    return (i);
}

void print_stack(s_stack *stack)
{
    int i = 0;

    printf("stack_%c [", stack->name);
    while (i < stack->size)
    {
        char esc = ((int)i == (stack->size - 1)) ? ']' : ',';
        printf("%d%c", stack->stack[i], esc);
        i++;
    }
    if (stack->size == 0)
        printf("]");
    printf("\n");
}

int check_duplicate(int **stack_a, int size, int nb)
{
    int i = 0;

    while (i < size)
    {
        if ((*stack_a)[i] == nb)
            return (0);
        i++;
    }
    return (1);
}

int allocate_stack(int **stack_a, char **argv, int size)
{
    (*stack_a) = malloc(sizeof(int) * size);
    int i = 0;
    int val;
    int final_size = 0;

    while (argv[i])
    {
        val = ft_atoi(argv[i]);
        if (check_duplicate(stack_a, i, val))
        {
            (*stack_a)[final_size] = val;
            final_size++;
        }
        i++;
    }

    if (final_size != size)
    {
        int *stack = malloc(sizeof(int) * final_size);
        i = 0;
        while (i < final_size)
        {
            stack[i] = (*stack_a)[i];
            i++;
        }
        free((*stack_a));
        (*stack_a) = stack;
    }
    return (final_size);
}

int main(int argc, char **argv)
{
    s_stack stack_a;
    s_stack stack_b;
    int size;

    if (argc < 2)
        return (0);

    if ((size = !check_args(argv + 1)))
        return (str_error("Error", 0));

    stack_a.size = allocate_stack(&stack_a.stack, argv + 1, size);
    stack_a.name = 'a';

    stack_b.stack = malloc(sizeof(int) * size);
    stack_b.size = 0;
    stack_b.name = 'b';

    ft_memset(stack_b.stack, 0, size);
    rev_stack(&stack_a);

    print_stack(&stack_a);
    print_stack(&stack_b);

    start_resolve(&stack_a, &stack_b);


    free(stack_a.stack);
    free(stack_b.stack);
    return (0);
}
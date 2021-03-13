#include "../includes/push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int check_args(char **argv, s_flag *flag)
{
    int i = 0;
    int y;
    int less;

    if (!ft_strncmp(argv[i], "-i", 2))
    {
        flag->flag_index++;
        flag->printstack = 1;
        i++;
    }

    while (argv[i])
    {
        y = 0;
        less = 0;
        while (argv[i][y])
        {
            if (argv[i][y] == '-' || argv[i][y] == '+')
                less++;
            else if (!ft_isdigit(argv[i][y]))
                return (0);
            y++;
        }
        if (less > 1)
            return (0);
        i++;
    }
    return (i - flag->flag_index);
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
        if (check_duplicate(stack_a, final_size, val))
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

void init_structs(s_stack *stack_a, s_stack *stack_b, s_flag *flag)
{
    stack_a->stack = NULL;
    stack_a->size = 0;
    stack_a->name = 'a';

    stack_b->stack = NULL;
    stack_b->size = 0;
    stack_b->name = 'b';

    flag->flag_index = 0;
    flag->printstack = 0;
}

int main(int argc, char **argv)
{
    s_stack stack_a;
    s_stack stack_b;
    s_flag flag;
    int size;

    if (argc < 2)
        return (0);

    init_structs(&stack_a, &stack_b, &flag);

    if (!(size = check_args(argv + 1, &flag)))
        return (str_error("Error", 0));

    stack_a.size = allocate_stack(&stack_a.stack, argv + 1 + flag.flag_index, size);
    stack_b.stack = malloc(sizeof(int) * size);
    ft_memset(stack_b.stack, 0, size);
    rev_stack(&stack_a);

//    print_stack_swag_str(&stack_a, &stack_b, &flag,"BEFORE SORTING");

    start_resolve(&stack_a, &stack_b, &flag);

//    print_stack_swag_str(&stack_a, &stack_b, &flag,"AFTER SORTING");

    free(stack_a.stack);
    free(stack_b.stack);
    return (0);
}
#include "../includes/push_swap.h"

int smallest_to_sort(s_stack_cursor *stacks)
{
    int x = find_smallest(stacks->stack_a, 0);
    int i = stacks->stack_a->size;

    int x_tmp = x;

    while (x_tmp != 0)
    {
        if (stacks->stack_a->stack[x_tmp] > stacks->stack_a->stack[x_tmp - 1])
            return (0);
        x_tmp--;
    }

    x_tmp = i - 1;
    while (x_tmp > x + 1)
    {
        if (stacks->stack_a->stack[x_tmp] > stacks->stack_a->stack[x_tmp - 1])
            return (0);
        x_tmp--;
    }
    return (1);
}

void bubble_sort(s_stack_cursor *stacks)
{
    while (smallest_to_sort(stacks) == 0)
    {
        if (stacks->stack_a->stack[stacks->stack_a->size - 1] > stacks->stack_a->stack[stacks->stack_a->size - 2])
            sa(stacks);
        else
            ra(stacks);
    }


    int x = find_smallest(stacks->stack_a, 0);

    if (x >= ((int)(stacks->stack_a->size - 1) / 2))
    {
        while (x < stacks->stack_a->size - 1)
        {
            ra(stacks);
            x++;
        }
    }
    else
    {
        while (x >= 0)
        {
            rra(stacks);
            x--;
        }
    }
}
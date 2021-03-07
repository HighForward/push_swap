#include "../includes/push_swap.h"

int is_sort(s_stack_cursor *stacks)
{
    int i = 0;

    if (stacks->stack_b->size != 0 && stacks->flag->printstack)
        return (str_error("is_sort: FALSE: stack_b is not empty", 0));
    else if (stacks->stack_b->size != 0)
        return (0);

    while (i < stacks->stack_a->size - 1)
    {
        if (stacks->stack_a->stack[i] < stacks->stack_a->stack[i + 1] && stacks->flag->printstack)
            return (str_error("is_sort: FALSE: stack_a is not sorted", 0));
        else if (stacks->stack_a->stack[i] < stacks->stack_a->stack[i + 1])
            return (0);
        i++;
    }

    if (stacks->flag->printstack)
        return (str_error("is_sort: TRUE: stack_a is sorted", 1));
    else
        return (1);
}

int find_smallest(s_stack *stack, int index)
{
    int smallest = stack->stack[0];
    int index_smallest = 0;

    while (index < stack->size)
    {
        if (stack->stack[index] < smallest)
        {
            smallest = stack->stack[index];
            index_smallest = index;
        }
        index++;
    }
    return (index_smallest);
}

int find_biggest(s_stack *stack, int index)
{
    int biggest = stack->stack[0];
    int index_biggest = 0;

    while (index < stack->size)
    {
        if (stack->stack[index] > biggest)
        {
            biggest = stack->stack[index];
            index_biggest = index;
        }
        index++;
    }
    return (index_biggest);
}

int find_smallest_a_and_push_b(struct t_stack_cursor *stacks)
{
    int x;
    x = find_smallest(stacks->stack_a, 0);

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

    if (is_sort(stacks))
        return (1);

    pb(stacks);
    return (0);
}

void selection_sort(struct t_stack_cursor *stacks)
{
    while (!stacks->sorted)
    {
        while (stacks->stack_a->size)
        {
            if (find_smallest_a_and_push_b(stacks))
            {
                stacks->sorted = 1;
                break;
            }
        }
        while (stacks->stack_b->size)
            pa(stacks);
        stacks->sorted = 1;
    }
}
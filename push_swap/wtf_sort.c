#include "../includes/push_swap.h"

void wtf_sort(s_stack_cursor *stacks)
{
    int ok = 0;

    while (stacks->stack_a->size && !is_sort(stacks))
    {
        int tmp = stacks->stack_a->stack[stacks->stack_a->size - 1];
        if (stacks->stack_b->size && stacks->stack_b->stack[stacks->stack_b->size - 1] > tmp)
        {
            ok = 1;
            ra(stacks);
        }
        while (stacks->stack_b->size && stacks->stack_b->stack[stacks->stack_b->size - 1] > tmp)
        {
            pa(stacks);
        }
        if (ok == 1)
        {
            rra(stacks);
            ok = 0;
        }
        pb(stacks);
    }

    while (stacks->stack_b->size)
    {
        pa(stacks);
    }
}

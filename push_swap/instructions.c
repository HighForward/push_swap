#include "../includes/push_swap.h"

s_stack *choose_stack(s_stack_cursor *stacks, char name_use)
{
    if (stacks->stack_a->name == name_use)
        return (stacks->stack_a);
    else
        return (stacks->stack_b);
}

void swap_base(s_stack_cursor *stacks, char name_use)
{
    int size;
    int tmp;

    s_stack *curr_stack = choose_stack(stacks, name_use);

    size = curr_stack->size;
    if (size >= 2)
    {
        tmp = curr_stack->stack[size - 1];
        curr_stack->stack[size - 1] = curr_stack->stack[size - 2];
        curr_stack->stack[size - 2] = tmp;
    }
}

void push_base(s_stack_cursor *stacks, char name_use)
{
    char pop_name = name_use == 'a' ? 'b' : 'a';

    s_stack *push_stack = choose_stack(stacks, name_use);
    s_stack *pop_stack = choose_stack(stacks, pop_name);

    if (pop_stack->size > 0)
    {
        push_stack->stack[push_stack->size] = pop_stack->stack[pop_stack->size -1];
        push_stack->size++;
        pop_stack->size--;
    }
}

void sa(s_stack_cursor *stacks)
{
    swap_base(stacks, 'a');
}

void sb(s_stack_cursor *stacks)
{
    swap_base(stacks, 'b');
}

void ss(s_stack_cursor *stacks)
{
    sa(stacks);
    sb(stacks);
}

void pa(s_stack_cursor *stacks)
{
    push_base(stacks, 'a');
}

void pb(s_stack_cursor *stacks)
{
    push_base(stacks, 'b');
}

void start_resolve(s_stack *stack_a, s_stack *stack_b)
{
    s_stack_cursor stacks;

    stacks.stack_a = stack_a;
    stacks.stack_b = stack_b;

    sa(&stacks);
    sb(&stacks);
    ss(&stacks);

    pb(&stacks);
    pa(&stacks);

    print_stack(stack_a);
    print_stack(stack_b);
}
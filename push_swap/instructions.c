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

void rotate_base(s_stack_cursor *stacks, char name_use)
{
    s_stack *curr_stack = choose_stack(stacks, name_use);
    int top;
    int i = curr_stack->size - 1;

    if (curr_stack->size >= 2)
    {
        top = curr_stack->stack[curr_stack->size - 1];
        while (i > 0)
        {
            curr_stack->stack[i] = curr_stack->stack[i - 1];
            i--;
        }
        curr_stack->stack[0] = top;
    }
}

void reverse_rotate_base(s_stack_cursor *stacks, char name_use)
{
    s_stack *curr_stack = choose_stack(stacks, name_use);
    int top;
    int i = 0;

    if (curr_stack->size >= 2)
    {
        top = curr_stack->stack[i];
        while (i < curr_stack->size)
        {
            curr_stack->stack[i] = curr_stack->stack[i + 1];
            i++;
        }
        curr_stack->stack[curr_stack->size - 1] = top;
    }
}

void sa(s_stack_cursor *stacks)
{
    swap_base(stacks, 'a');
    write(1, "sa\n", 3);
}

void sb(s_stack_cursor *stacks)
{
    swap_base(stacks, 'b');
    write(1, "sb\n", 3);
}

void ss(s_stack_cursor *stacks)
{
    swap_base(stacks, 'a');
    swap_base(stacks, 'b');
    write(1, "ss\n", 3);
}

void pa(s_stack_cursor *stacks)
{
    push_base(stacks, 'a');
    write(1, "pa\n", 3);
}

void pb(s_stack_cursor *stacks)
{
    push_base(stacks, 'b');
    write(1, "pb\n", 3);
}

void ra(s_stack_cursor *stacks)
{
    rotate_base(stacks, 'a');
    write(1, "ra\n", 3);
}

void rb(s_stack_cursor *stacks)
{
    rotate_base(stacks, 'b');
    write(1, "rb\n", 3);
}

void rr(s_stack_cursor *stacks)
{
    rotate_base(stacks, 'a');
    rotate_base(stacks, 'b');
    write(1, "rr\n", 3);
}

void rra(s_stack_cursor *stacks)
{
    reverse_rotate_base(stacks, 'a');
    write(1, "rra\n", 4);
}

void rrb(s_stack_cursor *stacks)
{
    reverse_rotate_base(stacks, 'b');
    write(1, "rrb\n", 4);
}

void rrr(s_stack_cursor *stacks)
{
    reverse_rotate_base(stacks, 'a');
    reverse_rotate_base(stacks, 'b');
    write(1, "rrr\n", 4);
}

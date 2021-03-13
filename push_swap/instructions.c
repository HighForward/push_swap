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
    add_to_moves(stacks, "sa");
    print_stack_refresh(stacks);

}

void sb(s_stack_cursor *stacks)
{
    swap_base(stacks, 'b');
    add_to_moves(stacks, "sb");
    print_stack_refresh(stacks);

}

void ss(s_stack_cursor *stacks)
{
    swap_base(stacks, 'a');
    swap_base(stacks, 'b');
    add_to_moves(stacks, "ss");
    print_stack_refresh(stacks);

}

void pa(s_stack_cursor *stacks)
{
    push_base(stacks, 'a');
    add_to_moves(stacks, "pa");
    print_stack_refresh(stacks);

}

void pb(s_stack_cursor *stacks)
{
    push_base(stacks, 'b');
    add_to_moves(stacks, "pb");
    print_stack_refresh(stacks);

}

void ra(s_stack_cursor *stacks)
{
    rotate_base(stacks, 'a');
    add_to_moves(stacks, "ra");
    print_stack_refresh(stacks);

}

void rb(s_stack_cursor *stacks)
{
    rotate_base(stacks, 'b');
    add_to_moves(stacks, "rb");
    print_stack_refresh(stacks);

}

void rr(s_stack_cursor *stacks)
{
    rotate_base(stacks, 'a');
    rotate_base(stacks, 'b');
    add_to_moves(stacks, "rr");
    print_stack_refresh(stacks);

}

void rra(s_stack_cursor *stacks)
{
    reverse_rotate_base(stacks, 'a');
    add_to_moves(stacks, "rra");
    print_stack_refresh(stacks);

}

void rrb(s_stack_cursor *stacks)
{
    reverse_rotate_base(stacks, 'b');
    add_to_moves(stacks, "rrb");
    print_stack_refresh(stacks);

}

void rrr(s_stack_cursor *stacks)
{
    reverse_rotate_base(stacks, 'a');
    reverse_rotate_base(stacks, 'b');
    add_to_moves(stacks, "rrr");
    print_stack_refresh(stacks);

}

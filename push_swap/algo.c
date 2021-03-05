#include "../includes/push_swap.h"


void start_resolve(s_stack *stack_a, s_stack *stack_b, s_flag *flag)
{
    s_stack_cursor stacks;

    stacks.flag = flag;
    stacks.stack_a = stack_a;
    stacks.stack_b = stack_b;
    stacks.sorted = 0;

    selection_sort(&stacks);
}
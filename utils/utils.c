#include "../includes/libft.h"
#include "../includes/push_swap.h"

void rev_stack(s_stack *stack)
{
    int i = 0;
    int tmp;

    if (stack->size < 2)
        return;

    while (i < stack->size / 2)
    {
        tmp = stack->stack[i];
        stack->stack[i] = stack->stack[stack->size - i - 1];
        stack->stack[stack->size - i - 1] = tmp;
        i++;
    }
}
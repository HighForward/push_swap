#include "../includes/libft.h"
#include "../includes/push_swap.h"

int str_error(char *str, int code)
{
    printf("%s\n", str);
    return (code);
}

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

void print_stack_swag_str(s_stack *stack_a, s_stack *stack_b, s_flag *flag, char *message)
{
    if (flag->printstack)
    {
        printf("-- %s --\n", message);
        print_stack(stack_a);
        print_stack(stack_b);
        printf("--------------------\n");
    }
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
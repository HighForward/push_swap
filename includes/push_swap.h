#ifndef PUSH_SWAP_HPP
#define PUSH_SWAP_HPP

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct t_stack_type
{
    int *stack;
    int size;
    char name;
}   s_stack;

typedef struct t_stack_cursor
{
    s_stack *stack_a;
    s_stack *stack_b;
}   s_stack_cursor;

void start_resolve(s_stack *stack_a, s_stack *stack_b);
void rev_stack(s_stack *stack);
void print_stack(s_stack *stack);
#endif
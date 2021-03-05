#ifndef PUSH_SWAP_HPP
#define PUSH_SWAP_HPP

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct t_flag
{
    int flag_index;
    int printstack;

}   s_flag;


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
    s_flag  *flag;
    int sorted;

}   s_stack_cursor;


void start_resolve(s_stack *stack_a, s_stack *stack_b, s_flag *flag);
void rev_stack(s_stack *stack);
void print_stack(s_stack *stack);
int str_error(char *str, int code);
void print_stack_swag_str(s_stack *stack_a, s_stack *stack_b, s_flag *flag, char *message);


s_stack *choose_stack(s_stack_cursor *stacks, char name_use);
void swap_base(s_stack_cursor *stacks, char name_use);
void push_base(s_stack_cursor *stacks, char name_use);
void rotate_base(s_stack_cursor *stacks, char name_use);
void reverse_rotate_base(s_stack_cursor *stacks, char name_use);
void sa(s_stack_cursor *stacks);
void sb(s_stack_cursor *stacks);
void ss(s_stack_cursor *stacks);
void pa(s_stack_cursor *stacks);
void pb(s_stack_cursor *stacks);
void ra(s_stack_cursor *stacks);
void rb(s_stack_cursor *stacks);
void rr(s_stack_cursor *stacks);
void rra(s_stack_cursor *stacks);
void rrb(s_stack_cursor *stacks);
void rrr(s_stack_cursor *stacks);


#endif
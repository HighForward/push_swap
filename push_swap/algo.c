#include "../includes/push_swap.h"

void hardcoded_three_sort(s_stack_cursor *stacks)
{
    if (stacks->stack_a->size == 3)
    {
        if (((stacks->stack_a->stack[2] > stacks->stack_a->stack[1]) && (stacks->stack_a->stack[1] < stacks->stack_a->stack[0]) && (stacks->stack_a->stack[2] < stacks->stack_a->stack[0])))
        {
            sa(stacks);
        }
        else if (stacks->stack_a->stack[2] > stacks->stack_a->stack[1] && stacks->stack_a->stack[1] > stacks->stack_a->stack[0])
        {

            sa(stacks);
            rra(stacks);
        }
        else if (stacks->stack_a->stack[2] > stacks->stack_a->stack[1] && stacks->stack_a->stack[1] < stacks->stack_a->stack[0])
        {
            ra(stacks);
        }
        else if (stacks->stack_a->stack[2] < stacks->stack_a->stack[1] && stacks->stack_a->stack[1] > stacks->stack_a->stack[0] && stacks->stack_a->stack[2] < stacks->stack_a->stack[0])
        {
            sa(stacks);
            ra(stacks);
        }
        else if (stacks->stack_a->stack[2] < stacks->stack_a->stack[1] && stacks->stack_a->stack[1] > stacks->stack_a->stack[0])
        {
            rra(stacks);
        }
    }
}

void add_to_moves(struct t_stack_cursor *stacks, char *str)
{
    if (stacks->moves->size >= stacks->moves->capacity)
    {
        char **tmp = malloc(sizeof(char *) * (stacks->moves->capacity + 100 + 1));
        int i = 0;

        stacks->moves->capacity += stacks->moves->capacity + 100;

        while (i < stacks->moves->size)
        {
            tmp[i] = stacks->moves->moves[i];
            i++;
        }

        free(stacks->moves->moves);
        stacks->moves->moves = tmp;
    }

    stacks->moves->moves[stacks->moves->size] = ft_strdup(str);
    stacks->moves->size++;
}

void start_resolve(s_stack *stack_a, s_stack *stack_b, s_flag *flag)
{
    s_stack_cursor stacks;
    s_moves moves;

    moves.size = 0;
    moves.capacity = 0;
    moves.moves = NULL;

    stacks.flag = flag;
    stacks.moves = &moves;
    stacks.stack_a = stack_a;
    stacks.stack_b = stack_b;
    stacks.sorted = 0;



//    selection_sort(&stacks);
//    wtf_sort(&stacks);
//    print_stack_refresh(&stacks);
    bubble_sort(&stacks);
//    hardcoded_three_sort(&stacks);
//    print_stack_refresh(&stacks);
//    algo qui split la stack sur a et b, algo qui trie les deux stack genre bubble sort, ss rr rrr

    /* loop sur stack_a, pb les premiers < 50%
     * sinon sa, ss si le prochain element a etre pb peut être mieux trié */

    int i = 0;
    while (i < stacks.moves->size)
    {
        free(stacks.moves->moves[i]);
        i++;
    }
    free(stacks.moves->moves);
}
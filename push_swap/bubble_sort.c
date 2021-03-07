#include "../includes/push_swap.h"

int find_fastest_to_rotate(s_stack* stack, int highest, int smallest)
{
    if (stack->size < 2)
        return (str_error("stack size < 2", 0));

    int i = 0;

    int index_from_bottom;
    int index_from_top;

    while (i < stack->size)
    {
        if (stack->stack[i] > stack->stack[(i == 0 ? stack->size -1 : i - 1)] && stack->stack[(i == 0 ? stack->size -1 : i - 1)] != stack->stack[smallest])
        {
            index_from_bottom = i;
            break;
        }
        i++;
    }

    i = stack->size - 1;
    while (i >= 0)
    {
        if (stack->stack[i] > stack->stack[(i == 0 ? stack->size -1 : i - 1)] && stack->stack[(i == 0 ? stack->size -1 : i - 1)] != stack->stack[smallest])
        {
            index_from_top = i;
            break;
        }
        i--;
    }

    if (index_from_bottom < (stack->size - 1 - index_from_bottom))
        return (index_from_bottom);
    else
        return (index_from_top);
}

int smallest_to_sort(s_stack_cursor *stacks)
{
    int x = find_smallest(stacks->stack_a, 0);
    int i = stacks->stack_a->size;

    int x_tmp = x;

    while (x_tmp != 0)
    {
        if (stacks->stack_a->stack[x_tmp] > stacks->stack_a->stack[x_tmp - 1])
            return (0);
        x_tmp--;
    }

    if (stacks->stack_a->stack[0] > stacks->stack_a->stack[stacks->stack_a->size - 1] )
        return (0);

    x_tmp = i - 1;
    while (x_tmp > x + 1)
    {
        if (stacks->stack_a->stack[x_tmp] > stacks->stack_a->stack[x_tmp - 1])
            return (0);
        x_tmp--;
    }
    return (1);
}

void bubble_sort(s_stack_cursor *stacks)
{
    //TODO function qui cherche un element mal placé, et check cb d'instruction pour le placer
    //TODO IDEE : cherche le grand / petit proche, le plus rapide a trié

    while (smallest_to_sort(stacks) == 0)
    {
        //can optimize this to loop only when it need to search those
        int smallest = find_smallest(stacks->stack_a, 0);
        int biggest = find_biggest(stacks->stack_a, 0);

        if (stacks->stack_a->stack[stacks->stack_a->size - 1] > stacks->stack_a->stack[stacks->stack_a->size - 2] && !(stacks->stack_a->size - 1 == biggest && stacks->stack_a->size - 2 == smallest))
        {
                sa(stacks);
        }
        else
        {
//            printf("fastest to rotate: %d\n", find_fastest_to_rotate(stacks->stack_a, biggest, smallest));
            int fastest = find_fastest_to_rotate(stacks->stack_a, biggest, smallest);
            int fastest_tmp = fastest;

            while (fastest != stacks->stack_a->size - 1)
            {
                //chercher un element mal trié, le plus proche pour SA, et faire RA ou RRA en fonction

                if (fastest >= ((int) (stacks->stack_a->size - 1) / 2))
                {
                    ra(stacks);
                    fastest_tmp ++;
                    if (fastest_tmp == stacks->stack_a->size - 1)
                        break;
                }
                else
                {
                    rra(stacks);
                    fastest_tmp--;
                    if (fastest_tmp == -1)
                        break;
                }
            }
        }
//        usleep(100000);
//        print_stack(stacks->stack_a);
    }



    //its sorted, lets put smallest at top
    int x = find_smallest(stacks->stack_a, 0);

    if (x >= ((int)(stacks->stack_a->size - 1) / 2))
    {
        while (x < stacks->stack_a->size - 1)
        {
            ra(stacks);
            x++;
        }
    }
    else
    {
        while (x >= 0)
        {
            rra(stacks);
            x--;
        }
    }
}
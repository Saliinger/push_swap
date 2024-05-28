#include "../../includes/push_swap.h"

void target_b_init(t_stack **a, t_stack **b)
{
    t_stack *temp_a;
    t_stack *temp_b;
    t_stack *max_a;
    t_stack *min_a;
    long match_diff;
    long diff;

    max_a = is_max(a);
    min_a = is_min(a);
    temp_b = *b;
    while (temp_b)
    {
        temp_a = *a;
        match_diff = LONG_MAX;
        temp_b->target = max_a;
        if (temp_b->number > max_a->number || temp_b->number < min_a->number)
            temp_b->target = min_a;
        else
        {
            while (temp_a)
            {
                if (temp_a->number > temp_b->number)
                {
                    diff = temp_a->number - temp_b->number;
                    if (diff < match_diff)
                    {
                        match_diff = diff;
                        temp_b->target = temp_a;
                    }
                }
                temp_a = temp_a->next;
            }
        }
        temp_b = temp_b->next;
    }
}

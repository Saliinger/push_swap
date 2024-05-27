#include "../../includes/push_swap.h"

void target_b_init(t_stack **a, t_stack **b) {
    t_stack *temp_a = *a;
    t_stack *temp_b;
    t_stack *max_b;
    long match;

    max_b = is_max(b);

    while (temp_a) {
        temp_b = *b;
        match = LONG_MIN;
        temp_a->target = max_b; // Default to the max in B if no smaller number is found

        while (temp_b) {
            if (temp_a->number > temp_b->number && temp_b->number > match) {
                match = temp_b->number;
                temp_a->target = temp_b;
            }
            temp_b = temp_b->next; // Move to the next node in stack B
        }

        temp_a = temp_a->next; // Move to the next node in stack A
    }
}

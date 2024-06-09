///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   a_b.c                                              :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2024/04/24 22:24:07 by anoukan           #+#    #+#             */
///*   Updated: 2024/06/09 14:42:22 by anoukan          ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */
//
//#include "../../includes/push_swap.h"
//
//static long average_node(t_stack **s)
//{
//    long average;
//    long effective;
//    long res;
//    t_stack *node;
//
//    average = 0;
//    effective = 0;
//    node = *s;
//    while (node)
//    {
//        average += node->number;
//        effective++;
//        node = node->next;
//    }
//    res = average / effective;
//    return (res);
//}
//
//void	a_b(t_stack **a, t_stack **b)
//{
//    long average;
//    t_stack *node;
//
//    average = average_node(a);
//    node = *a;
//	if (node->number < average)
//		pb(b, a);
//	else
//    {
//        pb(b, a);
//        if(ft_lstsize2(*b) > 2)
//            rb(b);
//    }
//}

#include "../../includes/push_swap.h"

// Function to calculate the size of the stack
int stack_size(t_stack *stack) {
    int size = 0;
    while (stack) {
        size++;
        stack = stack->next;
    }
    return size;
}

// Function to push elements from source stack to destination stack
void push_all(t_stack **dest, t_stack **src) {
    while (*src) {
        pb(dest, src);
    }
}

// Quicksort partition function
void partition(t_stack **a, t_stack **less, t_stack **greater, int pivot) {
    while (*a) {
        if ((*a)->number < pivot)
            pb(less, a);
        else
            pb(greater, a);
    }
}

// Quicksort function for stacks
static void quick_sort(t_stack **a) {
    if (stack_size(*a) <= 1)
        return;

    t_stack *less = NULL;
    t_stack *greater = NULL;
    int pivot = (*a)->number;  // Use the first element as pivot

    // Partition the stack
    partition(a, &less, &greater, pivot);

    // Recursively sort the sub-stacks
    quick_sort(&less);
    quick_sort(&greater);

    // Merge the sorted stacks back into the original stack
    push_all(a, &greater);
    pb(a, &less); // Push pivot back to stack a
    push_all(a, &less);
}

// Main function to sort stacks a and b
void a_b(t_stack **a, t_stack **b) {
    quick_sort(a);
    push_all(b, a); // Move all elements from a to b to complete the sort
}


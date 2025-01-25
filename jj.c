void sort_complicated(t_stack *stacka, t_stack *stackb)
{
    if (stacka->size <= 3) {
        sort_three(stacka);
        return;
    }

    pb(stacka, stackb);
    pb(stacka, stackb);
    
    while (stacka->size > 3)
    {
        int cheapest_number, min_cost;
        calculate_cost(stacka, stackb, &cheapest_number, &min_cost);
        
        if (cheapest_number == -1) break;
        
        int target = find_target_position(stackb, cheapest_number);
        rotate_and_push(stacka, stackb, cheapest_number, target);
    }

    sort_three(stacka);
    
    while (stackb->size > 0)
        pa(stacka, stackb);
    
    final_rotation(stacka);
}

int find_max_index(t_stack *stack)
{
    if (!stack || !stack->top) return -1;
    
    int max_value = stack->top->value;
    int max_index = 0;
    int current_index = 0;
    t_node *current = stack->top;
    
    while (current) {
        if (current->value > max_value) {
            max_value = current->value;
            max_index = current_index;
        }
        current = current->next;
        current_index++;
    }
    
    return max_index;
}

int find_target_position(t_stack *stack, int number)
{
    if (!stack || !stack->top) return 0;
    
    int max_index = find_max_index(stack);
    int stack_size = stack->size;
    
    // If number is larger than max, place it after max
    if (number > get_node_at_index(stack, max_index)->value)
        return (max_index + 1) % stack_size;
    
    // Find insertion point between existing elements
    int target_index = 0;
    t_node *current = stack->top;
    int prev_value = get_node_at_index(stack, stack_size - 1)->value;
    
    for (int i = 0; i < stack_size; i++) {
        if (number < current->value && number > prev_value)
            return i;
        
        prev_value = current->value;
        current = current->next;
        target_index++;
    }
    
    // Default to first position if no suitable spot found
    return 0;
}

void calculate_cost(t_stack *stacka, t_stack *stackb, int *cheapest_number, int *min_cost)
{
    *cheapest_number = -1;
    *min_cost = INT_MAX;
    
    t_node *current = stacka->top;
    int current_index = 0;
    
    while (current) {
        int target_pos = find_target_position(stackb, current->value);
        
        int ra_cost = current_index;
        int rb_cost = target_pos;
        int combined_rotations = (ra_cost > rb_cost) ? ra_cost : rb_cost;
        
        int total_cost = ra_cost + rb_cost + 1;
        
        if (total_cost < *min_cost) {
            *min_cost = total_cost;
            *cheapest_number = current->value;
        }
        
        current = current->next;
        current_index++;
    }
}

void rotate_and_push(t_stack *stacka, t_stack *stackb, int number, int target_pos)
{
    // Rotate stack A to bring number to top
    while (stacka->top->value != number) 
        ra(stacka);
    
    // Rotate stack B to bring target position to top
    while (find_target_position(stackb, number) != target_pos)
        rb(stackb);
    
    // Push to B
    pb(stacka, stackb);
}

void final_rotation(t_stack *stack)
{
    int min_index = find_min_index(stack);
    int stack_size = stack->size;
    
    // Rotate to bring minimum to top
    while (min_index != 0) {
        ra(stack);
        min_index = (min_index - 1 + stack_size) % stack_size;
    }
}
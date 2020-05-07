#ifndef __UTILS_H
#define __UTILS_H

//------------------------------------------------------------------- CONSTANTS
const int size_off = 62;
const int WALK = 4;
// horizontal and vertical first after diagonal - permutation 6 first
const int offset_x[WALK][size_off] = {
    {0, 0, 1, 0,-1,-1, 1,  1, -1, 0, 2, 0,-2,-1, 1, 1,-1,-2, 2, 2, -2, 0, 3, 0, 0,-3, 2, 2,-2,-2, 1, 3, 3, 1, -1, -3,-3,-1, 0, 4, 0,-4, 2, 3, 3, 2,-2,-3,-3,-2, 1, 4, 4, 1,-1,-4,-4,-1, 0, 5, 0,-5},
    {0,-1, 0, 1, 0,-1, 1,  1, -1, 0, 2, 0,-2,-1, 1, 1,-1,-2, 2, 2, -2, 0, 3, 0, 0,-3, 2, 2,-2,-2, 1, 3, 3, 1, -1, -3,-3,-1, 0, 4, 0,-4, 2, 3, 3, 2,-2,-3,-3,-2, 1, 4, 4, 1,-1,-4,-4,-1, 0, 5, 0,-5},
    {0, 0, 1, 0,-1,-1, 1,  1, -1, 0, 2, 0,-2,-1, 1, 1,-1,-2, 2, 2, -2, 0, 3, 0, 0,-3, 2, 2,-2,-2, 1, 3, 3, 1, -1, -3,-3,-1, 0, 4, 0,-4, 2, 3, 3, 2,-2,-3,-3,-2, 1, 4, 4, 1,-1,-4,-4,-1, 0, 5, 0,-5}, 
    {0,-1, 1, 0,-1,-1, 1,  1, -1, 0, 2, 0,-2,-1, 1, 1,-1,-2, 2, 2, -2, 0, 3, 0, 0,-3, 2, 2,-2,-2, 1, 3, 3, 1, -1, -3,-3,-1, 0, 4, 0,-4, 2, 3, 3, 2,-2,-3,-3,-2, 1, 4, 4, 1,-1,-4,-4,-1, 0, 5, 0,-5}
};
const int offset_y[WALK][size_off] = {
    {0, 1, 0,-1, 0, 1, 1, -1, -1, 2, 0,-2, 0, 2, 2,-2,-2, 1, 1,-1, -1, 3, 0, 3,-3, 0, 2,-2,-2, 2, 3, 1,-1,-3, -3, -1, 1, 3, 4, 0,-4, 0, 3, 2,-2,-3,-3,-2, 2, 3, 4, 1,-1,-4,-4,-1, 1, 4, 5, 0,-5, 0},
    {0, 0, 1, 0,-1, 1, 1, -1, -1, 2, 0,-2, 0, 2, 2,-2,-2, 1, 1,-1, -1, 3, 0, 3,-3, 0, 2,-2,-2, 2, 3, 1,-1,-3, -3, -1, 1, 3, 4, 0,-4, 0, 3, 2,-2,-3,-3,-2, 2, 3, 4, 1,-1,-4,-4,-1, 1, 4, 5, 0,-5, 0},
    {0,-1, 0, 1, 0, 1, 1, -1, -1, 2, 0,-2, 0, 2, 2,-2,-2, 1, 1,-1, -1, 3, 0, 3,-3, 0, 2,-2,-2, 2, 3, 1,-1,-3, -3, -1, 1, 3, 4, 0,-4, 0, 3, 2,-2,-3,-3,-2, 2, 3, 4, 1,-1,-4,-4,-1, 1, 4, 5, 0,-5, 0},
    {0, 0, 0,-1, 1, 1, 1, -1, -1, 2, 0,-2, 0, 2, 2,-2,-2, 1, 1,-1, -1, 3, 0, 3,-3, 0, 2,-2,-2, 2, 3, 1,-1,-3, -3, -1, 1, 3, 4, 0,-4, 0, 3, 2,-2,-3,-3,-2, 2, 3, 4, 1,-1,-4,-4,-1, 1, 4, 5, 0,-5, 0}
};

///------------------------------------------------------------------ EVALUATE NO 1-hop
int evaluate(int *e_a, int *e_b, int *pos_x, int *pos_y, int *pos_ii,
            const int n_edge) {
    int sum = 0, a, b, diff_pos_x, diff_pos_y, cost;

    for (int i = 0; i < n_edge; i++) {
        a = e_a[i];
        b = e_b[i];
        if (a == b){ 
#ifdef PRINT
            printf("%2d -> %2d Mesh: 0, 1-hop: 0\n", a, b);
#endif
            continue; // a -> a (ciclo 1 step)
        }
        diff_pos_x = abs(pos_x[a]-pos_x[b]);
        diff_pos_y = abs(pos_y[a]-pos_y[b]);
        
        if (diff_pos_x + diff_pos_y == 0)
            cost = 0;
        else
            cost = diff_pos_x + diff_pos_y - 1;
        
        sum += cost;
#ifdef DEBUG
    if (pos_ii[a] == pos_ii[b])
        printf("Would be balanced or error on the code, Which one?");
    printf("%2d (%d, %d)[%d] -> %2d (%d, %d)[%d] Cost: %d\n", a, pos_x[a], 
                pos_y[a], pos_ii[a], b, pos_x[b], pos_y[b], pos_ii[b], cost);
#endif 
    }

    return sum;
}

int evaluate_1hop(int *e_a, int *e_b, int *pos_x, int *pos_y, int *pos_ii,
            const int n_edge) {
    int sum = 0, a, b, diff_pos_x, diff_pos_y, cost;
    bool one_hop;

    for (int i = 0; i < n_edge; i++) {
        a = e_a[i];
        b = e_b[i];
        if (a == b) continue; // a -> a (ciclo 1 step)
  
        diff_pos_x = abs(pos_x[a]-pos_x[b]);
        diff_pos_y = abs(pos_y[a]-pos_y[b]);

        // one hop
        if (diff_pos_x != 1) diff_pos_x /= 2;
        if (diff_pos_y != 1) diff_pos_y /= 2;

        if (diff_pos_x + diff_pos_y == 0)
            cost = 0;
        else
            cost = diff_pos_x + diff_pos_y - 1;
        sum += cost;
#ifdef DEBUG
    if (pos_ii[a] == pos_ii[b])
        printf("Would be balanced or error on the code, Which one?");
    
    printf("%2d (%d, %d)[%d] -> %2d (%d, %d)[%d] Cost: %d\n", a, pos_x[a],
            pos_y[a], pos_ii[a], b, pos_x[b], pos_y[b], pos_ii[b], cost);
#endif
    }

    return sum;
}

int evaluate_cgrame(int *e_a, int *e_b, int *pos_x, int *pos_y, int *pos_ii,
            int *constraints, const int n_edge) {
    int sum = 0, sum_1hop = 0;
    int a, b, diff_pos_x, diff_pos_y, cost, cost_1hop, c_a, c_b;
    int temp;

    for (int i = 0; i < n_edge; i++) {
        a = e_a[i];
        b = e_b[i];
        c_a = constraints[a];
        c_b = constraints[b];

        if (a == b) continue; // a -> a (ciclo 1 step)

        diff_pos_x = abs(pos_x[a]-pos_x[b]);
        diff_pos_y = abs(pos_y[a]-pos_y[b]);
        if (c_a == 0 || c_b == 0) {
            diff_pos_y = 0;
            if (diff_pos_x != 0)
                diff_pos_y = abs(pos_y[a]-pos_y[b]);
        }
        
        cost_1hop = 0;
        temp = (diff_pos_x/2 + diff_pos_x%2) + (diff_pos_y/2 + diff_pos_y%2);
        if ( temp > 0)
            cost_1hop = temp - 1;

        cost = 0;
        temp = diff_pos_x + diff_pos_y; 
        if (temp > 0)
            cost = temp - 1;

        sum += cost;
        sum_1hop += cost_1hop;
    }
    return sum;
}

int evaluate_cgrame_final(int *e_a, int *e_b, int *pos_x, int *pos_y, int *pos_ii,
            int *constraints, const int n_edge) {
    int sum = 0, sum_1hop = 0;
    int a, b, diff_pos_x, diff_pos_y, cost, cost_1hop, c_a, c_b;

    for (int i = 0; i < n_edge; i++) {
        a = e_a[i];
        b = e_b[i];
        c_a = constraints[a];
        c_b = constraints[b];

        if (a == b) continue; // a -> a (ciclo 1 step)

        diff_pos_x = abs(pos_x[a]-pos_x[b]);
        diff_pos_y = abs(pos_y[a]-pos_y[b]);
        if (c_a == 0 || c_b == 0) {
            diff_pos_y = 0;
            if (diff_pos_x != 0)
                diff_pos_y = abs(pos_y[a]-pos_y[b]);
        }
        
        cost_1hop = 0;
        int temp = (diff_pos_x/2 + diff_pos_x%2) + (diff_pos_y/2 + diff_pos_y%2);
        if ( temp > 0)
            cost_1hop = temp - 1;

        cost = 0;
        temp = diff_pos_x + diff_pos_y; 
        if (temp > 0)
            cost = temp - 1;

        sum += cost;
        sum_1hop += cost_1hop;
#ifdef PRINT
        printf("%2d -> %2d [%2d,%2d] Cost_Mesh: %d Cost_1-hop: %d ", a, b, pos_x[a], pos_x[b], cost, cost_1hop);
        if (pos_ii[a] == pos_ii[b]) printf("same context");
        printf("\n");
#endif
    }
    return sum;
}

int evaluate_1hop_cgrame(int *e_a, int *e_b, int *pos_x, int *pos_y, int *pos_ii,
            int *constraints, const int n_edge) {
    int sum = 0, sum_1hop = 0;
    int a, b, diff_pos_x, diff_pos_y, cost, cost_1hop, c_a, c_b;
    int temp;

    for (int i = 0; i < n_edge; i++) {
        a = e_a[i];
        b = e_b[i];
        c_a = constraints[a];
        c_b = constraints[b];

        if (a == b) continue; // a -> a (ciclo 1 step)

        diff_pos_x = abs(pos_x[a]-pos_x[b]);
        diff_pos_y = abs(pos_y[a]-pos_y[b]);
        if (c_a == 0 || c_b == 0) {
            diff_pos_y = 0;
            if (diff_pos_x != 0)
                diff_pos_y = abs(pos_y[a]-pos_y[b]);
        }
        
        cost_1hop = 0;
        temp = (diff_pos_x/2 + diff_pos_x%2) + (diff_pos_y/2 + diff_pos_y%2);
        if ( temp > 0)
            cost_1hop = temp - 1;

        cost = 0;
        temp = diff_pos_x + diff_pos_y; 
        if (temp > 0)
            cost = temp - 1;

        sum += cost;
        sum_1hop += cost_1hop;
    }
    return sum_1hop;
}

#endif
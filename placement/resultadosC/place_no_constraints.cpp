#include <iostream>
#include <chrono>
#include <math.h>
#include <string>

#include <fstream>

using namespace std;

#ifdef MEASURE_TIME
    using Milliseconds = chrono::duration<double, ratio<1,1000>>;
#endif

int evaluate(const int *e_a, const int *e_b, const int *pos_x,
    const int *pos_y, const int n_edge) {
    int sum = 0, a, b, diff_pos_x, diff_pos_y;

    for (int i = 0; i < n_edge; i++) {
        a = e_a[i];
        b = e_b[i];
        if (a == b) continue; // a -> a (ciclo 1 step)

        diff_pos_x = abs(pos_x[a]-pos_x[b]);
        diff_pos_y = abs(pos_y[a]-pos_y[b]);

        if (diff_pos_x + diff_pos_y > 0)
            sum += diff_pos_x + diff_pos_y - 1;
    }
    return sum;
}

int evaluate_1hop(const int *e_a, const int *e_b, const int *pos_x,
    const int *pos_y, const int n_edge) {
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
    printf("%2d (%d, %d)[%d] -> %2d (%d, %d)[%d] Cost: %d\n", a, pos_x[a],
            pos_y[a], pos_ii[a], b, pos_x[b], pos_y[b], pos_ii[b], cost);
#endif
    }
    return sum;
}

int* leArq(string nome, int *v){
    int data;
    int i=0;
    ifstream infile;
    infile.open(nome);
   
    if (infile.is_open() && infile.good()){
        while(infile >> data){
		//infile >> data;
		//cout << data << endl; 	
                v[i] = data;
                i++;
        }
    }
    infile.close();
}

int main() {
    int n_node, n_edge;
    const int size_off = 64;

    int offset_x[size_off]; 
    leArq("offsetXData.txt", offset_x);
//    cout << offset_x[0] << endl;

    int offset_y[size_off];
    leArq("offsetYData.txt", offset_y);
 //   cout << offset_y[0] << endl;

    double time = 0;
#ifdef MEASURE_TIME
    chrono::time_point<chrono::high_resolution_clock>
		start_clock, end_clock;
#endif

    cin >> n_node >> n_edge;          // size node and edge

    int e_a[n_edge], e_b[n_edge];     // vector edge a -> b
    int pos_x[n_node], pos_y[n_node]; // position each node

    const int n = static_cast<int>(ceil(sqrt(n_node)));
    int grid[n][n];         // grid n x n
    //int constraints[n_node];

    // read information edges
    for (int i = 0; i < n_edge; ++i) {
        cin >> e_a[i] >> e_b[i];
    }

    // configure initial grid
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            grid[i][j] = -1;

    // horizontal and vertical first after diagonal
   /* const int offset_x[size_off] = { 0, 1, 0,-1,-1, 1,  1, -1, 0, 2,  0, -2,
                                    -1, 1, 1,-1,-2, 2,  2, -2, 0, 4,  0, -4,
                                     1, 1,-1,-1};
    const int offset_y[size_off] = { 1, 0,-1, 0, 1, 1, -1, -1, 2, 0, -2,  0,
                                     2, 2,-2,-2, 1, 1, -1, -1, 4, 0, -4,  0,
                                     3,-3,-3, 3};*/

    // configure initial position
    for (int i = 0; i < n_node; i++) {
        pos_x[i] = -1;
        pos_y[i] = -1;
    }

    int a, b, j;
    int pos_a_x, pos_a_y, pos_b_x, pos_b_y, xi, xj;

    a = e_a[0];

    pos_x[a] = 0;
    pos_y[a] = 0;

    grid[pos_x[0]][pos_y[0]] = a;

#ifdef DEBUG
    for (int i = 0; i < n_edge; ++i) {
        printf("%d %d\n", e_a[i], e_b[i]);
    }
#endif


#ifdef MEASURE_TIME
    start_clock = chrono::high_resolution_clock::now();
#endif
    //------------------------------------------------- algorithm placement
    for (int i = 0; i < n_edge; ++i) {
        a = e_a[i];
        b = e_b[i];
        pos_a_x = pos_x[a];
        pos_a_y = pos_y[a];
        pos_b_x = pos_x[b];
        pos_b_y = pos_y[b];

#ifdef DEBUG
        printf("%d -> %d\n", a, b);
#endif
        j = 0;
        // if position not set
        while (pos_a_x == -1) {
#ifdef DEBUG
            if (j == 0) printf("pos to %d\n", a);
#endif
            xi = pos_x[a] = pos_x[i-1] + offset_x[j];
            xj = pos_y[a] = pos_y[i-1] + offset_y[j];
            ++j;
#ifdef DEBUG
            printf("try pos (%d, %d)\n", xi, xj);
#endif
            if (grid[xi][xj] == -1 && xi < n && xi >= 0 && xj < n && xj >= 0) {
                grid[xi][xj] = a;
                pos_a_x = xi;
                pos_a_y = xj;
            } else if (j > size_off) {
                printf("No solution\n");
                return 0;
            }
        }

        j = 0;
        while (pos_b_x == -1) {
#ifdef DEBUG
            if (j == 0) printf("pos_b\n");
#endif
            // strategy local
            xi = pos_a_x + offset_x[j];
            xj = pos_a_y + offset_y[j];
            ++j;
#ifdef DEBUG
            printf("try pos (%d, %d)\n", xi, xj);
#endif
            if (grid[xi][xj] == -1 && xi < n && xi >= 0 && xj < n && xj >= 0) {
                grid[xi][xj] = b;
                pos_b_x = pos_x[b] = xi;
                pos_b_y = pos_y[b] = xj;
                break; // ok!
            } else if (j > size_off) {
                printf("No solution\n");
                return 0;
            }
        }
#ifdef DEBUG
        printf("%d (%d,%d) -> %d (%d,%d)\n", a, pos_a_x, pos_a_y, b, pos_b_x, pos_b_x);
#endif
    }
#ifdef MEASURE_TIME
    end_clock = chrono::high_resolution_clock::now();
    time = chrono::duration_cast<Milliseconds>(end_clock - start_clock).count();
#endif
#ifdef PRINT
    // Print Results
    printf("\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%3d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\nEvaluation = %d", evaluate(e_a, e_b, pos_x, pos_y, n_edge));
    printf("\nEvaluation 1-hop = %d\n", evaluate_1hop(e_a, e_b, pos_x, pos_y, n_edge));
    cout << "Time placement: " << time << " ms\n\n";
#endif
}

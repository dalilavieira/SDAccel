#include <iostream>
#include <chrono>
#include <math.h>
#include <vector>
#include <algorithm>
#include <time.h>
#include "utils.h"

using namespace std;

#ifdef MEASURE_TIME
    using Seconds = chrono::duration<double, ratio<1>>;
#endif

int evaluate(int *e_a, int *e_b, int *pos_x, int *pos_y, const int n_edge) {
    int sum = 0, sum_1hop = 0;
    int a, b, diff_pos_x, diff_pos_y, cost, cost_1hop;

    for (int i = 0; i < n_edge; i++) {
        a = e_a[i];
        b = e_b[i];

        if (a == b) continue; // a -> a (ciclo 1 step)

        diff_pos_x = abs(pos_x[a]-pos_x[b]);
        diff_pos_y = abs(pos_y[a]-pos_y[b]);
        
        cost_1hop = (diff_pos_x/2 + diff_pos_x%2) + (diff_pos_y/2 + diff_pos_y%2) - 1;

        cost = diff_pos_x + diff_pos_y - 1;

        sum += cost;
        sum_1hop += cost_1hop;
    }
    return sum;
}

int evaluate_final(int *e_a, int *e_b, int *pos_x, int *pos_y, const int n_edge) {
    int sum = 0, sum_1hop = 0;
    int a, b, diff_pos_x, diff_pos_y, cost, cost_1hop;

    for (int i = 0; i < n_edge; i++) {
        a = e_a[i];
        b = e_b[i];

        if (a == b) continue; // a -> a (ciclo 1 step)

        diff_pos_x = abs(pos_x[a]-pos_x[b]);
        diff_pos_y = abs(pos_y[a]-pos_y[b]);
        
        cost_1hop = (diff_pos_x/2 + diff_pos_x%2) + (diff_pos_y/2 + diff_pos_y%2) - 1;

        cost = diff_pos_x + diff_pos_y - 1;

        sum += cost;
        sum_1hop += cost_1hop;
#ifdef PRINT
        printf("%3d -> %3d Cost_Mesh: %d Cost_1-hop: %d\n", a, b, cost, cost_1hop);
#endif
    }
    return sum;
}

int evaluate_1hop(int *e_a, int *e_b, int *pos_x, int *pos_y, const int n_edge) {
    int sum = 0, sum_1hop = 0;
    int a, b, diff_pos_x, diff_pos_y, cost, cost_1hop;

    for (int i = 0; i < n_edge; i++) {
        a = e_a[i];
        b = e_b[i];

        if (a == b) continue; // a -> a (ciclo 1 step)

        diff_pos_x = abs(pos_x[a]-pos_x[b]);
        diff_pos_y = abs(pos_y[a]-pos_y[b]);
        
        cost_1hop = (diff_pos_x/2 + diff_pos_x%2) + (diff_pos_y/2 + diff_pos_y%2) - 1;

        cost = diff_pos_x + diff_pos_y - 1;

        sum += cost;
        sum_1hop += cost_1hop;
    }
    return sum_1hop;
}

int main(int argc, char** argv) {
    int n_node, n_edge;

    srand(time(NULL)+rand());

    string name;
    double time_ms = 0;
    const int size_edge = 2;
    int qtd;

    if (argc > 1) {
        name = argv[1];
        qtd = atoi(argv[2]);
    } else {
        printf("ERROR:\n\tCOMMAND: ./a.out <name> <qtd> < list/<name>.in\n");
        return 1;
    }

#ifdef MEASURE_TIME
    chrono::time_point<chrono::high_resolution_clock>
		start_clock, end_clock;
#endif

    cin >> n_node >> n_edge;          // size node and edge

    int e_a[size_edge][n_edge], e_b[size_edge][n_edge]; // vector edge a -> b
    int pos_x[n_node], pos_y[n_node]; // position each node

    const int n = static_cast<int>(ceil(sqrt(n_node)));
    int grid[n][n];         // grid n x n
    int best_grid[n][n];

    // read information edges
    for (int i = 0; i < n_edge; ++i) {
        cin >> e_a[0][i] >> e_b[0][i];
    }

    int best_evaluate = 9999, eval;
    int best_evaluate_1hop = 9999, eval_1hop;
    int best_pos_x[n_node];
    int best_pos_y[n_node];
    int a, b, j, k, aux, best_w;
    int pos_a_x, pos_a_y, pos_b_x, pos_b_y, xi, xj;
    std::vector<int> shuffle;         // Vector shuffle
    bool any_sol, solution;

    // create order inverse
    if (size_edge > 0) {
        for (int j = 0; j < n_edge; ++j) {
            e_a[1][j] = e_a[0][n_edge-j-1];
            e_b[1][j] = e_b[0][n_edge-j-1];
        }
    }

    for (int i = 0; i < n_node; ++i) {
        best_pos_x[i] = -1;
        best_pos_y[i] = -1;
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            best_grid[i][j] = -1;

    // create other order to edge
    for (int i=2; i < n_edge; ++i) 
        shuffle.push_back(i);

    for (int i = 2; i < size_edge; ++i) {
        random_shuffle (shuffle.begin(), shuffle.end());

        // creating others order
        for (int j = 0; j < n_edge; ++j) {
            aux = shuffle[j];
            e_a[i][j] = e_a[0][aux];
            e_b[i][j] = e_b[0][aux];
        }
#ifdef DEBUG
        // print out content:
        printf("shuffle contains: ");
        for (std::vector<int>::iterator it=shuffle.begin(); it != shuffle.end(); ++it)
            printf("%d ", *it);
        printf("\n");
#endif
    }
#ifdef DEBUG
    for (int i = 0; i < size_edge; ++i) {
        for (int j = 0; j < n_edge; ++j) {
            printf("(%d,%d) ", e_a[i][j], e_b[i][j]);
        }
        printf("\n");
    }
#endif
#ifdef MEASURE_TIME
    start_clock = chrono::high_resolution_clock::now();
#endif
    for (int t = 0; t < qtd; ++t) {
        solution = false;
        for (int w = 0; w < size_edge-1; ++w) {

            // configure initial position
            for (int i = 0; i < n_node; i++) {
                pos_x[i] = -1;
                pos_y[i] = -1;
            }
            any_sol = true;

            // configure initial grid
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)                    
                    grid[i][j] = -1;

            a = e_a[w][0]; 

            pos_a_x = pos_x[a] = rand() % n;
            pos_a_y = pos_y[a] = rand() % n;
            
            grid[pos_a_x][pos_a_y] = a;

#ifdef DEBUG
            for (int i = 0; i < n_edge; ++i) {
                printf("%d %d\n", e_a[w][i], e_b[w][i]);
            }
#endif
            //---------------------------------------------- algorithm placement
            for (int i = 0; i < n_edge; ++i) {
                any_sol = true;
                a = e_a[w][i];
                b = e_b[w][i];
                pos_a_x = pos_x[a];
                pos_a_y = pos_y[a];
                pos_b_x = pos_x[b];
                pos_b_y = pos_y[b];
#ifdef DEBUG
                printf("%d -> %d\n", a, b);
#endif                
                // if position not set
                if (pos_a_x == -1) {
                    j = 0;
                    k = rand() % WALK;
                    while (pos_a_x == -1) {
#ifdef DEBUG
                        if (j == 0) printf("pos to %d\n", a);
#endif

                        if (pos_b_x == -1) {
                            xi = (rand() % n) + offset_x[k][j];
                            xj = (rand() % n) + offset_y[k][j];
                        } else { // pos_b already set
                            xi = pos_b_x + offset_x[k][j];
                            xj = pos_b_y + offset_y[k][j];
                        }

                        ++j;
#ifdef DEBUG
                        printf("try pos (%d, %d)\n", xi, xj);
#endif
                        if (xi < n && xi >= 0 && xj < n && xj >= 0 && grid[xi][xj] == -1) {
                            grid[xi][xj] = a;
                            pos_x[a] = pos_a_x = xi;
                            pos_y[a] = pos_a_y = xj; 
                        } else if (j >= size_off) {
#ifdef DEBUG
                            printf("No solution\n");
#endif
                            any_sol = false;
                            break;
                        }
                    }
                }

                if (pos_b_x == -1 && any_sol) {
                    j = 0;
                    k = rand() % WALK;
                    while (pos_b_x == -1) {
#ifdef DEBUG
                        if (j == 0) printf("pos_b\n");
#endif
                        // strategy local
                        xi = pos_a_x + offset_x[k][j]; 
                        xj = pos_a_y + offset_y[k][j];
                        
                        ++j;
#ifdef DEBUG
                        printf("try pos (%d, %d)\n", xi, xj);
#endif
                        if (xi < n && xi >= 0 && xj < n && xj >= 0 && grid[xi][xj] == -1) {
                            grid[xi][xj] = b;
                            pos_b_x = pos_x[b] = xi;
                            pos_b_y = pos_y[b] = xj;
                            break; // ok!
                        } else if (j >= size_off) {
#ifdef DEBUG
                            printf("No solution\n");
#endif
                            any_sol = false;
                            break;
                        }
                    }
                }

                if (!any_sol) break;
#ifdef DEBUG
                printf("%d (%d,%d) -> %d (%d,%d)\n", a, pos_a_x, pos_a_y, b, pos_b_x, pos_b_x);
#endif
            }
#ifdef MEASURE_TIME
            end_clock = chrono::high_resolution_clock::now();
            time_ms = chrono::duration_cast<Seconds>(end_clock - start_clock).count();
#endif
            if (any_sol) {
                eval = evaluate(e_a[w], e_b[w], pos_x, pos_y, n_edge);
                eval_1hop = evaluate_1hop(e_a[w], e_b[w], pos_x, pos_y, n_edge);
            } else {
                eval = 9999;
                eval_1hop = 9999;
            }

            if (eval <= best_evaluate && eval_1hop < best_evaluate_1hop){
                best_evaluate = eval;
                best_evaluate_1hop = eval_1hop;
                best_w = w;
                solution = (eval == 0 || eval_1hop == 0);

#ifdef PRINT
                for(int ii = 0; ii < n_node; ii++) {
                    best_pos_x[ii] = pos_x[ii];
                    best_pos_y[ii] = pos_y[ii];
                } 
                for (int ii = 0; ii < n; ++ii)
                    for (int jj = 0; jj < n; ++jj) 
                        best_grid[ii][jj] = grid[ii][jj];
#endif
                    
                if (solution) break;
            }
        }
        if (solution) {
            //printf("Better solution walking: %d\n", w);
            break;
        }
    }
#ifdef PRINT
    // Print Results
    if (best_evaluate != 9999) {
        evaluate_final(e_a[best_w], e_b[best_w], best_pos_x, best_pos_y, n_edge);
        printf("\n");
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                printf("%3d ", best_grid[i][j]);
            }
            printf("\n");
        }
        printf("\nEvaluation = %d", best_evaluate);
        printf("\nEvaluation 1-hop = %d\n", best_evaluate_1hop);
    } else {
        printf("No solution!\n");
    }
#ifdef MEASURE_TIME
    cout << "Time placement: " << time_ms * 1000 << " ms\n";
#endif
#else
    printf("%s, %d, %d, %lf\n",
        name.c_str(), 
        best_evaluate,
        best_evaluate_1hop,
        time_ms * 1000
    );
#endif
}

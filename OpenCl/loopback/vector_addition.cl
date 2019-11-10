
#define BUFFER_SIZE 256
#define DATA_SIZE 1024

//TRIPCOUNT indentifier
__constant uint c_len = DATA_SIZE/BUFFER_SIZE;
__constant uint c_size = BUFFER_SIZE;

kernel __attribute__((reqd_work_group_size(1, 1, 1)))
void vector_add(global int* c,
                global const int* a,
                       const int n_elements)
{
    int arrayA[BUFFER_SIZE];
    int arrayB[BUFFER_SIZE];
    
    __attribute__((xcl_loop_tripcount(c_len, c_len)))
    for (int i = 0 ; i < n_elements ; i += BUFFER_SIZE) {
        int size = BUFFER_SIZE;
        
        if (i + size > n_elements) size = n_elements - i;

        __attribute__((xcl_loop_tripcount(c_size, c_size)))
        __attribute__((xcl_pipeline_loop(1)))
        readA: for (int j = 0 ; j < size ; j++) {
                arrayA[j] = a[i+j]; }

        __attribute__((xcl_loop_tripcount(c_size, c_size)))
        __attribute__((xcl_pipeline_loop(1)))
        vadd_writeC: for (int j = 0 ; j < size ; j++) {
                c[i+j] = arrayA[i];
        }
    }
}

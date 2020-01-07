#define BUFFER_SIZE 256
#define DATA_SIZE 1024

//TRIPCOUNT indentifier
__constant uint c_len = DATA_SIZE/BUFFER_SIZE;
__constant uint c_size = BUFFER_SIZE;

kernel __attribute__((reqd_work_group_size(1, 1, 1)))
void vector_add(global int* c,
                global const int* a,
                global const int* b,
                global const int* d,
                global const int* e,
                global const int* f,
                global const int* g,
                global const int* h,
                       const int n_elements)
{
    int arrayA[BUFFER_SIZE];
    int arrayB[BUFFER_SIZE];
    int arrayD[BUFFER_SIZE];
    int arrayE[BUFFER_SIZE];
    int arrayF[BUFFER_SIZE];
    int arrayG[BUFFER_SIZE];
    int arrayH[BUFFER_SIZE];

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
        readB: for (int j = 0 ; j < size ; j++) {
                arrayB[j] = b[i+j]; }

        __attribute__((xcl_loop_tripcount(c_size, c_size)))
        __attribute__((xcl_pipeline_loop(1)))
        readD: for (int j = 0 ; j < size ; j++) {
                arrayD[j] = d[i+j]; }

        __attribute__((xcl_loop_tripcount(c_size, c_size)))
        __attribute__((xcl_pipeline_loop(1)))
        readE: for (int j = 0 ; j < size ; j++) {
                arrayE[j] = e[i+j]; }

        __attribute__((xcl_loop_tripcount(c_size, c_size)))
        __attribute__((xcl_pipeline_loop(1)))
        readF: for (int j = 0 ; j < size ; j++) {
                arrayF[j] = f[i+j]; }

        __attribute__((xcl_loop_tripcount(c_size, c_size)))
        __attribute__((xcl_pipeline_loop(1)))
        readG: for (int j = 0 ; j < size ; j++) {
                arrayG[j] = g[i+j]; }

        __attribute__((xcl_loop_tripcount(c_size, c_size)))
        __attribute__((xcl_pipeline_loop(1)))
        readH: for (int j = 0 ; j < size ; j++) {
                arrayH[j] = h[i+j]; }

        __attribute__((xcl_loop_tripcount(c_size, c_size)))
        __attribute__((xcl_pipeline_loop(1)))
        vadd_writeC: for (int j = 0 ; j < size ; j++) {
                c[i+j] = (arrayB[i]*arrayB[i]*arrayB[i]*arrayB[i]*arrayA[i]) + 4*(arrayF[i]*arrayF[i]*arrayF[i]*arrayB[i]*arrayG[i]) + 6*(arrayB[i]*arrayB[i])*(arrayF[i]*arrayF[i]*arrayD[i])
								+ (arrayF[i]*arrayF[i]*arrayF[i]*arrayF[i]*arrayE[i]) + 4*(arrayB[i]*arrayB[i]*arrayB[i]*arrayF[i]*arrayD[i]); }
    }
}
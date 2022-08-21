#include <iostream>
#include <pthread.h>
#include <thread>
#include <assert.h>
#include <omp.h>
#include <math.h>

//#define MULTITHREADING    // uncomment this to use multithreading

struct Data {
    int *array1;
    int *array2;
    int *array3;
    int id;
    int length;
};

#ifdef MULTITHREADING
const unsigned int num_threads = std::thread::hardware_concurrency();
#else
const unsigned int num_threads = 1;
#endif

void *thread_function(void *data);
int do_evaluation(int x, int y);

int main()
{
    double start_s, stop_s;

    std::cout << num_threads << " concurrent threads are supported." << std::endl;
    int length = 12 * (1 << 19);
    std:: cout << "Length of arrays = " << length << std::endl;
    int *array1 = new int[length];
    int *array2 = new int[length];
    int *array3 = new int[length];

    for (int i = 0; i < length; i++) {
        array1[i] = i;
        array2[i] = 2*i;
        array3[i] = 0;
    }

    pthread_t thread[num_threads];
    Data data[num_threads];

    start_s = omp_get_wtime();
    for(int id=0; id < num_threads; id++) {
        data[id] = {
            .array1 = array1,
            .array2 = array2,
            .array3 = array3,
            .id = id,
            .length = length
        };
        int ret = pthread_create( &thread[id], NULL, thread_function, &data[id] );
        if (ret) {
            fprintf(stdout,"Error - pthread_create() return code: %d\n", ret);
            exit(EXIT_FAILURE);
        }
    }

    for(int id=0; id < num_threads; id++)
        pthread_join( thread[id], NULL);

    stop_s = omp_get_wtime();
    std::cout << "Evaluation time = " << stop_s - start_s << " s" << std::endl;

    for (int i = 0; i < length; i++) {
//        std::cout << array3[i] << " " << do_evaluation(i, 2*i) << std::endl;
        assert(array3[i] == do_evaluation(i, 2*i));
    }

    delete[] array1;
    delete[] array2;
    delete[] array3;

    return 0;
}

void *thread_function(void *input)
{
    Data data = *(Data *)input;
    int th_length = data.length / num_threads;
    int offset = th_length * data.id;

    for (int i = offset; i < offset + th_length; i++)
        data.array3[i] = do_evaluation(data.array1[i], data.array2[i]);
}

int do_evaluation(int x, int y)
{
    return exp(cos(x + y)) + sin(x - y);
}

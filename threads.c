/* ******************************************************************
 *  FIT5003: Software Security - Assignment # 1
 *
 * The program creates a number of threads and performs a timing 
 * analysis on when and how the threads are being executed in a 
 * time sharing multiprogramming system. 
 *
 * Compilation: $ gcc -o ProgramName PROGNAME.c -l pthread
 *
 * Execute from the command line as follows:
 *
 * :$ ./ProgramName <number-of-threads> <increment>
 *
 * *******************************************************************
*/

#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <error.h>


// Mutex for the threads
pthread_mutex_t lock;
        
// Function prototype
void *compute_factorial(void *args), *arg; 

// Main function
int main(int argc, char *argv[])
{

        // Declare some variables...
        int err;
        int threads_created = 0;

        // Variables for the timing of the program...
        clock_t start, finish;
        double cpu_time;
        start = clock();

        // These variables are for the command line sanitising...
        int base = 10; 
        char *arg1, *arg2, *endptr;
        
        // Include a how to use message... 
        char usage[] = "ProgramName <increment (min 1, max 8)> <number-of-threads (min 1, max 8)>";
        
        /* Check input is safe... */
        if (argc != 3) // Correct number of arguments for the program is 3 (including program name)
        {
                printf("\n%s\n", usage);
                return -1;
        }

        if (argv[1][0] == '-' || argv[2][0] == '-') 
        {
              printf("%s\n", "No NEGATIVE values!");
              printf("\n%s\n", "Program exiting...");
              return -1;
        }

        arg1 = argv[1];
        arg2 = argv[2];

        // Parse the cmd line arguments
        // - uses the strtoul() function from the stdlib.h
        int increment = strtoul(arg1, &endptr, base);
        int numthreads = strtoul(arg2, &endptr, base);
        
        // Check for out of range values
        if (increment < 0 || increment > 8)
        {
                printf("\n%s\n%s\n", "Value out of range", usage);
                return -1;
        }
        if (numthreads < 0 || numthreads > 8)
        {
                printf("\n%s\n%s\n", "Value out of range", usage);
                return -1;
        }
        /* End chcking of command line input. */
 
        printf("\n%s", "Arguments entered");
        printf("\n%s%d", "-> increment: ",increment);
        printf("\n%s%d\n", "-> numthreads: ", numthreads);


        // An array for the increment
        int inc[increment];
        for (int i = 0; i < increment; i++)
               inc[i] = i; 
        // An array for thread ids
        pthread_t nthr[numthreads];
        for (int i = 0; i < numthreads; i++)
                nthr[i] = i;

        // The thread creation loop
        for (int i = 0; i < numthreads; i++)
        {
                pthread_t tid = i; // set the thread ids to the value of i
                printf("\n%s%i\n", "Creating thread ", i);
                
                err = pthread_create(&nthr[i], NULL, compute_factorial, (void *) &inc[i]);

                if (err != 0)
                {
                        printf("\n%s\n", "Error creating thread!");
                }
                threads_created += 1;
        }

        printf("\n%s%d\n","threads created:", threads_created);

        // Clean up
       for (int j = 0; j < numthreads; j++)
        {
                int thrd_join;
                thrd_join = pthread_join(nthr[j], NULL);
                if (thrd_join != 0)
                        perror("pthread_join");
        }

        // Calculate the final time taken in CPU time consumed
        finish = clock();
        cpu_time = ((double) (finish - start) / CLOCKS_PER_SEC);
        printf("\n\n%s%ld\n", "Time taken: ", cpu_time);

}

void *compute_factorial(void *args)
{
        // Lock the mutex.
        pthread_mutex_lock(&lock);

        int result = 0;
        int* increment = *((int *)args);
        
        // Factorial calculation performed here
        for (int i = 1; i < (int)increment; i++)
        {
           result += i * (int)increment;
        }
        // Unlock the mutex.
        pthread_mutex_unlock(&lock);
}



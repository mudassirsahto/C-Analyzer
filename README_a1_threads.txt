*******************************
  Assignment 1 - Readme file 
*******************************

The code was written on a 32-bit Lubuntu virtual machine. To compile the program, use the following command:

$ gcc -o a1_threads a1_threads.c -l pthread

The program is command line based, taking two integers as arguments. An error will occur should unacceptable inputs be provided. The program may be launched as follows:

$ ./a1_threads <increment> <number of threads>

The maximum number for both is set at 8; any more than this and the machine encountered an error on the machine on which it was written. Results may vary.

The code implements (poorly) the computation of the factorial of the increment as a means of utilizing CPU time. Generally, this does not return the correct result, and in fact does not return any result; this is purely a time-wasting function. 

The timing of the program is calculated by using the CPU time, the time it takes for the CPU to run the program. Only the elapsed time of the program as a whole has been implemented, not per thread. It can give some odd results, such as a negative number, the reason for which eludes the programmer.

Additional documentation throughout the code.

The only detected security anomaly found was related to the printf(), however, this was only conducted using the free "rats" and "flawfinder" tools. 

===========
References:

Kerrisk, M.(2010). 'Threads: Thread Syncronization', The Linux Programming Interface, pp. 632-653, No Starch Press.

Lars.(2011).'How to measure the ACTUAL execution time of a C program under Linux?', StackOverflow.com, http://stackoverflow.com/questions/7215764/how-to-measure-the-actual-execution-time-of-a-c-program-under-linux
# Static-Source-Code-Analysis (Code Review)
Static Source Code Analysis using a simple program which examines a simple C / C++ code and reports for common issues such as syntax errors, unused variables, and potential memory-related risks.

Download the code and run the following command on linux terminal:
   $ gcc -o a1_threads a1_threads.c -l pthread
   
This will compile the code and report errors identified by the compiler as shown below:

![alt text](https://image.ibb.co/nkwfC7/error.png)

By passing the file to the program flawfinder the following output is display:

![alt text](https://image.ibb.co/dmu0C7/p2.png)

And By passing the file to Cppcheck program, the following results are displayed:

![alt text](https://image.ibb.co/eSZNAS/cppcheck.png)

# Description of Vulnerabilities:

    Assigning an integer to a pointer is not portable.
•	 Line 138: Assigning an integer (int/long/etc) to a pointer is not portable across different platforms and compilers. For example in 32-bit Windows and linux they are same width, but in 64-bit Windows and linux they are of different width. In worst case you end up assigning 64-bit integer to 32-bit pointer. The safe way is to store addresses only in pointer types (or typedefs like uintptr_t).  
•	Line 128: %ld in format string (no. 2) requires 'long' but the argument type is 'double'.  
•	Line 102: Variable 'tid' is assigned a value that is never used.\n

Further vulnerabilities observed:

•	There is no checking of null values being entered in the ‘main’, which leads to a vulnerability which may be prone to variable modification.  
•	The program does not check whether the entered input is a valid numeric input (line 51 - 62), thus this program can accept alphabets and characters as well.  
•	There is no means of accepting input from the user anywhere in the code.  
•	On line 73, in the if block where the following condition is given:  
if (increment < 0 || increment > 8)  
The condition will also accept 0 as a value, which is an undesirable value since there is no ‘=’ sign in the condition.



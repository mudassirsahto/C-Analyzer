# Static-Source-Code-Analysis-Code-Review-
Static Source Code Analysis using a simple program which examines a simple C / C++ code and reports for possible security loopholes.

This demonstration checks a simple program written in C for possible security flaws using flawfinder and Cppcheck program. Download the
code and run the following command on linux terminal:
   $ gcc -o a1_threads a1_threads.c -l pthread
   
This will compile the code and report errors identified by the compiler as shown below:

![alt text](https://image.ibb.co/nkwfC7/error.png)

By passing the file to the program flawfinder the following output is display:

![alt text](https://image.ibb.co/dmu0C7/p2.png)

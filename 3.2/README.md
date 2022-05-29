# Assignment 3.2

Write a telbook program or set of programs that will provide the following functionality:

1. Allow creation of telbook file with user specified name and size. The size is in terms of number of telbook entries. Each entry will be 40 characters long: 20 characters for Name and 20 characters for Telephone number. (Hint: Use lseek to create file with hole)

2. On user providing index number program should show the entry corresponding to that index number. (Hint: Use lseek to jump to appropriate offset)

3. On user providing index number and entry (name + telephone number) the program should write the entry at the specified index in the telbook.

All system calls that are used in the above program must be checked for error return.


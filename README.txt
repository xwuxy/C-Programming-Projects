Author: Zhu Junmian(Jimmy) zhujunmi@grinnell.edu
Description:
        This Program prints a hanoi-tower game on the terminal screen.

Extra Credit:
    Please notice I have complete part of the extra credit, that user
    can set arbitraty number of disks in the program.
    I did not complete the second part of the extra credit, to have an
    arbitrary number of towers.

How to Use?
    First, type the command $>make hanoi-curse
    Then, type the command"hanoi-curse",
    folow the instructions and type the size of tower less than 30.
    It would print 3 towers with given size of disks.

    Instructions would also print on the screen.

    Press 'q' to quit the game.
    When one of the disks other than the first one is full,
    the player win the game.

Files:
    list.h  list.c   is the library and implementation of the linked list
    stack.h stack.c is the library and implementation of the stack
    hanoi.h hanoi.c is the library and implementation of the hanoi tower
    structure
    *hanoi-curse.c is the driver and implementation of this game.
    it would print the tower and get user input.

    *For convenience, since I don't expect user to change the file of this
     game, I didn't divide the hanoi-curse.c file into two files including
     a driver file and a implementation file. 

Acknowledgement:
    Please notice that I've used my code for the group lab stack
    During the implementation I always assumed that I am one client
    of the stack.h file. Also, the stack.h file itself is a client of
    the list.h file.

    CSC-161 Course Website


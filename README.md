This lab will build on the concepts learned in the past week and will allow you to practice:

    Pointers
    Dynamic allocation (i.e. heap instead of stack)
    Reading a file
    Writing a file
    Functional patterns

Fundamentally, this lab is quite similar to the previous lab. You will be reading in line by line from a file and adding those lines to a list. This time, the list will be dynamic. Before you begin, be sure you understand:

https://github.com/tjklemz/cst126/blob/main/inits.cpp (Links to an external site.)

and:

https://github.com/tjklemz/cst126/blob/main/lab1.cpp (Links to an external site.)

We will be following the new rubric from here on out. There will be a total of 4 points, with each point being a level:
Levels 	Description / Criteria 	Potential Emotion
0 	No work done, no points. 	 :'(
1 	Some work done, but code... doesn't work. 	 :(
2 	Code works but with problems (memory leaks, warnings, logical errors). 	 :|
3 	Code works fine with no memory leaks / errors / etc. Also follows any lab-specific requirements (see bottom of Lab). 	 :)
4 	Code has been reviewed by me, and you've applied the updates and suggestions I've given and resubmitted. We also discussed the code. 	 :D

You can check off the lab at any time with me. It does not have to happen in lab, but please use your time wisely. I'm here to help, but you also have to put the work in.

Lab2: Pantry on the Heap

Write a program that keeps an inventory of pantry items for cooking. These ingredients will be stored in a text file that is specified on the command line (you can hardcode it at first, e.g. "pantry.txt"). This file will be read from to get the initial list as well as for storing any updates. The format of the file will be a simple line-by-line where each line is the ingredient name followed by the quantity. You can separate the ingredient name and quantity with a tab character ('\t') or some other single character delimiter (like a semicolon or comma).

When run, your program will display a menu like the following:

    Add ingredient
    Remove ingredient
    Find ingredient
    Edit ingredient
    Display ingredients
    Save
    Quit

After displaying this menu, prompt the user for an option (i.e. a number). When adding or changing an ingredient, remember to update or request the quantity of the ingredient too.

To start with, try getting everything working without worrying about quantities. You can add this feature after you get everything else working.

Remember that we have worked with code that appends to a list dynamically. Adding and removing and finding (and even displaying) are all list actions. That is, they don't technically have anything to do with ingredients. That means we will want the following functions that modify a list on the heap:

    append (already written in class, see: https://github.com/tjklemz/cst126/blob/main/inits.cpp (Links to an external site.) )
    forEach (will use for displaying; already written in class, see: https://github.com/tjklemz/cst126/blob/main/foreach.cpp (Links to an external site.) )
    find (or findIndex)
    remove
    update

If at any point you get stuck, try to work on one of these functions on its own. (And of course, I'm here to help.) Just like I wrote the forEach in class with some dummy data, you could write the find or remove the same way. We want to break down our problem into manageable chunks, and the best way to do that is to think data-first. This means we want to think in terms of lists (for this lab) and not ingredients, even though our list will be handling ingredients.

Requirements:

    Must use new / delete for the list and only allocate what is needed.
    Must accept the filename via a command line argument.
    Must use a lambda w/ forEach.
    Must use a lambda w/ find (or findIndex).

You can first write the program without all of these requirements at first, but you must have all these things in order to get full marks.

As always, please let me know if you need help or are confused on anything. I encourage working together; feel free to pair program at a computer.

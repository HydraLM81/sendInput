# SendInput

A C++ function designed to handle individual keypresses by importing data into a computers keyboard stream

# What I did

I made a function that allows users to more easily use the SendInput function and its corresponding syntax? (don't know how to phrase it) with strings by allowing users to call the `hold()` function with a string as a parameter. 
The individual characters of the string can then be sent to the keyboard stream at the same time (still in the form of the string), hold down the keys individually for a set amount of time, or, through recursion, to press multiple keys at the same time allowing things like `Win + d` (minimize all apps) shortcut to be performed.

# How to import

1: Add `input.cpp` file to the same folder as the project you wish to use this code with

2: Use `#include "input.cpp"` at the top of your file

3: Call `hold();` at any time throughout your program

# What the parameters are

`std::string in` is the string/characters you want the function to put into the keyboard stream

`bool recurse=0` OPTIONAL;  tells the function if it is to hold the keys down simultaniously (used for keyboard shortcuts). Automatically set to false

`int waitAll=0` OPTIONAL; tells the function how long to hold all the characters (if recurse is set to true, don't use this; not tested)

`int waitIndv[]=0` OPTIONAL;  tells the function how lonf to hold each individual character (if recurse is set to true, don't use this; not tested)

`int current=0` DO NOT USE; used to keep track of current number when using recursion

# How to use `hold()`

Call `hold();`  anywhere with the following parameters

`std::string in`: REQUIRED;  either use as `hold("your string");` or `hold(string_variable);`
        for Windows/Start key, type `\x5B`
        for Control (left), type `\xA2`
        for Shift (left; doesn't unpress, working on it), type `\x10`
        for Escape/Esc, type `\x1B`

`bool recurse`: OPTIONAL;  set to true (`hold(var,true)`) to use shortcuts

`int waitAll`: OPTIONAL;  sets the minimum time for each character to be held down (`hold(var1,var2,time)`). I don't recommend using with recurse

`int waitIndv[]`: OPTIONAL;  pass a pointer to an int array (`hold(var1,var2,var3,pointerVar)`) that corresponds to the wait time in seconds you want each individual character to be held. I don't recommend using with recurse

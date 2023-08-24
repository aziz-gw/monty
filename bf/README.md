# Brainfck

Welcome to Brainf*ck directory !

<p align="center">
  <img src="https://th.bing.com/th/id/OIP.nswYjf4nMytCWM4I6lrSgwHaHa?pid=ImgDet&rs=1" alt="Image"/>
</p>


## General

Brainfuck is an esoteric programming language created in 1993 by Urban Müller.

Notable for its extreme minimalism, the language consists of only eight simple commands, a data pointer and an instruction pointer. While it is fully Turing complete, it is not intended for practical use, but to challenge and amuse programmers. Brainfuck requires one to break commands into microscopic steps.

The language's name is a reference to the slang term brainfuck, which refers to things so complicated or unusual that they exceed the limits of one's understanding, as it was not meant or made for designing actual software but to challenge the boundaries of computer programming.

In Brainfuck, the language consists of only eight commands, each represented by a single character. The commands are:

<div align="center">
  <h2>Brainfuck Commands</h2>

  | Command | Description                                    |
  |---------|------------------------------------------------|
  | `>`     | Increment the data pointer (move to the right) |
  | `<`     | Decrement the data pointer (move to the left)  |
  | `+`     | Increment the byte at the data pointer         |
  | `-`     | Decrement the byte at the data pointer         |
  | `.`     | Output the byte at the data pointer as a char  |
  | `,`     | Read one byte of input and store it            |
  | `[`     | Jump forward if the byte at data pointer is 0  |
  | `]`     | Jump back if the byte at data pointer is nonzero|
</div>


## Examples:

### Adding two values
As a first, simple example, the following code snippet will add the current cell's value to the next cell: Each time the loop is executed, the current cell is decremented, the data pointer moves to the right, that next cell is incremented, and the data pointer moves left again. This sequence is repeated until the starting cell is 0.

```
[->+<]
```

This can be incorporated into a simple addition program as follows:

```
++       Cell c0 = 2
> +++++  Cell c1 = 5

[        Start your loops with your cell pointer on the loop counter (c1 in our case)
< +      Add 1 to c0
> -      Subtract 1 from c1
]        End your loops with the cell pointer on the loop counter

At this point our program has added 5 to 2 leaving 7 in c0 and 0 in c1
but we cannot output this value to the terminal since it is not ASCII encoded

To display the ASCII character "7" we must add 48 to the value 7
We use a loop to compute 48 = 6 * 8

++++ ++++  c1 = 8 and this will be our loop counter again
[
< +++ +++  Add 6 to c0
> -        Subtract 1 from c1
]
< .        Print out c0 which has the value 55 which translates to "7"!
```

### Hello World!
The following program prints "Hello World!" and a newline to the screen:

```
[ This program prints "Hello World!" and a newline to the screen, its
  length is 106 active command characters. [It is not the shortest.]

  This loop is an "initial comment loop", a simple way of adding a comment
  to a BF program such that you don't have to worry about any command
  characters. Any ".", ",", "+", "-", "<" and ">" characters are simply
  ignored, the "[" and "]" characters just have to be balanced. This
  loop and the commands it contains are ignored because the current cell
  defaults to a value of 0; the 0 value causes this loop to be skipped.
]
++++++++               Set Cell #0 to 8
[
    >++++               Add 4 to Cell #1; this will always set Cell #1 to 4
    [                   as the cell will be cleared by the loop
        >++             Add 2 to Cell #2
        >+++            Add 3 to Cell #3
        >+++            Add 3 to Cell #4
        >+              Add 1 to Cell #5
        <<<<-           Decrement the loop counter in Cell #1
    ]                   Loop until Cell #1 is zero; number of iterations is 4
    >+                  Add 1 to Cell #2
    >+                  Add 1 to Cell #3
    >-                  Subtract 1 from Cell #4
    >>+                 Add 1 to Cell #6
    [<]                 Move back to the first zero cell you find; this will
                        be Cell #1 which was cleared by the previous loop
    <-                  Decrement the loop Counter in Cell #0
]                       Loop until Cell #0 is zero; number of iterations is 8

The result of this is:
Cell no :   0   1   2   3   4   5   6
Contents:   0   0  72 104  88  32   8
Pointer :   ^

>>.                     Cell #2 has value 72 which is 'H'
>---.                   Subtract 3 from Cell #3 to get 101 which is 'e'
+++++++..+++.           Likewise for 'llo' from Cell #3
>>.                     Cell #5 is 32 for the space
<-.                     Subtract 1 from Cell #4 for 87 to give a 'W'
<.                      Cell #3 was set to 'o' from the end of 'Hello'
+++.------.--------.    Cell #3 for 'rl' and 'd'
>>+.                    Add 1 to Cell #5 gives us an exclamation point
>++.                    And finally a newline from Cell #6
```

For "readability", this code has been spread across many lines, and blanks and comments have been added. Brainfuck ignores all characters except the eight commands `+-<>[],.` so no special syntax for comments is needed (as long as the comments do not contain the command characters). The code could just as well have been written as:
```
++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.
```

## Compilation :

1- You can install the `bf` interpreter to test the codes:
```
sudo apt-get install bf
```
2- Run the Interpreter:
```
bf file.bf
```
Replace `file.bf` with the actual name of your Brainfuck code file.

This should execute your Brainfuck code and display the output in the terminal. Remember that Brainfuck is a very minimalistic and esoteric programming language, so your code might produce unexpected or complex output based on the logic you've used in the code.

## Source : [Wikipedia](https://en.wikipedia.org/wiki/Brainfuck)

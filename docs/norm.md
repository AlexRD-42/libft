## 1 Naming

- A structure’s name must start by s_
- A typedef’s name must start by t_
- A union’s name must start by u_
- An enum’s name must start by e_
- A global’s name must start by g_
- Identifiers, like variables, functions names, user defined types, can only contain
	lowercases, digits and ’_’ (snake_case). No capital letters are allowed.
- Files and directories names can only contain lowercases, digits and ’_’ (snake_case).
- Characters that aren’t part of the standard ASCII table are forbidden, except inside
	litteral strings and chars.
- _(*)_ All identifiers (functions, types, variables, etc.) names should be explicit, or a
	mnemonic, should be readable in English, with each word separated by an underscore.
	This applies to macros, filenames and directories as well.
- Using global variables that are not marked const or static is forbidden and is considered
	a norm error, unless the project explicitly allows them.
- The file must compile. A file that doesn’t compile isn’t expected to pass the Norm.


## 2 Formatting

- Each function must be at most 25 lines long, not counting the function’s own braces.
- Each line must be at most 80 columns wide, comments included. Warning: a tabulation
	doesn’t count as a single column, but as the number of spaces it represents.
- Functions must be separated by an empty line. Comments or preprocessor instruc-
    tions can be inserted between functions. At least an empty line must exists.
- You must indent your code with 4-char-long tabulations. This is not the same as 4
    spaces, we’re talking about real tabulations here (ASCII char number 9). Check that
    your code editor is correctly configured in order to visually get a proper indentation
    that will be validated by thenorminette.
- Blocks within braces must be indented. Braces are alone on their own line, except
    in declaration of struct, enum, union.
- An empty line must be empty: no spaces or tabulations.
- A line can never end with spaces or tabulations.
- You can never have two consecutive empty lines. You can never have two consecu-
    tive spaces.
- Declarations must be at the beginning of a function.
- All variable names must be indented on the same column in their scope. Note:
    types are already indented by the containing block.
- The asterisks that go with pointers must be stuck to variable names.
- One single variable declaration per line.
- Declaration and an initialisation cannot be on the same line, except for global
    variables (when allowed), static variables, and constants.
- In a function, you must place an empty line between variable declarations and the
    remaining of the function. No other empty lines are allowed in a function.
- Only one instruction or control structure per line is allowed. Eg.: Assignment in
    a control structure is forbidden, two or multiple assignments on the same line is
    forbidden, a newline is needed at the end of a control structure, ....
- An instruction or control structure can be split into multiple lines when needed.
    The following lines created must be indented compared to the first line, natural
    spaces will be used to cut the line, and if applies, operators will be at the beginning
    of the new line and not at the end of the previous one.
- Unless it’s the end of a line, each comma or semi-colon must be followed by a space.
- Each operator or operand must be separated by one - and only one - space.
- Each C keyword must be followed by a space, except for keywords for types (such
    as int, char, float, etc.), as well as sizeof.


- Control structures (if, while..) must use braces, unless they contain a single in-
    struction on a single line.


```c
int g_global;
typedef struct s_struct
{
	char *my_string;
	int i;
}	t_struct;
struct	s_other_struct;

int main( void )
{
	int		i;
	char	c;
	return (i);
}
```

## 3 Functions

- A function can take 4 named parameters at most.
- A function that doesn’t take arguments must be explicitly prototyped with the
    word "void" as the argument.
- Parameters in functions’ prototypes must be named.
- You can’t declare more than 5 variables per function.
- Return of a function has to be between parenthesis, unless the function returns nothing.
- Each function must have a single tabulation between its return type and its name.

```
int my_func( int arg1, char arg2, char *arg3)
{
return (my_val);
}
int func2( void )
{
return ;
}
```

## 4 Typedef, struct, enum and union

- As other C keywords, add a space between “struct” and the name when declaring a struct.
- When declaring a variable of type struct, apply the usual indentation for the name
    of the variable. Same applies to enum and union.
- Inside the braces of the struct, enum, union, regular indentation rules apply, like
    any other blocks.
- As other C keywords, add a space after “typedef”, and apply regular indentation
    for the new defined name.
- You must indent all structures’ names on the same column for their scope.
- You cannot declare a structure in a .c file.


## 5 Headers - a.k.a include files

- _(*)_ The allowed elements of a header file are: header inclusions (system or not),
    declarations, defines, prototypes and macros.
- All includes must be at the beginning of the file.
- You cannot include a C file in a header file or another C file.
- Header files must be protected from double inclusions. If the file isft_foo.h, its
    bystander macro isFT_FOO_H.
- _(*)_ Inclusion of unused headers is forbidden.
- Header inclusion can be justified in the .c file and in the .h file itself using comments.

```c
#ifndef FT_HEADER_H
# define FT_HEADER_H
# include <stdlib.h>
# include <stdio.h>
# define FOO "bar"
int	g_variable;
struct s_struct;
#endif
```

## 6 The 42 header - a.k.a start a file with style

- Every .c and .h file must immediately begin with the standard 42 header: a multi-
    line comment with a special format including useful informations. The standard
    header is naturally available on computers in clusters for various text editors (emacs:
    usingC-c C-h, vim using:StdheaderorF1, etc...).
- _(*)_ The 42 header must contain several informations up-to-date, including the cre-
    ator with login and student email (@student.campus), the date of creation, the login
    and date of the last update. Each time the file is saved on disk, the information
    should be automatically updated.

```
The default standard header may not automatically be configured with
your personnal information. You may need to change it to follow the
previous rule.
```

## 7 Macros and Pre-processors

- _(*)_ Preprocessor constants (or #define) you create must be used only for literal
    and constant values.
- _(*)_ All #define created to bypass the norm and/or obfuscate code are forbidden.
- _(*)_ You can use macros available in standard libraries, only if those ones are allowed
    in the scope of the given project.
- Multiline macros are forbidden.
- Macro names must be all uppercase.
- You must indent preprocessor directives inside #if, #ifdef or #ifndef blocks.
- Preprocessor instructions are forbidden outside of global scope.


## 8 Forbidden stuff!

### You’re not allowed to use:

- for loops, do while, switch, case, goto
- Ternary operators such as ‘?’.
- VLAs - Variable Length Arrays.
- Implicit type in variable declarations

```c
int main( int argc, char **argv)
{
	int i;
	char str[argc]; // This is a VLA
	i = argc > 5? 0 : 1 // Ternary
}
```

## 9 Comments

- Comments cannot be inside function bodies. Comments must be at the end of a
    line, or on their own line
- _(*)_ Your comments should be in English, and useful.
- _(*)_ A comment cannot justify the creation of a carryall or bad function.

```
A carryall or bad function usually comes with names that are not
explicit such as f1, f2... for the function and a, b, c,.. for
the variables names. A function whose only goal is to avoid the
norm, without a unique logical purpose, is also considered as a
bad function. Please remind that it is desirable to have clear and
readable functions that achieve a clear and simple task each. Avoid
any code obfuscation techniques, such as the one-liner, ....
```

## 10 Files

- You cannot include a .c file in a .c file.
- You cannot have more than 5 function-definitions in a .c file.


## 11 Makefile

Makefiles aren’t checked by thenorminette, and must be checked during evaluation by
the student when asked by the evaluation guidelines. Unless specific instructions, the
following rules apply to the Makefiles:

- The _$(NAME)_ , _clean_ , _fclean_ , _re_ and _all_ rules are mandatory. The _all_ rule must be
    the default one and executed when typing justmake.
- If the makefile relinks when not necessary, the project will be considered non-
    functional.
- In the case of a multibinary project, in addition to the above rules, you must have
    a rule for each binary (eg: $(NAME_1), $(NAME_2), ...). The “all” rule will
    compile all the binaries, using each binary rule.
- In the case of a project that calls a function from a non-system library (e.g.:libft)
    that exists along your source code, your makefile must compile this library auto-
    matically.
- All source files needed to compile your project must be explicitly named in your
    Makefile. Eg: no “*.c”, no “*.o” , etc ...
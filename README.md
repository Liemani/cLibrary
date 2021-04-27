# cLibrary

This library makes c language like OOP

## Index

- supporting type
- supporting method
- Description
- Example
- Details

## supporting type

- Class         t\_class
- List          t\_list
- Pair          t\_pair
- Dictionary    t\_dictionary
- String        t\_string

## supporting method

- new
- dealloc
- description

## Feature

This library use 'main()' internally. So instead of main(), you have to implement `int  program(int argc, char **argv)` which is called in main() of library.

You can test the example `program.c` file.

- `<Class>->new()`: create new \<Class\>'s \<instance\>
- `<Class>->dealloc(<instance>)`: dealloc \<instance\>
- `<Class>->description(<instance>)`: print description of \<instance\>

#### dealloc(), description()

- `dealloc(<instance or Class>)`: dealloc \<instance\> or \<Class\>
- `description(<instance or Class>)`: return `t\_string` describing \<instance\> or \<Class\>

`dealloc()` and `description()` function uses a appropriate function for the argument.

#### flushing t\_string

- `stringFlush(<string>)` will print the value and dealloc string.
- `stringprettyFlush(<string>)` will print the value pretty and dealloc string.

## Example

```c
// program.c
#include <stdio.h>                     
                                       
#include "cLibrary.h"                  
                                       
                                       
                                       
int	program(int argc, char **argv)
{
	t_dictionary	*dictionary = Dictionary->new();

	t_string		*key = initString("hi!");
	t_string		*value = initString("there!");

	dictionaryUpdate(dictionary, key, value);

	stringPrettyFlush(description(dictionary));
	printf("\n\n");

	stringPrettyFlush(description(String));
	printf("\n\n");

	stringPrettyFlush(description(Dictionary));
	printf("\n\n");

	stringPrettyFlush(description(Class));
	printf("\n");

	return (0);
}
```

```zsh
% make test
...
% ./program.out
[
	"hi!": "there!"
]


{
	"type": "Class",
	"new": "0x10460af4c",
	"dealloc": "0x10460a7a8",
	"description": "0x10460a7f8",
	"instances": [
		"0x13d606a40",
		"0x13d606910",
		"0x13d6068b0",
		"0x13d606880"
	]
}


{
	"type": "Class",
	"new": "0x10460b8ec",
	"dealloc": "0x10460b588",
	"description": "0x10460b5fc",
	"instances": [
		"0x13d606860"
	]
}


{
	"type": "KernelClass",
	"new": "0x10460a018",
	"dealloc": "0x104609908",
	"description": "0x104609998",
	"classes": [
		{
			"type": "Class",
			"new": "0x10460b8ec",
			"dealloc": "0x10460b588",
			"description": "0x10460b5fc",
			"instances": [
				"0x13d606860"
			]
		},
		{
			"type": "Class",
			"new": "0x10460b4ac",
			"dealloc": "0x10460b354",
			"description": "0x10460b398",
			"instances": [
				"0x13d6068e0"
			]
		},
		{
			"type": "Class",
			"new": "0x10460b26c",
			"dealloc": "0x10460b044",
			"description": "0x10460b0b8",
			"instances": [
				null
			]
		},
		{
			"type": "Class",
			"new": "0x10460af4c",
			"dealloc": "0x10460a7a8",
			"description": "0x10460a7f8",
			"instances": [
				"0x13d606b50",
				"0x13d606930",
				"0x13d606910",
				"0x13d6068b0",
				"0x13d606880"
			]
		},
		{
			"type": "Class",
			"new": null,
			"dealloc": "0x10460a414",
			"description": "0x10460a424",
			"instances": [
				null
			]
		}
	]
}
```

## Details

For the features described above, this library has this structure:

![image](https://i.imgur.com/q8ILNCo.png)

The function dealloc() or description() actually search it's argument and get the class structure, and call dealloc() or description() of that class structure.

If you want to add your own Class type, you can copy t\_template and imitate t\_list. And modify `Makefile` and `cLibrary.h` a little, then it will work.

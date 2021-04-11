# cLibrary

This library makes c language like OOP

## Index

- supporting type
- supporting method
- Description
- Example
- Details

## supporting type

- List  t\_list
- Pair  t\_pair
- Dictionary  t\_dictionary

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

Here is another features:

- `_dealloc(<instance or Class>)`: dealloc \<instance\> or \<Class\>
- `_description(<instance or Class>)`: print description of \<instance\> or \<Class\>

`_dealloc()` and `_description()` function uses a appropriate function for the argument.

All classes and instances will be freed when called exit() or return of main.

## Example

```c
// program.c
#include <stdio.h>                     
                                       
#include "cLibrary.h"                  
                                       
                                       
                                       
int program(int argc, char **argv)     
{                                      
    t_list  *list;                     
                                       
    _description(Class);                
    printf("\n\n");                    
                                       
    printf("list = List->new(); \n\n");
    list = List->new();                
                                       
    _description(Class);                
    printf("\n\n");                    
                                       
    printf("dealloc(list); \n\n");     
    _dealloc(list);                     
                                       
    _description(Class);                
    printf("\n\n");                    
                                       
    printf("dealloc(Null); \n\n");     
    _dealloc(Null);                     
                                       
    _description(Class);                
    printf("\n\n");                    
                                       
    printf("dealloc(List); \n\n");     
    _dealloc(List);                     
                                       
    _description(Class);                
    printf("\n\n");                    
                                       
    printf("dealloc(Class); \n\n");    
    _dealloc(Class);                    
                                       
    _description(Class);                
    printf("\n\n");                    
                                       
    return (0);                        
}                                      
```

```zsh
% make test
...
% ./program.out
Class: [ new: 0x100f7b1a4, dealloc: 0x100f7b070, description: 0x100f7b0b4,
         classList: [ t_class: [ new: 0x100f7bb60, dealloc: 0x100f7b9d4, description: 0x100f7ba48, t_primitiveList: [ NULL ] ],
                      t_class: [ new: 0x100f7b840, dealloc: 0x100f7b84c, description: 0x100f7b85c, t_primitiveList: [ 0x0 ] ] ] ]

list = List->new();

Class: [ new: 0x100f7b1a4, dealloc: 0x100f7b070, description: 0x100f7b0b4,
         classList: [ t_class: [ new: 0x100f7bb60, dealloc: 0x100f7b9d4, description: 0x100f7ba48, t_primitiveList: [ 0x1276067b0 ] ],
                      t_class: [ new: 0x100f7b840, dealloc: 0x100f7b84c, description: 0x100f7b85c, t_primitiveList: [ 0x0 ] ] ] ]

dealloc(list);

Class: [ new: 0x100f7b1a4, dealloc: 0x100f7b070, description: 0x100f7b0b4,
         classList: [ t_class: [ new: 0x100f7bb60, dealloc: 0x100f7b9d4, description: 0x100f7ba48, t_primitiveList: [ NULL ] ],
                      t_class: [ new: 0x100f7b840, dealloc: 0x100f7b84c, description: 0x100f7b85c, t_primitiveList: [ 0x0 ] ] ] ]

dealloc(Null);

Class: [ new: 0x100f7b1a4, dealloc: 0x100f7b070, description: 0x100f7b0b4,
         classList: [ t_class: [ new: 0x100f7bb60, dealloc: 0x100f7b9d4, description: 0x100f7ba48, t_primitiveList: [ NULL ] ] ] ]

dealloc(List);

Class: [ new: 0x100f7b1a4, dealloc: 0x100f7b070, description: 0x100f7b0b4,
         classList: [ NULL ] ]

dealloc(Class);

Class: [ NULL ]

%
```

## Details

For the features described above, this library has this structure:

![image](https://i.imgur.com/q8ILNCo.png)

The function dealloc() or description() actually search it's argument and get the class structure, and call dealloc() or description() of that class structure.

If you want to add your own Class type, you can copy t\_template and imitate t\_list. And modify `Makefile` and `cLibrary.h` a little, then it will work.

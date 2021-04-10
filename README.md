# cLibrary

This library makes c language like OOP

# supporting type

- t\_list  \*List

# supporting method

- new
- dealloc
- description

# Description

You can test the example `program.c` file.

- `<Class>->new()`: create new \<Class\>'s \<instance\>
- `<Class>->dealloc(<instance>)`: dealloc \<instance\>
- `<Class>->description(<instance>)`: print description of \<instance\>

Here is another feature.

- `dealloc(<instance or Class>)`: dealloc \<instance\> or \<Class\>
- `description(<instance or Class>)`: print description of \<instance\> or \<Class\>

`dealloc` and `description` function uses a appropriate function for the argument.

# Details

For the features described above, this library has this structure:

![image](https://i.imgur.com/q8ILNCo.png)

The function dealloc() or description() acrually search it's argument and get the class structure, and call dealloc() or description() of that class structure.

If you want to add your own Class type, you can add one and imitate t\_list. And modify `Makefile` and `cLibrary.h` a little, then it will work.

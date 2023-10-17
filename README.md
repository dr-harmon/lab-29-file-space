# Lab 29: File Space

In this lab we will look at a practical example of postorder traversal using the file system. For example, the file structure of this project is a tree:

    lab-29-file-space/            120 KB
        build/                    114 KB
            lab29_main            101 KB
            CMakeCache.txt         13 KB
        src/                        2 KB
            file_space.cpp          1 KB
            file_space.h            1 KB
        CMakeLists.txt              1 KB
        main.cpp                    1 KB
        README.md                   2 KB

Each file in this directory consumes some amount of data. If we add up all of the data used by all of the files in the directory, we can determine the total space that it uses. For example, the data used by the `build` directory (shown here with some files excluded for brevity) is 114 KB because it contains a 101 KB file and a 13 KB file.

Your task in this lab is to write a program to find the "directory size", meaning the total number of bytes consumed, of any given directory on your computer. You can do this with a postorder traversal of the file system, starting with an initial file path:

    Algorithm getDirectorySize(path):
        Input: A path in the file system
        Output: The total size, in bytes, used by all files in this path
        size ← 0
        if path is a directory then
            for each subpath in the directory
                size ← size + getDirectorySize(subpath)
        else
            size ← number of bytes used by path
        return size

To translate this pseudocode into C++, you can use the built-in `filesystem` library:

* `filesystem::directory_entry(path)`: creates a new `directory_entry` object from the given path.
* `filesystem::directory_entry::is_directory()`: returns true if the entry is a directory, otherwise false.
* `filesystem::directory_entry::path()`: returns a string representation of the directory entry
* `filesystem::directory_entry::file_size()`: returns the number of bytes used by the directory entry
* `filesystem::directory_iterator(path)`: returns an iterator over the directory path, where each entry is another `directory_entry` contained by the directory. For example: `for (const directory_entry& entry : directory_iterator(path)) { ... }`

For more details on these functions and others in the `filesystem` library, search online or visit the C++ reference sites provided in Canvas.

To test your code:

1. Modify `main` to:
    1. Accept arguments (`argc`/`argv`).
    2. Invoke the `getDirectorySize` function by passing it the first argument provided.
    3. Print the result of `getDirectorySize`.
2. Build the project.
3. From a terminal window (such as the one within VS Code), run `./build/lab29_main .`

This should print the total space used by the current directory. Test your code on other directories by replacing `.` with the full path to the directory.

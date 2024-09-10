# Unix-Filesystem-Tree
## Programer Kyan Kotschevar-Smead

This project simulates a Unix shell environment, providing basic filesystem operations.


Demo: https://youtu.be/GF_eHr06B5c

### Commands
- `ls`: List files and directories in the current directory.
- `cd`: Change the current directory.
- `pwd`: Print the current working directory.
- `mkdir`: Create a new directory.
- `rmdir`: Remove an empty directory.
- `touch` (aliased to `creat`): Create a new file.
- `rm`: Remove files or directories.
- `save`: Serialize and save the filesystem tree to a file.
- `reload`: Deserialize and load the filesystem tree from a file.

### Running the Program
Seriaized trees files will be located in the build folder
To run the program, follow these steps:

1. Navigate to the `build` directory then run:
```bash
cd ./build
cmake CMakeLists.txt && make all && ./UFT
./UFT
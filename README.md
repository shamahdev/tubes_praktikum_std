## Running with CodeBlocks

1. Open CodeBlocks
2. Go to File > Open
3. Navigate to the project folder
4. Select `tubes_praktikum_std_kel8.cbp`
5. Click the "Build and Run" or press F9

## Running with VSCode

### Prerequisites

- Install VSCode
- Install C/C++ extension
- Install CMake Tools extension
- Install LLDB debugger
- Install a C++ compiler (GCC/MinGW for Windows, GCC for Linux, or Clang for MacOS)

### Steps

1. Open VSCode
2. File > Open Folder > Select the project folder
3. To build and run:
   - Press F5 to build and run with debugger
   - Or use Command Palette (Ctrl+Shift+P):
     - Run Task > cmake-build to build
     - Run without debugging to execute

The configured tasks will automatically:

- Configure CMake
- Build the project
- Place executables in the `build` folder

## Data Structures Used

- Double Linked List (Flights/Parent)
- Single Linked List (Aircraft/Child)
- Single Linked List (Relations)

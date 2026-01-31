# Basics of Creating C Files in Linux & Using Vi Editor

## 1. Creating C Files in Linux

To create and compile a C file in Linux, follow these steps:

1. Open the terminal.
2. Create a new file using:
   ```bash
   touch filename.c
   ```
   or directly open with:
   ```bash
   vi filename.c
   ```
3. Write your C code inside the file.
4. Save and exit the editor.
5. Compile the file using:
   ```bash
   gcc filename.c -o outputname
   ```
6. Run the program with:
   ```bash
   ./outputname
   ```

### Example Program
```c
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}
```

---

## 2. Using Vi Editor

`vi` (or `vim`) is a text editor available by default in most Linux systems.  
It has **two main modes**:  
- **NORMAL mode** → for navigation and commands.  
- **INSERT mode** → for writing text.  

### Basic Commands
- `vi filename.c` → Open or create a C file  
- `i` → Switch to INSERT mode (start writing)  
- `A` → Move to end of line and switch to INSERT mode  
- `o` → Open a new line below and switch to INSERT mode  
- `Esc` → Return to NORMAL mode  
- `:w` → Save changes  
- `:q` → Quit editor  
- `:wq` → Save and quit  
- `:q!` → Quit without saving  

### Navigation in Vi (Cursor Movements)
- `h` → Move left  
- `l` → Move right  
- `k` → Move up  
- `j` → Move down  
- `0` → Go to beginning of line  
- `$` → Go to end of line  
- `gg` → Go to beginning of file  
- `G` → Go to end of file  

### Editing in Vi
- `x` → Delete a character (under cursor)  
- `X` → Delete a character (before cursor)  
- `dd` → Delete a whole line  
- `yy` → Copy (yank) a line  
- `p` → Paste after cursor  
- `P` → Paste before cursor  
- `u` → Undo last action  
- `Ctrl + r` → Redo  

---

## 3. GCC Compilation Process

GCC (GNU Compiler Collection) compiles C programs in **multiple stages**. You can stop at each stage with different commands:

1. **Preprocessing (expands macros, includes headers):**
   ```bash
   gcc -E filename.c -o filename.i
   ```

2. **Compilation (C to Assembly):**
   ```bash
   gcc -S filename.i -o filename.s
   ```

3. **Assembly (Assembly to Object file):**
   ```bash
   gcc -c filename.s -o filename.o
   ```

4. **Linking (Object file to Executable):**
   ```bash
   gcc filename.o -o outputname
   ```

✅ Usually, GCC does all these steps automatically when you just run:
```bash
gcc filename.c -o outputname
```

---
With these basics, you can **write, edit, and compile C programs in Linux** using `vi` and `gcc` step by step.

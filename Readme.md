# Linux Shell in Language C

### (NOTE) UNIVERSAL Error shown:
   * If the user give a command other than the 10 commands given in the assignment, the program 
     will show command not found.

### Commands:

### 1. ls: Prints the contents of directories.
#####      flags used: ls -1, ls -m
    -1: prints every file/dir in a newline.
    -a: prints directory comma seperated.
    Errors: None

### 2. echo: Prints whatever after echo 
####         flags used: -n, -E 
    -n:  this option is used to omit echoing trailing newline 
    -E:  gives same output as echo without flags.
    Errors: None

### 3. rm: Remove files and using -r can also delete directories
####      flags used: -r, -f
    -r: remove directories and their contents recursively
    -f:  ignore nonexistent files and arguments, never prompt
     Errors Shown:
        - if no file/dir is given after rm it throws an error: missing operand.
        
### 4. cat: Reads and prints files.
####        flags used: -n, -E
    -n:  number all output lines
    -E: display $ at end of each line
    Errors Shown:
        - If file does not exits it will throw an error: no such file or directory


### 5. mkdir: Create directories
####          flags used: --help, -v
    --help: shows help for mkdir.
    -v:  print a message for each created directory
    Errors Show:
        - if no file/dir is given after rm it throws an error: missing operand.
        - if the user does mkdir dir1/dir2 and dir1 doesn't exist it will show an error: directory does not exist.
        - if the user does mkdir hello and hello exits it will again give the same error: File exists.

### 6. date: Shows date 
####         flags used: -u, -R 
    -u: print or set Coordinated Universal Time (UTC)
    -R: output date and time in RFC 5322 format.
    Example: Mon, 14 Aug 2006 02:34:56 -0600
    Errors: None

### 7. cd: Goes into the directory which we specify
####       flags used: --help, -P  
    --help: shows help for cd.
    -P: use the physical directory structure without following
        symbolic links: resolve symbolic links in DIR before
        processing instances of `..'
    Errors: None

### 8. pwd: Shows current directory
####        flags used: --help, -P 
    --help: shows help for pwd.
    -P:  print the physical directory, without any symbolic links
    Errors: None

### 9. history: Showing history of commands.
####            flags used: -a, -c 
        -a: append that command in history.
        -c: clears the history.
    Erros: None

### 10. exit: For exiting program.
####          flags: None
    Error: None


### System Calls Used:
    1)Fork(): Used for creating a new process, known as child process and it concurrently runs with the parent process.
    2)execvp(): the created child process does not have to run the same program as the parent process does. The execvp system call allow a 
    process to run any C file, whose executable file can be made.
    3)chdir():It changes the current directory of the calling process to the directory specified in path.
    4)readdir():This function returns a pointer to a dirent struct variable
    pointing the next directory
    5)opendir():This function opens a directory corresponding to the directory name given and returns a pointer of that directory
    6)wait(): It blocks the calling process until one of the child processes exits. After child process 
    exits or ends, parent continues its execution after wait call instruction.
    7)unlink(): unlink() deletes a file from the filesystem.
    8)remove(): used to delete a file or directory.
    9)mkdir(): creates a new directory of the name passed in it as argument.
    10)getcwd(): used to get current working directory
    11)exit(): exits out of the program.
    >>exit

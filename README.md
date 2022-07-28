# simple_shell

# Main task
Write a simple UNIX command interpreter. How does a shell work and How to create processes

## Processes
- THink of them as instances of running programs. Each has a unique ID when run
- To get the process ID, we use the getpid function like so
-	getpid()
- Every process however has a parent that created it...hence that paret has a parent ID.
- It can be obtained using getppid as below
-	getppid()

# simple-shell

Run the command below to build the shell.

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o simple_shell
After compiling the program, run ./simple_shell to startup the shell in interactive mode. To start the shell in non-interactive mode, run ./simple_shell file, where file is a text-encoded file containing lines of commands to be executed. You can also pipe a string of commands to the program like echo 'echo $PWD' | ./simple_shell to be run in a non-interactive mode.

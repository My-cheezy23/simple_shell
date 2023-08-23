**Simple Shell Overview**

This is a lightweight UNIX Shell.
A command line interpreter designed for basic command execution,
environment variable handling, built-in commands, and logical operations.

**Usage**

Run the shell by executing the "hsh" executable.
It waits for your commands and displays a prompt after each command.
Commands consist of single words.
No arguments are passed to programs.

**Error Handling**

If an **executable** cannot be found, the shell prints an error message and displays
the prompt again. The shell **handles errors** and the **“end of file”** condition
**(Ctrl+D)**.

**Built-in Commands**

	Built-in commands include:
	exit: Exit the shell.
	env: Print current environment.
	cd: Change the current directory.
	setenv: Initialize or modify environment variables.
	unsetenv: Remove an environment variable.
	alias: Define or display command aliases.

**Key Features**

	Process command lines with arguments.
	Handle the system's PATH.
	Avoid unnecessary forking for non-existent commands.
	Support command separation with semicolons.
	Manage logical operators && and ||.
	Implement custom getline function.
	Substitute variables like $? and $$.
	Ignore comments marked with #.
	Accept file input as a command.

**Additional Functions**

	panic: Display an error message and exit.
	run_script: Run a script file.
	parse_line: Parse a command line into tokens.
	launch: Launch an external command as a child process.
	execute: Execute a command line.
	prompt: Display the shell prompt.
	read_line: Read a command line from input.

**Authors**

	Created by:
		1. Lewis Machoka <https://github.com/Machoka-Hub>
		2. Olive Maina <https://github.com/My-cheezy23>

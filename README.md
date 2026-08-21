# Presentation
This project is a simple, smaller version of the UNIX Shell.

# How to use
Once the repo is cloned, make an executable using ``make``. A file named ``shell`` should appear in your working directory. Execute it.

# Features
## Modes
This Shell can either be ran in interactive or non-interactive modes.
Try ``echo "ls" | ./shell`` to enter non-interactive mode.
Try ``./shell`` then ``ls`` to enter interactive mode.

## Path display
Displays the path to the current working directory in command prompt.

## Execution
The Shell successfully executes both command executables or shortcut to commands. Try running ``ls`` or ``./bin/ls`` (or ``./usr/bin/ls`` depending on your system), both should work fine.

## Command line arguments
You can pass arguments into your commands inside the simple Shell. They will be treated the same way the actual Shell does.

## Error handling and exiting
If an error is thrown by a command, the simple Shell writes it in the appropriate channel (usually stderr).
To exit the simple Shell, simply use the ``exit`` keyword, or Ctrl + D (EOF) command.

# About the authors
We are two students in Holberton School France. See [AUTHORS](./AUTHORS) file to contact us.
sample of screen buffer vs file stdout

emulates soft std i/o

Standard Input and Output: The Basic Engine of an Operating System

At the core of every operating system lies a simple yet powerful concept: standard input and output. These are the basic channels through which the system receives and sends data.

The operating system receives input from the keyboard (or another source) through standard input — known as stdin, which is internally identified as file descriptor 0. Functions like getc and fgets read data from this special input stream.

To send data out, the system uses standard output — called stdout, associated with file descriptor 1. Commands like puts and printf write formatted text to this output stream, which by default appears on the console.

There is also a third channel: standard error — stderr, with file descriptor 2. This is where error messages are sent using functions such as perror, keeping them separate from regular output.

By default, these three special files — stdin (0), stdout (1), and stderr (2) — are connected to the console. However, they can be redirected through pipes to other files, devices, serial consoles, or even sent across the internet. This flexibility makes them one of the fundamental building blocks of any operating system’s input/output system.



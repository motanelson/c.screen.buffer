
global file_input
global file_output
global file_error
file_input=False
file_output=False
file_error=False
def opens(handlers):
    global file_input
    global file_output
    global file_error
    if handlers == 0:
        file_input=True
    if handlers == 1:
        file_output=True
    if handlers == 2:
        file_error=True

def closes(handlers):
    global file_input
    global file_output
    global file_error
    if handlers == 0:
        file_input=False
    if handlers == 1:
        file_output=False
    if handlers == 2:
        file_error=False

def writes(handlers:int,s:str):
        global file_input
        global file_output
        global file_error
        if handlers == 1 and file_output:
            print("stdout:>"+s)
        if handlers == 2 and file_error:
           print("stderr:>"+s)


def clear():
    print("\033c\033[43;30m\n")
    opens(0)
    opens(1)
    opens(2)

clear()
writes(1,"hello world...")
writes(2,"error tests")
closes(2)
closes(1)
writes(1,"hello world...")
writes(2,"error tests")


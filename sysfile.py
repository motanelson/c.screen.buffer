import sys
global file1
file1=None


def prints(s:str):
    global file1 
    if file1==None:
        file1=open(sys.stdout.fileno(),"w")
    file1.write(s)
    file1.flush()



prints("\033c\033[43;30m\nhello world............")



file1.close()
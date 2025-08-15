import sys


def prints(s:str):
    sys.stdout.write(s)
    sys.stdout.flush()



prints("\033c\033[43;30m\nhello world............")


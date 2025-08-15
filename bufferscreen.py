global w,h,x,y,buffers,pos

w=80
h=25
x=0
y=0
pos=0
buffers=""

def locates(xx:int,yy:int):
    global w,h,x,y,buffers,pos
    pos=yy*w+xx
def clear():
    global w,h,x,y,buffers,pos
    b=""
    print("\033c\033[43;30m\n") 
    for n in range(w):
        b=b+" "
    for n in range(h):
        buffers=buffers+b

def writes(s:str):
    global w,h,x,y,buffers,pos
    lens=len(s)
    if pos+lens>w*h:
        lens=w*h-pos
    if(pos<w*h):
        lens=pos+lens
        buffers=buffers[:pos]+s+buffers[lens:]
def refresh():
    global w,h,x,y,buffers,pos
    cursor=0
    for n in range(h-1):
        print(buffers[cursor:cursor+w])
        cursor=cursor+w
clear()
locates(4,4)
writes("hello world.....")
refresh()



'type shell.dat | .\commands.exe
dim a as string=""
dim b as string=""
dim count as integer=0
color 0,6
cls
open scrn for output as #1
open command(1) for input as #3


do
    line input #3,a
    write #1,a
    
    if eof(3) then exit do
loop
close #1
close #3

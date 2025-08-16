
'type shell.dat | .\commands.exe
dim a as string=""
dim b as string=""
dim count as integer=0
color 0,6
cls
open scrn for output as #1
open cons for input as #3


do
    line input #3,a
    if rtrim(ltrim(lcase(a)))="exit" then exit do
    
     
    write #1,a
    shell(a)
    if eof(3) then exit do
loop
close #1
close #3
close #4
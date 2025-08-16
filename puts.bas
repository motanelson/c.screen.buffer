open "con:" for output as #1
sub puts(s as string)
   write #1,s
end sub 

color 0,6
cls
puts("hello world.....")



#!/usr/bin/env python3
from subprocess import call
import os 
a = ''
#Deletes 
for i in os.listdir():     
    if ".o" in i:
        os.system("rm -rf " + i) 
os.system("rm -rf Stage") 
#Compiladores 
for i in os.listdir():
    if ".cpp" in i:
        call(['g++','-c',i]) 
for i in os.listdir():
    if ".o" in i:
        a = a+i+' ' 
os.system("g++ --std=c++11 " + a + "-o Stage")  

#Ejecutar 
os.system("./TestStage1  ")

#Limpiar 
for i in os.listdir():
    if ".o" in i:
        os.system("rm -rf " + i)


CC = /opt/csw/gcc3/bin/g++
DebugFlag = -g 

p1: app.o LinkedList.o 
	$(CC) $(DebugFlag) -o p1 app.o LinkedList.o
	
LinkedList.o: LinkedList.cpp LinkedList.h
	$(CC) $(DebugFlag) -c LinkedList.cpp
	
app.o: app.cpp LinkedList.h
	$(CC) $(DebugFlag) -c app.cpp
	
clean:
	/rm -rf *.o p1

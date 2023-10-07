CC = g++
TARGET = P0
OBJS = p0.o tree.o 

.SUFFIXES: .c .o 
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)
p0.o: p0.cpp
	$(CC) -c p0.cpp 
tree.o: tree.cpp 
	$(CC) -c tree.cpp 


.PHONY: clean
clean:
	/bin/rm -f *.o *~ *.inorder *.preorder *.postorder $(TARGET)

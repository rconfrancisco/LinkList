# define the C compiler to use
CC = g++

# define any compile-time flags
CFLAGS = -Wall -g -fpermissive -std=c++11

# define the executable file 
TARGET = LinkList

all: $(TARGET)

LinkList: LinkList.C
	$(CC) $(CFLAGS) -o LinkList LinkList.C

clean:
	$(RM) *.o *~ $(TARGET)


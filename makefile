#Jared Migneco cs4760 proj5 makefile
# due 04-21-22
CC = gcc
CFLAGS = -g

all: oss.c user_proc.c

OSS: oss.c
        gcc -o oss oss.c
user_proc: user_proc.c.c
        gcc -o user_proc user_proc.c

clean:
        -rm *.o $(objects)

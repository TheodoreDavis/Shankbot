ifndef VERBOSE
.SILENT:
endif

CC = gcc

shank: shank.c
	$(CC) -o $@ $^
#pragma once
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
const char *write_fifo ="write_fifo";
const char *read_fifo = "read_fifo";
void write_msg(int fd);
void read_msg(int fd);























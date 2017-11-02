all: stat.c
  gcc -o stat stat.c
run: all
  ./stat

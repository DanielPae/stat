#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
  int fd;
  fd = open("statfile", O_CREAT | O_RDWR, 0644);
  char string[] = "This is a string.This is a string.This is a string.";
  write(fd, string, sizeof(string));
  close(fd);
  
  struct stat sb;
  stat("statfile", &sb);
  
  long int size = sb.st_size;
  printf("File size:\n%ld B\n", size);
  
  
  printf("File permissions: %ud\n", sb.st_mode);
  printf("Time of last access: %s\n", ctime(&(sb.st_atime)));
  
  
}

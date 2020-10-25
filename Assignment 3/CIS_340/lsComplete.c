/*
THis program emulates the function of the ls command. It includes the -l and -a options.
*/

#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <pwd.h>
#include <grp.h>

#define  A_OPT  2             //constants for -a and -l options
#define  L_OPT  1
#define MAX_LEN 50            //maximum size for file name

int dir_size(char []);
char opt_check(int *, char *[]);
void strip(int, int, char *[]);
void get_names(char [], char [][MAX_LEN],char);
void print_l_opt(char [],char [][MAX_LEN],int);
void print_default(char [][MAX_LEN],int);
int order(const void *, const void *);
void mode_to_letters(int,char []);

int main(int argc,char *argv[]){
  char dashOpt = opt_check(&argc, argv);          //gets the -a and -l option if present and stores them in the first and secont binary bits of a char variable
  //no additional dir or files
  if(argc == 1){

    int size = dir_size(".");                     //get the number of entries in a directory
    if((dashOpt & A_OPT) != A_OPT)                //make adjustments ot size if -a is not indocated
      size = size - 2;

    if(size == -1){
      printf("Couldn't open dir");
      exit(0);
    }
    char list_names[size][MAX_LEN];               //create a list of all the files in a directory
    get_names(".", list_names,dashOpt);
    if(dashOpt & L_OPT){
      print_l_opt(".",list_names, size);          //print for -l option inocated
    }
    else{
      print_default(list_names, size);            //print for -l not indocated
    }

  }

//this section if for a specified directory(s)
  else{
    while(--argc){
      int size = dir_size(*++argv);
      if(size != -1){
        if((dashOpt & A_OPT) != A_OPT)
          size = size - 2;

        if(size == -1){
          printf("Couldn't open file");
          //exit(0);
        }
        char list_names[size][MAX_LEN];
        get_names(*argv, list_names,dashOpt);

        printf("\"%s\":\n",*argv);

        if(dashOpt & L_OPT){
          print_l_opt(*argv,list_names, size);
        }
        else{
          print_default(list_names, size);
        }
      }
    }
  }
}

//print default option (no -l option)
void print_default(char list[][MAX_LEN],int length){
  int i;
  for(i=0; i<length; i++){
    if(i%4 == 0 && i != 0)
      printf("\n");
    printf("%-18.18s",list[i]);
  }
  printf("\n\n");
}

//print the -l option
void print_l_opt(char dir[],char list[][MAX_LEN],int length){
  struct stat data;
  char listent[MAX_LEN];
  listent[0] = 0;
  int i;
  for(i=0; i < length; i++){

    //if not the current directory, add the directory name to the front of the file name
    if(strcmp(dir,".")){
      strcpy(listent,dir);
      strcat(listent,"/");
    }
    strcat(listent,list[i]);
    if(stat(listent,&data) != -1){
      char str[10];
      mode_to_letters(data.st_mode, str);
      printf("%s  ", str);
      printf("%2d ", data.st_nlink);
      printf("%-6s ", getpwuid(data.st_uid)->pw_name);
      printf("%6s ", getgrgid(data.st_gid)->gr_name);
      printf("%10d ", data.st_size);
      printf("%12.12s  ", ctime(&data.st_mtime)+4);
      printf("%-18.18s", list[i]);
      printf("\n");
    }
  }
  printf("\n");
}

//returns the number of entries in a directory
int dir_size(char dname[]){
  DIR *dir_ptr;
  struct dirent *direntp;
  if((dir_ptr = opendir(dname)) == NULL){
    printf("Could not open dir %s\n\n",dname);
    return -1;
  }
  int count = 0;
  while((direntp = readdir(dir_ptr)) != NULL){
    count++;
  }
  closedir(dir_ptr);
  return count;
}

//stores a list of the directory content in the char[][]
void get_names(char dirname[], char dir_list[][MAX_LEN],char opt){
  DIR *dir_ptr;
  struct dirent *direntp;
  if((dir_ptr = opendir(dirname)) == NULL){
    printf("Could not open dir %s", dirname);
  }
  int count = 0;
  while((direntp = readdir(dir_ptr)) != NULL){
    //don't include '.' or '..' if -a option not indocated
    if((strcmp(direntp->d_name,".") != 0 && strcmp(direntp->d_name,"..") != 0) || (opt & A_OPT )){
      strcpy(dir_list[count],direntp->d_name);
      count++;
    }
  }
  closedir(dir_ptr);
  qsort(dir_list,count,MAX_LEN,order);                //sort dir_list
}

//check for -a and -l options and strips them out of the pointer array
char opt_check(int *count, char *arg[]){
  char opt = 0;
  int c = *count;
  while(c > 1){
    c--;
    if(strcasecmp("-l",arg[c]) == 0){                 //check for -l option
      opt |= L_OPT;
      strip(c,*count,arg);                            //remove -l from the arg list
      *count = *count - 1;
    }
    else if(strcasecmp("-a",arg[c]) == 0) {          //check for -a option
      opt |= A_OPT;
      strip(c,*count,arg);                          //remove -a from the arg list
      *count = *count - 1;
    }
  }
  return opt;
}

//removes intex from the char *[]
void strip(int index,int length, char *arg[]){
  int i;
  for(i=index; i < length; i++){
    if(i < length -1){
      strcpy(arg[i],arg[i+1]);
    }
    else{
      arg[i] = 0;
    }
  }
}

//comparator for qsort
int order(const void *str1, const void *str2){
  return strcasecmp((char *)str1,(char *)str2);
}

//convert a stat mode number into a string
void mode_to_letters(int mode, char str[]){
  strcpy(str,"----------");
  if(S_ISDIR(mode)) str[0] = 'd';
  if(S_ISCHR(mode)) str[0] = 'c';
  if(S_ISBLK(mode)) str[0] = 'b';

  if(mode & S_IRUSR) str[1] = 'r';
  if(mode & S_IWUSR) str[2] = 'w';
  if(mode & S_IXUSR) str[3] = 'x';

  if(mode & S_IRGRP) str[4] = 'r';
  if(mode & S_IWGRP) str[5] = 'w';
  if(mode & S_IXGRP) str[6] = 'x';

  if(mode & S_IROTH) str[7] = 'r';
  if(mode & S_IWOTH) str[8] = 'w';
  if(mode & S_IXOTH) str[9] = 'x';
}

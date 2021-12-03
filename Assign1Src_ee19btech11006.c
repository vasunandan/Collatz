#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <wait.h>

int collatz(int num){                   // collatz function to generated the collatz sequence
    while(num!=1){
        printf("%d ",num);
        if(num%2==0){                   // if num is even then the next no. id num/2
            num = num/2;
        }
        else{                           // if num is odd the num =3*num+1
            num = 3*num +1;
        }
    }
    printf("%d\n",num);                 // print 1
    return 0;                           // end of the function
}

int main(){
    int num = 0;
    while(num<=0){                      // while loop continues until a positive number is entered
        printf("Enter a postive no : ");
        scanf("%d",&num);
    }
    pid_t pid = fork();
    if(pid<0){                          // if pid<0 then fork failed
        fprintf(stderr,"Fork Failed");
        return 1;
    }
    else if(pid==0){                    // child process
        printf("child executing\n");
        collatz(num);                   // generating collatz sequence

    }
    else{                               // parent process
        printf("Parent executing\n");
        wait(NULL);                     // wait untill all child process completed.
        printf("parent and child executed\n");    // parent and child executed
    }
    return 0;

}
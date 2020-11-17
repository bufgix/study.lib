//ogrno:[181213044]
//ad:[Omer Faruk Oruc]

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    int proc_count = atoi(argv[1]);
    pid_t PIDS[proc_count];
    int child_status;
    int error = 0;

    for (int i = 0; i < proc_count; i++)
    {
        if ((PIDS[i] = fork()) == 0) // child
        {
            srand(time(NULL) ^ getpid());
            printf("%d\n", rand() % 100);
            exit(100 + i);
        }
        else
        { // parent
            waitpid(PIDS[i], &child_status, 0);
            if (!WIFEXITED(child_status))
            {
                error = 1;
            }
        }
    }
    if (!error)
    {
        printf("tamamlandı...\n");
        sleep(2);
    }

    return 0;
}

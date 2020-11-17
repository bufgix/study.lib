//ogrno:[181213044]
//ad:[Omer Faruk Oruc]

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <string.h>

int childTerminated = 0;
int current_player = 1;
int min = 0;
int max = 99;

int opponent()
{
    if (current_player == 1)
    {
        return 2;
    }
    return 1;
}

void alarmCallbak(int signum)
{
    printf("Kaybetti %d. oyuncu kazandı\n", opponent());
    exit(EXIT_SUCCESS);
}

void sig_handler(int singnum)
{
    childTerminated = 1;
}

int main(int argc, char const *argv[])
{
    int A = atoi(argv[1]);
    int B = atoi(argv[2]);

    FILE *fp;
    fp = fopen("oyun_181213044.txt", "w");

    pid_t pid;
    struct sigaction sa;
    sa.sa_handler = sig_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGCHLD, &sa, NULL);

    pid = fork();
    if (pid == 0) // Child proccess for game loop
    {

        signal(SIGALRM, alarmCallbak);
        srand(time(NULL));

        int rdeger = rand() % 100;
        int c;
        struct timespec begin;
        struct timespec end;

        fprintf(fp, "rdeger %d\nA: %d, B: %d\n", rdeger, A, B);

        for (int i = 0;; i++)
        {
            alarm(A);
            clock_gettime(CLOCK_MONOTONIC, &begin);
            printf("Oyuncu %d [%d-%d] arası bir sayı girsin: \n", current_player, min, max);
            scanf("%d", &c);
            clock_gettime(CLOCK_MONOTONIC, &end);
            double diff;
            diff = (end.tv_sec - begin.tv_sec) * 1e9;
            diff = (diff + (end.tv_nsec - begin.tv_nsec)) * 1e-9;
            fprintf(fp, "oyuncu %d  Geçen süre: %.2f saniye\n", current_player, diff);
            fprintf(fp, "oyuncu %d tahmini: %d\n", current_player, c);

            if (c > max || c < min)
            {
                printf("Aralık disi. Oyuncu %d Kaybetti\n.", current_player);
                fprintf(fp, "Aralık disi. Oyuncu %d Kaybetti\n", current_player);
                fprintf(fp, "kazanan oyuncu  %d\n.", opponent());
                exit(EXIT_SUCCESS);
            }
            if (c == rdeger)
            {
                printf("Doğru. Oyuncu %d Kaybetti\n.", current_player);
                fprintf(fp, "Doğru. kazanan oyuncu %d\n", opponent());

                exit(EXIT_SUCCESS);
            }
            printf("Yanlış. Geçen süre: %.2f saniye\n", diff);
            if (c < rdeger)
                min = c;
            else
                max = c;

            current_player = opponent();
        }
    }
    else
    { // parent proccess
        struct timespec begin;
        struct timespec end;
        clock_gettime(CLOCK_MONOTONIC, &begin);

        while (1)
        {
            clock_gettime(CLOCK_MONOTONIC, &end);
            double diff;
            diff = (end.tv_sec - begin.tv_sec) * 1e9;
            diff = (diff + (end.tv_nsec - begin.tv_nsec)) * 1e-9;
            if ((int)diff > B)
            {
                kill(pid, SIGKILL);
                printf("Kazanan yok\n");
                fprintf(fp, "Kazanan yok\n");
                fprintf(fp, "Toplam sure %.1f", diff);
                break;
            }

            if (childTerminated)
            {
                fprintf(fp, "Toplam sure %.1f", diff);
                fclose(fp);
                exit(EXIT_SUCCESS);
            }
        }
    }
    fclose(fp);
    return 0;
}

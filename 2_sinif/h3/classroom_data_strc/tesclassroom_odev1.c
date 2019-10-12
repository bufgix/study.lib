#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>

const char *FILENAME = "2_sinif\\h3\\classroom_data_strc\\data.txt";

/* 
-----BEGIN PGP PUBLIC KEY BLOCK-----

mQENBF2grVMBCADUxATaohljIX3S+n4lrS94E5NJ7WphV2Dux+x/uoSizUemgGzs
p3lDil8B5odr63SKRZfXzntyUc9uoex8BTlJpcv/IjrUxW0ud4vyenYolFkJUPAx
JiJcJ2YgutQDnZu97B67ajQdkRo1ff+pfbvgvccRFwCtNGQwWgn4P/VoiTXnAnqm
rcrjCl1cdZJPg7X1+dW9YdA1sBRr08PAp9fQ1kVXaWYFa5PtXsJG5f0ihU2JtRva
AUmGtHzkY8oSXbkMzArz462r3tk1JX/YfSLd92aC/IjL6Om9keG3hKUVi60NpjQw
nQeyRDRlm9dAD/o7cmkD4ow+jSwlGzxns0gTABEBAAG0J8OWbWVyIEZhcnVrIE9y
dcOnIDxvb3J1YzQ3MUB5YW5kZXguY29tPokBVAQTAQgAPhYhBJZIplY43wCtO5+c
ASz2ddT+8iyuBQJdoK1TAhsDBQkDwmcABQsJCAcCBhUKCQgLAgQWAgMBAh4BAheA
AAoJECz2ddT+8iyuAx0H/RMoiEfyaWVeqbousmHVB01ZS2eIqsQEDMjEQWLl96hA
6hpyAHbidIybnZ5y/SmbFZUiSFbWeadF8IzJ+RN/u11qzh8NKXKH3Rr60xA2izZA
+HcDSsECd+/T77rFnwtgG2RjKOpaZEWQ+35oMku5SjxAgvs80sExmggENZlH43h7
P9ZQTgkXd+QZIEQMDIRoboguZmCvFGNPodZR0Tt8XWOt8wFKTcMfpsZeW2X+pXCZ
QucKZUwGc2J6fFNkAV1ICQOUJH9jGShM2BEln3hW2RKM6eDXt9nrkJz0gLqXMeKT
Opdf2/uTnx+gxJmpKvdyJCc5d5efoiEm4UbB9Nfs42C5AQ0EXaCtUwEIALM4DuJ/
3pQ8YjDFR/rdf1Dfp3e/5Ic1ItY6CG2AknZPZu+RXBCRkhyjWQbrQ2I0RjA44/+l
47RGzxjHYDhThvwDGdNUNJYpgZaPlNLXsdoxQLjtYxQC43vWL5pfxa5+MadYV0+8
k10So7ExZ9A2B5mqdGqaNay7o3lv99OXShxi/d0QoAjJDBalCQrNoi5fes0p8/ar
M1oYrK0SlTV2z6Lm82NbcYqU9zfWlFURaGFGMt4OmEmLJQd8LJrckUf/bz7C3r0q
oOtFnEwb1TPAIWyJYm5s5RImSatekXn8nxlXc3jn0VM0MRApuftpT9hFS1QDBk6b
Fj+rKxRrnhqWpn8AEQEAAYkBPAQYAQgAJhYhBJZIplY43wCtO5+cASz2ddT+8iyu
BQJdoK1TAhsMBQkDwmcAAAoJECz2ddT+8iyun1QIALuUjaJDdl1z3nEQzusYV06D
3DLfEn9b5iXdNvXSeRh1VIXparX3oGA8bylHttdYJGbjX0jSRFRs+q2iXgz3BucR
PUarecNc/twxNOFEcmeZU7drLZL49/knodzAUYuMREFMiHlKyIBeJowMFlBd1/k/
6orJhQ12fh9sEIH8kjWcU993ctFa2EmQ7swN+rFJNVB3sLAkXw2BTOJXEJ5zoZLF
5rhUkgmNf/uVysYbC7mJvvmPsAv007YAvbOiK00nKLNbMo6w7Xi96OLVKctr23cy
6ETwlGkrtwY52josGBvdwbd1B7mn8Fnd0iY1sDGt1wfrFlrGM1uK3ZVYNsh/ODM=
=zmbe
-----END PGP PUBLIC KEY BLOCK----- 


Yukardaki anahtar ooruc471@yandex.com - Ömer "Bufgix" Faruk Oruç
kayıtlı olup kontrol amaçlıdır.


*/
typedef struct Node
{
    Node *next;
    char letter;
    int freq;
} Node;

// Fonksiyon imzaları

// Malloc ile struct için yer açar
Node *initNode();
// Malloc ile yer açıp içini paramterelere göre doldurur
Node *registerNode(const char letter, int freq);
// Yeni harf ataması yapar
void setLetter(Node *node, const char letter);
// Yeni frekans ataması yapar
void setFreq(Node *node, int freq);
// Harf liste içinde mi?
int includeNode(Node *head, const char letter);
// Node head içinde var mı?
int include(Node *head, Node *node);
// target a göre uygun node yi döndürür.
Node *findNode(Node *head, const char target);
// listeye sıralı şekilde yeni eleman ekler
void *pushNode(Node *head, Node *node);
// listede eleman cıkarır
Node *deleteNode(Node *head, const char target);
// listeyi sıralar
void sortNode(Node *head);
// verilen dosya isminden verileri okur ve bagli listeye donusturur
Node *readFromFile(const char *fname);
// listeyi yazdirir
void printNode(Node *head);
// Frekanslarına göre listedeki elemanları yazdirir
void printAsFreq(Node *head);
// Rastgele kucuk karakter üretir
char getRandomLetter();
// rastgele frekans degerleri uretir
int getRandomFreq();
// Verilen string de harflerin frekansını bulur
int findFreq(char *string, char target);
// Sorunun A bölümünü calistiir
void RunPartA();
// Sorunun B bölümünü calistiir
void RunPartB();
// Sorunun C bölümünü calistiir
void RunPartC();

int main(int argc, char const *argv[])
{
    while (1)
    {
        fseek(stdin, 0, SEEK_END);
        char ch;
        printf("a - A bolumu\nb - B bolumu\nc - C bolumu\nq - Cik\n\n->");
        scanf("%c", &ch);
        switch (ch)
        {
        case 'a':
            RunPartA();
            break;
        case 'b':
            RunPartB();
            break;
        case 'c':
            RunPartC();
            break;
        case 'q':
            return 0;
            break;
        default:
            break;
        }
    }
    system("PAUSE");
    return 0;
}

void RunPartA()
{
    Node *head = readFromFile(FILENAME);
    printf("%s dosyasi okundu...\n", FILENAME);
    printNode(head);

    char ch;
    while (1)
    {
        fseek(stdin, 0, SEEK_END);
        printf("\ne - Ekle\ns - sil\nl - listele\ng- geri\n\n-> ");
        scanf("%c", &ch);
        Node *t;
        char letter;
        switch (ch)
        {
        case 'e':
            getchar();
            int freq;
            printf("\nHARF girin: ");
            scanf("%c", &letter);
            printf("%c harfinini frekansini girin: ", letter);
            scanf("%d", &freq);
            pushNode(head, registerNode(letter, freq));
            break;
        case 's':
            getchar();
            printf("Silinecek harf: ");
            scanf("%c", &letter);

            t = deleteNode(head, letter);
            if (t != NULL)
                head = t;

            else
                printf("Listede %c harfi yok", letter);
            break;
        case 'l':
            printf("\n");
            printNode(head);

            break;
        case 'g':
        default:
            return;
            break;
        }
    }
}

void RunPartB()
{
    int n;
    printf("Kac harf istiyorsun: ");
    scanf("%d", &n);
    srand(time(NULL));

    Node *head = registerNode(getRandomLetter(), getRandomFreq());

    printf("%d\n", n);
    for (int i = 0; i < n - 1; i++)
    {
        pushNode(head, registerNode(getRandomLetter(), getRandomFreq()));
    }

    printNode(head);
    printf("Frekanslara gore harf dagilimi: ");
    printAsFreq(head);
}

void RunPartC()
{
    srand(time(NULL));

    Node *head = registerNode(getRandomLetter(), getRandomFreq());

    for (int i = 0; i < 4; i++)
    {
        pushNode(head, registerNode(getRandomLetter(), getRandomFreq()));
    }
    printNode(head);
    printf("Olabilecek frekans stringi  ");
    printAsFreq(head);
    char string[100];
    printf("Karakter dizisi girin: ");
    scanf("%s", string);

    char *tempt = string;
    int status = 1;
    char tChar;
    while (*tempt != '\0')
    {
        if (include(head, registerNode(*tempt, findFreq(string, *tempt))) == 0)
        {
            status = 0;
            tChar = *tempt;
        }
        *tempt++;
    }
    if (status == 0) // Eğer frekansı uymayan bir char varsa
    {
        printf("Bu veri uygun degildir. Cunku %c harfinin frekansi %d .Kullanici ise %c harfini %d kez girmistir.\n",
               tChar,
               findNode(head, tChar)->freq,
               tChar,
               findFreq(string, tChar));
    }
    else
    {
        printf("Bu veri uygundur\n");
    }
}

Node *initNode()
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    return newNode;
}

Node *registerNode(const char letter, int freq)
{
    Node *node = initNode();
    node->letter = letter;
    node->freq = freq;

    return node;
}

void setLetter(Node *node, const char letter)
{
    node->letter = letter;
}

void setFreq(Node *node, int freq)
{
    node->freq = freq;
}

int includeNode(Node *head, const char letter)
{
    while (head != NULL)
    {
        if (head->letter == letter)
            return 1;
        head = head->next;
    }
    return 0;
}

int include(Node *head, Node *node)
{
    while (head != NULL)
    {
        if (node->letter == head->letter && node->freq == head->freq)
        {
            return 1;
        }
        head = head->next;
    }
    return 0;
}

void *pushNode(Node *head, Node *node)
{
    if (includeNode(head, node->letter))
    {
        printf("[UYARI] %c listede daha once var oldugundan eklenmedi\n", node->letter);
        return NULL;
    }
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = node;
    sortNode(head);
}

void sortNode(Node *head)
{
    Node *i = head;
    Node *j;

    for (; i->next != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->letter > j->letter)
            {
                int t = i->letter;
                i->letter = j->letter;
                j->letter = t;
            }
        }
    }
}

Node *deleteNode(Node *head, const char target)
{
    /*
        @params: head (Node*) -> list in en baş işaretcisi
        @param: target (char) -> silinecek deger

        @return: (Node*) -> Yeni headi dondurur

        Eger taget list içinde yoksa NULL dondurecektir
    */
    Node *prev = head;
    Node *cursor = head->next;

    // Eger silinecek karakter head ise
    if (prev->letter == target)
    {
        Node *t = prev->next;
        free(prev);
        return t;
    }

    while (cursor != NULL)
    {
        if (cursor->letter == target)
        {
            Node *t = cursor->next;
            prev->next = t;
            free(cursor);
            return head;
        }
        prev = prev->next;
        cursor = cursor->next;
    }
    return NULL;
}

Node *readFromFile(const char *fname)
{
    FILE *fp = fopen(fname, "r");
    char ch;
    Node *head = initNode();
    fscanf(fp, "%c,", &ch);
    setLetter(head, ch);

    // Harfleri yerleştir
    do
    {
        Node *node = initNode();
        fscanf(fp, "%c,", &ch);
        if (ch == '\n') // ikinci satıra gelince döngüyü kır
            break;
        setLetter(node, ch);
        pushNode(head, node);
    } while (!feof(fp));
    fclose(fp);

    // Freakans bilgisi
    fp = fopen(fname, "r");
    fscanf(fp, "%*[^\n]\n", NULL); // Ilk satırı geç
    Node *t = head;
    int freq;
    do
    {
        fscanf(fp, "%d,", &freq);
        if (t != NULL)
        {
            setFreq(t, freq);
            t = t->next;
        }

    } while (!feof(fp));

    fclose(fp);

    return head;
}

char getRandomLetter()
{
    return rand() % (123 - 97) + 97;
}

int getRandomFreq()
{
    return rand() % (10 - 1) + 1;
}

Node *findNode(Node *head, const char target)
{
    while (head != NULL)
    {
        if (head->letter == target)
            return head;
        head = head->next;
    }
    return NULL;
}

int findFreq(char *string, char target)
{
    int n = 0;
    while (*string != '\0')
    {
        if (*string == target)
        {
            n++;
        }
        *string++;
    }
    return n;
}

void printAsFreq(Node *head)
{
    while (head != NULL)
    {
        for (int i = 0; i < head->freq; i++)
        {
            printf("%c", head->letter);
        }
        head = head->next;
    }
    printf("\n");
}

void printNode(Node *head)
{
    while (head != NULL)
    {
        printf("==============\n");
        printf("Harf: %c\n", head->letter);
        printf("Frekans: %d\n", head->freq);
        head = head->next;
    }
}

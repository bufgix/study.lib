#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

const char *FILENAME = "2_sinif\\h3\\classroom_data_strc\\data.txt";

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
// kucuk karakter üretir
char getRandomLetter();
// rastgele frekans degerleri uretir
int getRandomFreq();
// Verilen string de harflerin frekansını bukur
int findFreq(char *string, char target);
// Sorunun A sikkini calistiir
void RunPartA();
// Sorunun B sikkini calistiir
void RunPartB();
// Sorunun C sikkini calistiir
void RunPartC();

int main(int argc, char const *argv[])
{
    RunPartC();
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
    printAsFreq(head);
    char string[100];
    printf("Karakted dizisi girin: ");
    scanf("%s", string);

    // TODO: C bölümü yapılacak
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

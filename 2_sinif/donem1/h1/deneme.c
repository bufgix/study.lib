#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Bu dosya ödev değildir
 * "struct içinde nasıl fonksiyon yazılır?"
 * örneğidir.
*/


// Person struct
struct Person
{
    Person* self;
    char name[200];
    int age;
    
    void (*setAge)(Person*, int);
    void (*setName)(Person*, char*);
    void (*printPerson)(Person*);
    void (*destroy)(Person *);

};
typedef struct Person Person;

// Function Declarations
Person* initPerson(char* name, int);
void _setAge(Person*, int);
void _setName(Person*, char*);
void _printPerson(Person*);
void _destroy(Person*);

Person* initPerson(
    char *name,
    int age
)
{
    Person* newp = (Person*)malloc(sizeof(Person) * 1);
    strcpy(newp->name, name);
    newp->age = age;
    newp->setAge = &_setAge;
    newp->printPerson = &_printPerson;
    newp->setName = &_setName;
    newp->destroy = &_destroy;
    newp->self = newp;
}

void _setAge(Person* p, int age) {
    p->age = age;
}

void _printPerson(Person* p)
{
    printf("Isim: %s\nYas: %d\n\n", p->name, p->age);
}
void _setName(Person* p, char* name)
{
    strcpy(p->name, name);
}

void _destroy(Person* p) 
{
    free(p);
}

int main(int argc, char const *argv[])
{

    Person* p = initPerson((char*)"Omer", 20);
    p->printPerson(p->self);
    p->setAge(p->self, 33);
    p->printPerson(p->self);
    p->setName(p->self, (char*) "Ahmet");
    p->printPerson(p->self);
    p->destroy(p->self);

    getch();
    return 0;
}

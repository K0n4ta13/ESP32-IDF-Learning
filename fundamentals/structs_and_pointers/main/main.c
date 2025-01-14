#include <stdio.h>
#include <string.h>

typedef struct {
    char first_name[20];
    char last_name[20];
    int age;
} Person;

void update_person(Person *person) {
    strcpy(person->first_name, "John");
    strcpy(person->last_name, "Doe");
    person->age = 18;
}

void exclam_it(char *phrase) {
    printf("len: %d size: %d\n", strlen(phrase), sizeof(phrase));
    strcat(phrase, "!");
    printf("len: %d size: %d\n", strlen(phrase), sizeof(phrase));
}

void connect_and_get_info() {
    uint8_t *data_retrieved = malloc(sizeof(uint8_t) * 1024);

    printf("len: %d size: %p\n", sizeof(data_retrieved), data_retrieved);

    free(data_retrieved);
}

uint32_t i = 1;

void app_main(void)
{
    Person person;
    char *phrase = { "Hello, World" };

    update_person(&person);
    exclam_it(phrase);

    connect_and_get_info();

    printf("person: %s %s is %d years old\n", person.first_name, person.last_name, person.age);
    printf("%s\n", phrase);
}


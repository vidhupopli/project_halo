#include <stdio.h>
#include <stdbool.h>

// If you want to avoid using they keyword struct at the point of usage then you need to create type alias.
typedef struct
{
    char *name;
    bool isEnrolled;
} Student;

// struct Student
// {
//     char *name;
//     bool isEnrolled;
// };

int main()
{
    Student s1 = {"Vidhu", true}; // This is not allowed if there is no type alias.
    // struct Student s1 = {"Vidhu", true}; // This is the syntax when there is no type alias.

    printf("Jai Gurudev\n");

    printf("%s | %d\n", s1.name, s1.isEnrolled);
    return 0;
}
#include <stdio.h>
struct student {
    char name[20];
    char roll[12];
    int age;
};
int main() {
    struct student s1;
    scanf("%s",s1.name);
    scanf("%s",s1.roll);
    scanf("%d",&s1.age);
    printf("name\troll\tage\n");
    printf("%s\t    %s\t   %d",s1.name,s1.roll,s1.age);
    
}
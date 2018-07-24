#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/*************************
*Name:Student Manegement *
*Auth:Mr.Yin             *
*CraTime                 *
*************************/

//学生个人信息表
typedef struct student
{
    unsigned id;
    char name[20];
    char sex;
    unsigned short age;
    unsigned grade_class;
} stu;

stu *addStu(unsigned id, const char *name, char sex, unsigned age, unsigned grade_class)
{
    stu *stp_add = NULL;
    stp_add = (stu *)malloc(sizeof(stu)); //申请动态内存，强制转为stu结构体类型
    //判断是否成功
    if (stp_add == NULL)
    {
        printf("Failed to add record");
        return NULL;
    }
    stp_add->id = id;
    strcpy(stp_add->name, name);
    stp_add->sex = sex;
    stp_add->age = age;
    stp_add->grade_class = grade_class;
    printf("Added successfully!");
    return stp_add;
}

void mdfStu(stu *stp_mdf, int num_filed)
{
    system("clear");
    printf("Please enter the new value:\n");
    char name_new[20];
    char sex_new;
    unsigned class_new;
    unsigned age_new;
    switch (num_filed)
    {
        case 1:
            scanf("%s", &name_new);
            strcpy(stp_mdf->name, name_new);
            break;
        case 2:
            scanf("c", &sex_new);
            stp_mdf->sex = sex_new;
            break;
        case 3:
            scanf("%d", &age_new);
            stp_mdf->age = age_new;
            break;
        case 4:
            scanf("%d", &class_new);
            stp_mdf->grade_class = class_new;
            break;
        default:
            break;
    }
}

void delStu(stu *stp_del)
{
    free(stp_del);
    stp_del = NULL;
    if (stp_del == NULL)
        printf("Deleted successfully!");
}

int main(int argc, char const *argv[])
{
    stu *arr_stp[100]; //定义一个结构体指针数组存放多张学生个人信息表
    int num;
    unsigned id, age, grade_class;
    char name[20];
    char sex;

    while (1)
    {
        system("clear");
        printf("Welcome to the student management system.\n");
        printf("Please enter a num to select an action:\n0 quit\n1 add\n2 delete\n3 modify\n4 search\n");
        scanf("%d", &num);
        if (num == 0)
            break;
        else if (num == 1)//增
        {
            system("clear");
            printf("Please enter id name sex age class:\n");
            scanf("%u %s %c %u %u", &id, &name, &sex, &age, &grade_class);
            arr_stp[id - 1] = addStu(id, name, sex, age, grade_class);
            sleep(1);
        }
        else if (num == 2)//删
        {
            system("clear");
            printf("Please enter the id to delete:\n");
            scanf("%d", &id);
            delStu(arr_stp[id - 1]);
            sleep(1);
        }
        else if (num == 3)//改
        {
            system("clear");
            printf("Please enter the id to modify:\n");
            scanf("%d", &id);
            system("clear");
            printf("Please enter a num to select an filed:\n1 name\n2 sex\n3 age\n4 grade_class\n");
            scanf("%d", &num);
            mdfStu(arr_stp[id - 1], num);
        }
        else if (num == 4)//查
        {
            system("clear");
            printf("Please enter the id to search:\n");
            scanf("%d", &id);
            printf("id\tname\tsex\tage\tgrade\n");
            printf("%u\t%s\t%c\t%u\t%u\n",
                   arr_stp[id - 1]->id, arr_stp[id - 1]->name, arr_stp[id - 1]->sex, arr_stp[id - 1]->age, arr_stp[id - 1]->grade_class);
            sleep(3);
        }
    }
    return 0;
}

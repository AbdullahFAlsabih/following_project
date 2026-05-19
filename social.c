#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct follow_node follow_node;
typedef struct user user;

struct user
{
    int user_id;
    char user_name[50];
    int user_age;
    struct follow_node *following;
};

struct follow_node
{

    user *follow_user;
    follow_node *next;
};

void follow_user(struct user *follower, struct user *followed)
{
    struct follow_node *new_node = malloc(sizeof(struct follow_node));
    new_node->follow_user = followed;
    new_node->next = follower->following;
    follower->following = new_node;
}

void print_following(struct user *current_user)
{
    printf("%s is folloing:\n", current_user->user_name);
    struct follow_node *temp = current_user->following;
    while (temp != NULL)
    {
        printf("- %s\n,", temp->follow_user->user_name);
        temp = temp->next;
    }
}
void print_table()
{
    printf("\n");
    printf("1 follows 2\n");
    printf("1 follows 3\n");
    printf("2 follows 1\n");
    printf("2 follows 3\n");
    printf("3 follows 1\n");
    printf("3 follows 2\n");
}

int main()
{

    struct user Abdullah;
    Abdullah.user_id = 1;
    strcpy(Abdullah.user_name, "AbdullahF");
    Abdullah.user_age = 25;
    Abdullah.following = NULL;

    struct user Ali;
    Ali.user_id = 2;
    strcpy(Ali.user_name, "Ali");
    Ali.user_age = 22;
    Ali.following = NULL;

    struct user Ahmed;
    Ahmed.user_id = 3;
    strcpy(Ahmed.user_name, "Ahmed");
    Ahmed.user_age = 24;
    Ahmed.following = NULL;

    follow_user(&Abdullah, &Ali);
    follow_user(&Abdullah, &Ahmed);
    follow_user(&Ahmed, &Ali);
    follow_user(&Ahmed, &Abdullah);
    follow_user(&Ali, &Ahmed);
    follow_user(&Ali, &Abdullah);

  
    print_table();

    return 0;
}
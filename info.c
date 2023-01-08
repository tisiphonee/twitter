#include "info.h"
void info(user *head)
{
    user *current_user = head;
    while (current_user->next != NULL)
    {
        current_user = current_user->next;
        if (current_user->isLogedin == TRUE) // Switch To The Logged in User
        {
            post *current_post = current_user->post->next;
            if (current_post == NULL)
            {
                printf("*+*+*+*+*+*+**+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*\n");
                printf("User : %s\n", current_user->username);
                printf("<<NO POST FOUND>>\n");
                printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
            }
            while (current_post != NULL)
            {
                printf("*+*+*+*+*+*+**+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*\n");
                printf("User : %s\n", current_user->username);
                printf("Post-ID : %ld\n", current_post->post_id);
                printf("Likes : %d\n", current_post->num_like);
                printf("Message : %s\n", current_post->message);
                printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
                current_post = current_post->next;
            }
        }
    }
}
int find_user(user *head)
{
    char *username;
    char tempChar;
    tempChar = getchar();
    if (check_spaces_endl(tempChar) == TRUE)
    {
        return FAILED;
    }
    username = dynamic_memory_alloc(username, tempChar, REGISTER_MODE);
    user *current_user = head;
    while (current_user->next != NULL) // Check when the username matches
    {
        current_user = current_user->next;
        if (strcmp(current_user->username, username) == 0)
        {
            post *current_post = current_user->post->next;
            if (current_post == NULL)
            {
                printf("*+*+*+*+*+*+**+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*\n");
                printf("User : %s\n", current_user->username);
                printf("<<NO POST FOUND>>\n");
                printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
            }
            printf("<<Search Completed>>\n");
            while (current_post != NULL)
            {
                printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
                printf("User : %s\n", current_user->username);
                printf("Post-ID : %ld\n", current_post->post_id);
                printf("Likes : %d\n", current_post->num_like);
                printf("Message : %s\n", current_post->message);
                printf("*+*+*+*+*+*+**+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*\n");
                current_post = current_post->next;
            }
            // No longer Pointer is needed
            free(username);
            return DONE;
        }
    }
    printf("make sure user exist!\n");
    return FAILED;
}

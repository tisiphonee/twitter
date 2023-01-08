#include "register.h"
int singup(user *head, int numUsers, int lastStatus)
{
    char tempChar;
    tempChar = getchar();
    /* Add User at the end*/
    user *new_user = (user *)malloc(sizeof(user)), *backupNext;
    user *current_user = head;
    while (current_user->next != NULL)
        current_user = current_user->next;
    backupNext = current_user->next;
    current_user->next = new_user;

    // Check if the next Input is correct or not

    if (check_spaces_endl(tempChar) == TRUE)
    {
        free(new_user);
        current_user->next = backupNext;
        return FAILED;
    }
    new_user->username = dynamic_memory_alloc(new_user->username, tempChar, REGISTER_MODE);
    // check if there is antoher user with same name

    if (numUsers > 0) // at least  one user must be to check the same
    {
        user *tempUser = head;
        while (tempUser->next != new_user)
        {
            tempUser = tempUser->next;

            if (strcmp(tempUser->username, new_user->username) == 0 && lastStatus != FALSE)
            {
                printf("This User is Already exist please try to login it!\n");
                free(new_user);
                current_user->next = backupNext;
                return FAILED;
            }
        }
    }
    tempChar = getchar(); // clear the sapce between

    if (check_spaces_endl(tempChar) == TRUE)
    {
        free(new_user);
        current_user->next = backupNext;
        return FAILED;
    }
    new_user->password = dynamic_memory_alloc(new_user->password, tempChar, REGISTER_MODE);
    new_user->num_post = 0;
    new_user->total_num_post = 0;
    new_user->next = NULL;
    // each user neeed  a pointer to the head of posts
    post *post_head = (post *)malloc(sizeof(post));
    new_user->post = post_head;
    new_user->post->next = NULL;
    return DONE;
}
int login(user *head)
{
    char *username, *password;
    char tempChar;
    tempChar = getchar();
    if (check_spaces_endl(tempChar) == TRUE)
    {
        return FAILED;
    }
    username = dynamic_memory_alloc(username, tempChar, REGISTER_MODE);
    tempChar = getchar();
    if (check_spaces_endl(tempChar) == TRUE)
    {
        return FAILED;
    }
    password = dynamic_memory_alloc(password, tempChar, REGISTER_MODE);
    user *tempUser = head;
    while (tempUser->next != NULL) // Check when the user name and password matches
    {
        tempUser = tempUser->next;

        if (strcmp(tempUser->username, username) == 0 && strcmp(tempUser->password, password) == 0)
        {
            printf("You Just Logged in !!\n");
            // No longer Pointer is needed
            free(username);
            free(password);
            tempUser->isLogedin = TRUE;
            return DONE;
        }
    }
    printf("make sure user exist!\n");
    return FAILED;
}
int logout(user *head)
{

    user *current_user = head;
    while (current_user->next != NULL)
    {
        current_user = current_user->next;
        if (current_user->isLogedin == TRUE)
        {
            current_user->isLogedin = FALSE;
            printf("You Just Logged Out!\n");
            return DONE;
        }
    }
    return FAILED;
}
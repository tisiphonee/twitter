#include "main.h"

int main()
{
    user *head = (user *)malloc(sizeof(user));
    post *post_head = (post *)malloc(sizeof(post));
    liked_user_t *liked_users_head = (liked_user_t *)malloc(sizeof(liked_user_t));
    head->post = post_head;
    head->post->likeduser = liked_users_head;
    head->next = NULL;
    head->post->next = NULL;
    head->post->likeduser->next = NULL;

    int nUsers = 0;
    char commands[NUMCOMMAND][COMMAND_MAXSIZE] = {"signup", "login", "logout", "post", "like", "delete", "info", "find_user"};
    char chararray[COMMAND_MAXSIZE];
    int isAdded = FALSE;
    int is_logged_in = FALSE;

    while (TRUE)
    {
        printf("\nPlease Enter Your Command :");
        int isSame = FALSE;
        while (isSame != SAME) // Get User Input until all the inputs are correct
        {
            // clearing current_user states
            int commandIndex = 0;
            memset(chararray, 0, sizeof(chararray));
            char tempChar = 0;
            int index = 0;
            size_t sLneght = 0;
            fflush(stdin);
            tempChar = getchar();
            if (check_spaces_endl(tempChar) == TRUE)
            {
                break;
            }
            while (tempChar != ' ' && tempChar != '\n') // get command from user input and switch based on that
            {
                chararray[index] = tempChar;
                tempChar = getchar();
                index++;
            }
            sLneght = strlen(chararray);
            for (commandIndex; commandIndex < NUMCOMMAND; commandIndex++)
            {
                isSame = strncmp(chararray, commands[commandIndex], sLneght);
                if (isSame == 0)
                    break;
            }
            if (isSame != 0)
            {
                printf("Error : please check your spaces and command!\n");
                break;
            }
            // if after command was no entry except commands like info and logout
            if (commandIndex != LOGOUT && commandIndex != INFO)
            {
                if (tempChar == '\n')
                {
                    printf("Too few entry! please ensure that your command is correct \n");
                    break;
                }
            }

            if ((commandIndex != SIGNUP && commandIndex != LOGIN) && is_logged_in == FALSE)
            {
                printf("You must login first for these commands \n");
                break;
            }

            switch (commandIndex) // to call function of command base on commandIndex
            {
            case SIGNUP:

                isAdded = singup(head, nUsers, isAdded);
                if (isAdded == TRUE)
                {
                    printf("User Successfully Added!\n");
                    nUsers++;
                }

                break;
            case LOGIN:
                is_logged_in = login(head);
                break;
            case LOGOUT:
                is_logged_in = logout(head);
                break;
            case POST:
                send_post(head);
                break;
            case LIKE:
                like_post(head);
                break;
            case DELETE:
                delete_post(head);
                break;
            case INFO:
                info(head);
                break;
            case FIND:
                find_user(head);
                break;

            default:
                break;
            }
        }
        // Write the usernames and post etc. to the export file
        write_to_file(head);
    }
}

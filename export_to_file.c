#include "export_to_file.h"
void write_to_file(user *head)
{
    FILE *accountOut = fopen(ACC_FILE_ADDRESS, "w");
    FILE *postOut = fopen(POST_FILE_ADDRESS, "w");
    user *current_user = head;
    while (current_user->next != NULL)
    {
        current_user = current_user->next; // Write Accounts infos

        fprintf(accountOut, "%s %s %d\n", current_user->username, current_user->password, current_user->num_post);
        post *current_post = current_user->post->next;
        while (current_post != NULL) // Write Post infos
        {
            fprintf(postOut, "%s %s %d\n", current_post->message, current_user->username, current_post->num_like);
            current_post = current_post->next;
        }
    }
    fclose(accountOut);
    fclose(postOut);
}
#include "post.h"
int send_post(user *head)
{
    user *current_user = head;
    char tempChar;
    tempChar = getchar();
    if (check_spaces_endl(tempChar) == TRUE)
    {
        return FAILED;
    }
    while (current_user->next != NULL)
    {
        current_user = current_user->next;
        if (current_user->isLogedin == TRUE)
        {
            // Add Post At the end
            post *new_post = (post *)malloc(sizeof(post));
            post *current_post = current_user->post;
            liked_user_t *pLikedUser = (liked_user_t *)malloc(sizeof(liked_user_t));
            while (current_post->next != NULL)
                current_post = current_post->next;
            current_post->next = new_post;
            current_post = current_post->next;
            current_post->message = dynamic_memory_alloc(current_post->message, tempChar, TEXT_MODE);
            // generate the post id and set the like to 0 for like command
            current_post->num_like = 0;
            // set post id and update num of posts
            current_post->post_id = current_user->total_num_post;
            current_user->num_post += 1;
            current_user->total_num_post += 1;
            current_post->next = NULL;
            current_post->likeduser = pLikedUser;
            current_post->likeduser->next = NULL;
            printf("<< Post Added With Post ID : %ld >>\n", current_post->post_id);
            return DONE;
        }
    }
    printf("\n**Post Not Added**\n");
    return FAILED;
}
int like_post(user *head)
{
    char *username;
    char tempChar;
    size_t postid = 0;
    tempChar = getchar();
    if (check_spaces_endl(tempChar) == TRUE)
    {
        return FAILED;
    }
    username = dynamic_memory_alloc(username, tempChar, REGISTER_MODE);
    if (scanf("%ld", &postid) == 0)
    {
        printf("Cannot Read Any Post ID");
        return FAILED;
    }
    user *current_user = head;
    while (current_user->next != NULL) // Check when the user name  matches
    {
        current_user = current_user->next;
        if (strcmp(current_user->username, username) == 0) // is same with given user name?
        {
            post *current_post = current_user->post->next;
            while (current_post != NULL)
            {
                if (current_post->post_id == postid) // Check for the post with given post id
                {
                    // Check if the user is already liked this post
                    liked_user_t *check_like = current_post->likeduser->next;
                    while (check_like != NULL)
                    {
                        if (strcmp(check_like->username, current_user->username) == 0) // then user already liked
                        {
                            printf("You already liked this post!\n");
                            return FAILED;
                        }
                        check_like = check_like->next;
                    }
                    // post the like and add the name to the liked user list
                    liked_user_t *liked_user = current_post->likeduser;
                    liked_user_t *new_like = (liked_user_t *)malloc(sizeof(liked_user_t));
                    while (liked_user->next != NULL)
                        liked_user = liked_user->next;
                    liked_user->next = new_like;
                    liked_user = liked_user->next;
                    liked_user->next = NULL;
                    // copy the user name to the liked list
                    liked_user->username = malloc(sizeof(current_user->username));
                    strcpy((liked_user->username), (current_user->username));
                    current_post->num_like += 1;
                    printf("Post Liked!\n");
                    // No longer Pointer is needed
                    free(username);
                    return DONE;
                }
                current_post = current_post->next;
            }
        }
    }
    printf("Post or User Does not exist!\n");
    return FAILED;
}
int delete_post(user *head)
{

    size_t postid = 0;
    if (scanf("%ld", &postid) == 0)
    {
        printf("Cannot Read Any Post ID");
        return FAILED;
    }
    user *current_user = head;
    while (current_user->next != NULL)
    {
        current_user = current_user->next;
        if (current_user->isLogedin == TRUE) // Switch To The Logged in User
        {
            post *delete_post;
            post *prev = current_user->post;
            post *current_post = current_user->post->next;
            while (current_post != NULL)
            {

                if (current_post->post_id == postid) // Check for the post with given post id
                {
                    prev->next = current_post->next;
                    free(current_post);
                    current_user->num_post -= 1;

                    printf("<<Post with id:%ld Deleted>>\n", postid);
                    return DONE;
                }
                prev = current_post;
                current_post = current_post->next;
            }
        }
    }
    printf("Post  Does not exist!\n");
    return FAILED;
}
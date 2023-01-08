#ifndef STRUCT_HEADER
#define STRUCT_HEADER
typedef struct users user;
typedef struct posts post;
typedef struct username_liked liked_user_t;

struct username_liked
{
    char *username;
    liked_user_t *next;
};
struct posts
{
    int num_like;
    size_t post_id;
    char *message;
    liked_user_t *likeduser;
    post *next;
};
struct users
{
    char *username;
    char *password;
    int num_post;
    int total_num_post;
    post *post;
    user *next;
    int isLogedin;
};
#endif
#ifndef ESSENTIAL
#define ESSENTIAL
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "defs.h"
#endif
#include "memoryalloc.h"
int send_post(user *head);
int like_post(user *head);
int delete_post(user *head);
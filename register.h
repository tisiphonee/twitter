#ifndef ESSENTIAL
#define ESSENTIAL
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "defs.h"
#endif
#include "memoryalloc.h"
int singup(user *head, int numUsers, int lastStatus);
int login(user *head);
int logout(user *head);
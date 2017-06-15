#ifndef _ROOM_H
#define _ROOM_H

#include<stdbool.h>
#include"element.h"

struct room {
	char *name;
	char *image;
	char *description;
	int num_elements;
};

typedef struct room Room;

#endif




#ifndef _ELEMENT_H
#define _ELEMENT_H

#include<stdbool.h>
//#include "LocalizedString.h"


typedef struct element_status ElementStatus;
typedef enum element_flag ElementFlag;
typedef struct keyed_status KeyedStatus;
typedef struct element Element;

enum element_flag {
	carriable = 1,
	limited_uses = carriable << 1,
	reactable = carriable << 2,
	temporal = carriable << 3,
	container = carriable << 4,
	timed = carriable << 5
};

struct element_status {
	bool active;
	char *alias;
	char* description;
	char* short_desc;
	ElementFlag flags;
	int uses;
	int max_uses;
	KeyedStatus* reactions;
	ElementStatus* next_status;
};

struct keyed_status {
	char* key;
	char* transition_string;
	ElementStatus* status;
};

struct element {
	char* name;
	int num_status;
	ElementStatus* status;
};

#endif
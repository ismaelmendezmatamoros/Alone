#ifndef _LOCALIZED_STRING
#define _LOCALIZED_STRING

#include<string.h>
#include<stdlib.h>

struct localized_string_set {
	char* name;
	char* locale;
	char* str;
};

typedef struct localized_string LocalizedStringSet;


//LocalizedString* createLocalizedString(const char* locale, const char* str);

#endif
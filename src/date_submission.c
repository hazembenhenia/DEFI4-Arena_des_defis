#include <stdio.h>
#include <time.h>
#include "date_submission.h"

char* timing()
{
    time_t now = time(NULL);
    struct tm tm_now = *localtime(&now);

    static char s_now[20]; 

    strftime(s_now, sizeof s_now, "%d/%m/%Y %H:%M:%S", &tm_now);

    return s_now;
}

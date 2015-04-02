#ifdef STANDARD
/* STANDARD is defined, don't use any mysql functions */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifdef __WIN__
typedef unsigned __int64 ulonglong;	/* Microsofts 64 bit types */
typedef __int64 longlong;
#else
typedef unsigned long long ulonglong;
typedef long long longlong;
#endif /*__WIN__*/
#else
#include <my_global.h>
#include <my_sys.h>
#if defined(MYSQL_SERVER)
#include <m_string.h>		/* To get strmov() */
#else
/* when compiled as standalone */
#include <string.h>
#define strmov(a,b) stpcpy(a,b)
#define bzero(a,b) memset(a,0,b)
#endif
#endif
#include <mysql.h>
#include <ctype.h>

#ifdef _WIN32
/* inet_aton needs winsock library */
#pragma comment(lib, "ws2_32")
#endif

#ifdef HAVE_DLOPEN

#if !defined(HAVE_GETHOSTBYADDR_R) || !defined(HAVE_SOLARIS_STYLE_GETHOST)
static pthread_mutex_t LOCK_hostname;
#endif

#include <math.h>

my_bool convert_time_init(UDF_INIT* initid, UDF_ARGS* args, char* message);
char *convert_time(UDF_INIT *initid, UDF_ARGS *args, char *result,
	       unsigned long *length, char *is_null, char *error);

my_bool convert_time_init(UDF_INIT *initid, UDF_ARGS *args, char *message)
{
    if (args->arg_count != 1 || args->arg_type[0] != INT_RESULT)
    {
        strcpy(message, "Wrong arguments to convert_time(); Requires number of seconds as INT.");
    }
 
//    char *tmp = (char *) malloc((size_t) 255);
//    initid->ptr = tmp;
    initid->maybe_null = 1;
    initid->max_length= 255; 
    return 0;
}

char *convert_time(UDF_INIT *initid, UDF_ARGS *args, char *result,
	       unsigned long *length, char *is_null, char *error)
{
    longlong in_seconds = *((longlong*)(args->args[0]));
    int hours = in_seconds / 60 / 60;
    int minutes = in_seconds / 60 % 60;
    int seconds = in_seconds % 60 % 60;
    char tmp[255];


    if (args->args[0] == NULL) {
        result = NULL;
        *length = 0;
        *is_null = 1;
    }
    else
    {
        snprintf(tmp, 255, "%d Hours, %d Minutes, %d Seconds", hours, minutes, seconds);

        memcpy(result, tmp, strlen(tmp));
        *length = strlen(tmp);
    }

    return result; 
}


#endif

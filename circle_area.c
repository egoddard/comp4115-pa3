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

my_bool circle_area_init(UDF_INIT* initid, UDF_ARGS* args, char* message);
double circle_area(UDF_INIT* initid, UDF_ARGS* args, char* is_null, char *error);


my_bool circle_area_init(UDF_INIT *initid, UDF_ARGS *args, char *message)
{ 
    if (args->arg_count != 1)
    {
        strcpy(message, "circle_area() requires one argument.");
        return 1;
    }

    if (args->arg_type[0] == STRING_RESULT)
    {
        strcpy(message, "circle_area() requires a double or real argument.");
        return 1;
    }

    args->arg_type[0]=REAL_RESULT;
    initid->maybe_null=1;
    initid->decimals=2;
    initid->max_length=15;

    return 0;
}

double circle_area(UDF_INIT *initid, UDF_ARGS *args, char *is_null, char *error)
{
    double radius = *((double *)(args->args[0]));
    return pow(radius, 2) * M_PI; 
}

#endif

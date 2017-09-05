#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH  4096

int write_log ( char *file_path, int do_reopen )
{
    int fd = -1, rc;
    int err = -1;
    FILE *logFh = NULL;
    struct stat statbuf = { 0 };
    char logFile[MAX_PATH];
    char newFile[MAX_PATH];

    rc = 1;
    snprintf( logFile, MAX_PATH, "%s", file_path );
    logFh = fopen( file, "a" ); 
    if ( !logFh ) {
        logFh = stdout;
    }
    fd = fileno( logFh );
    if ( fd < 0 ) {
        logFh = stdout;
    }
    rc = fstat( fd, &statbuf );
    if (!rc && ((int)statbuf.st_size > MAX_PATH ) ) {
        snprintf( oldFile, MAX_PATH, "%s", logfile );
    }
    return 0;
}

int main ( int argc, char **argv )
{
    return 0;
}

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define TOTAL_RETRIES 30
#define FIRST_TIMEOUT 1
#define OK            0
#define ERROR         1

int do_scan_port (const char *ip, const char *port)
{
    int s;
    struct addrinfo addr;
    struct addrinfo *rp;

    addr.ai_family = AF_INET;
    addr.ai_socktype = SOCK_STREAM;
    addr.ai_flags = 0;
    addr.ai_protocol = 0;
    getaddrinfo(ip, port, &addr, &rp);
    if((s = socket(rp->ai_family, rp->ai_socktype,  rp->ai_protocol)) == -1){
        fprintf(stderr, "do_scan_port(): socket error\n");
        freeaddrinfo(rp);
        return ERROR;
    }

    if(connect(s, rp->ai_addr, rp->ai_addrlen) < 0){
        fprintf(stderr, "do_scan_port(): connect error\n");
        close(s);
        freeaddrinfo(rp);
        return ERROR;
    }
    freeaddrinfo(rp);
    close(s);
    return OK; 
}

int main(int argc, char **argv)
{
    int retries = TOTAL_RETRIES;
    int timeout = FIRST_TIMEOUT;
    int rc = ERROR;
    char *ip = "10.10.12.195";
    char *port = "6550";
    
    do {
        rc = do_scan_port (ip, port); /* do it */
        fprintf(stderr, "main(): scan ip=%s port=%s result=%d\n", ip, port, rc);

        if (rc!=OK && retries>0) {
            fprintf(stderr, "net scan retry %d of %d will commence in %d seconds\n", retries, TOTAL_RETRIES, timeout);
            sleep (timeout);
            timeout <<= 1;
        }

        retries--;
    } while (rc!=OK && retries>0);
    return OK;
}

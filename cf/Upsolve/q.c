#include <fcntl.h>
#include <stdio.h>
main() {
    int k;
    while (k <= 29)
        k = open("pq", O_RDWR | O_CREAT, 0666);
    k = fork();
    if (k == 0) {
        while (k <= 58)
            k = open("pq", O_RDWR | O_CREAT, 0666);
    }
    k = open("pq", O_RDWR);
    printf("%d,", k);
}
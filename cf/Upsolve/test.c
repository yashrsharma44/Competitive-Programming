#include <pthread.h>
#include <stdio.h>

void *f() {
    sleep(1);
    printf("D\n");
    printf("T\n");
}

void *g() {
    printf("K\n");
    sleep(3);
    printf("H\n");
}

int main() {
    pthread_t a, b;
    pthread_create(&a, NULL, &g, NULL);
    pthread_create(&b, NULL, &f, NULL);
    pthread_join(b, NULL);
    printf("L\n");
    pthread_join(a, NULL);
}
#include <stdio.h>

#define BUFFER_SIZE 20  

int buffer[BUFFER_SIZE];
int in = 0, out = 0;
int mutex = 1, full = 0, empty = BUFFER_SIZE;
int x = 0;

void wait(int *s) {
    while (*s <= 0);  
    (*s)--;            
}

void signal(int *s) {
    (*s)++;            
}

void producer() {
    wait(&empty); 
    wait(&mutex);  

    buffer[in] = ++x;
    printf("Producer has produced: Item %d\n", buffer[in]);

    in = (in + 1) % BUFFER_SIZE;  
    signal(&mutex);  
    signal(&full);   
}

void consumer() {
    if (full == 0) {
        printf("Buffer is empty!\n");
        return;
    }
    wait(&full);  
    wait(&mutex); 

    // Consume an item
    printf("Consumer has consumed: Item %d\n", buffer[out]);

    out = (out + 1) % BUFFER_SIZE;  
    signal(&mutex); 
    signal(&empty);  
}

int main() {
    int ch, flag = 1;
    printf("Enter:\n1. Producer\n2. Consumer\n3. Exit\n");

    while(flag == 1) {
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        
        if(ch == 1) {
            producer();
        }
        else if(ch == 2) {
            consumer();
        }
        else {
            flag = 0;
        }
    }

    return 0;
}

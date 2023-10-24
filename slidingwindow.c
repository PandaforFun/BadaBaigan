#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
#include <unistd.h> 
#define WINDOW_SIZE 4 
typedef struct { 
    int seq_num; 
    bool acked; 
} Frame; 
int main() { 
    srand(time(NULL)); 
    Frame sender_window[WINDOW_SIZE]; 
    int sender_base = 0; 
    int next_seq_num = 0; 
    while (next_seq_num < 4) {  
        while (next_seq_num < sender_base + WINDOW_SIZE && next_seq_num < 4) { 
            sender_window[next_seq_num % WINDOW_SIZE].seq_num = next_seq_num; 
            sender_window[next_seq_num % WINDOW_SIZE].acked = false; 
            printf("Sending frame %d\n", next_seq_num); 
            next_seq_num++; 
        } 
        int acked_frame = rand() % (sender_base + WINDOW_SIZE); 
        if (acked_frame >= sender_base) { 
            for (int i = sender_base; i <= acked_frame && i < 4; i++) { 
                sender_window[i % WINDOW_SIZE].acked = true; 
                printf("Received ACK for frame %d\n", i); 
            } 
            sender_base = acked_frame + 1; 
        } 
        sleep(1); 
    } 
    return 0; 
} 

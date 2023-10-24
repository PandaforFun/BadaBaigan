#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

#define WINDOW_SIZE 4
#define MAX_SEQ_NUM 8

typedef struct {
    int seq_num;
    bool acked;
} Frame;

int main() {
    srand(time(NULL));

    Frame sender_window[WINDOW_SIZE];
    int sender_base = 0;
    int next_seq_num = 0;

    while (sender_base < MAX_SEQ_NUM) {
        // Send frames
        while (next_seq_num < sender_base + WINDOW_SIZE && next_seq_num < MAX_SEQ_NUM) {
            sender_window[next_seq_num % WINDOW_SIZE].seq_num = next_seq_num;
            sender_window[next_seq_num % WINDOW_SIZE].acked = false;
            printf("Sending frame %d\n", next_seq_num);
            next_seq_num++;
        }

        // Simulate acknowledgments
        int acked_frame = -1;
        while (acked_frame < sender_base) {
            acked_frame = rand() % (MAX_SEQ_NUM + 1);
        }

        for (int i = sender_base; i <= acked_frame; i++) {
            sender_window[i % WINDOW_SIZE].acked = true;
            printf("Received ACK for frame %d\n", i);
        }

        sender_base = acked_frame + 1;

        sleep(1);
    }

    printf("All frames have been successfully transmitted!\n");

    return 0;
}

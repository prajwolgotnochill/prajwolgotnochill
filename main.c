#include <stdio.h>
#include <time.h>

#define MICROSECONDS_IN_SECOND 1000000

int main() {
    struct timespec start_time;
    clock_gettime(CLOCK_MONOTONIC, &start_time); // Use CLOCK_MONOTONIC for consistent timing

    while (1) {
        struct timespec current_time;
        clock_gettime(CLOCK_MONOTONIC, &current_time);

        long long elapsed_microseconds = (current_time.tv_sec - start_time.tv_sec) * MICROSECONDS_IN_SECOND;
        elapsed_microseconds += (current_time.tv_nsec - start_time.tv_nsec) / 1000;

        double elapsed_seconds = (double)elapsed_microseconds / MICROSECONDS_IN_SECOND;

        printf("%.1fs\r", elapsed_seconds); // Print with one decimal place and carriage return
        fflush(stdout); // Flush output immediately

        sleep(1); // Sleep for 1 second
    }

    return 0;
}

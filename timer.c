#include <stdio.h>
#include <windows.h>   // for Sleep()
#include <conio.h>     // for _kbhit() and _getch()
#include <time.h>      // for time()

int main() {
    int minutes = 25;
    int total_seconds = minutes * 60;   // 1500 seconds
    int elapsed = 0;                    // how much time has passed
    int paused = 0;                     // flag for pause state
    time_t start = time(NULL);

    printf("Timer started for %d minutes.\n", minutes);
    printf("Controls: 'p' = pause, 'r' = resume, 'q' = quit.\n\n");

    while (1) {
        if (!paused) {
            time_t now = time(NULL);
            elapsed = (int)(now - start);
        }

        if (elapsed >= total_seconds) {
            printf("\nTime's up! 25 minutes completed.\n");
            break;
        }

        int remaining = total_seconds - elapsed;
        int rem_min = remaining / 60;
        int rem_sec = remaining % 60;

        printf("\rRemaining: %02d:%02d", rem_min, rem_sec);
        fflush(stdout);

        // Check for user input
        if (_kbhit()) {
            char input = _getch();
            if (input == 'q' || input == 'Q') {
                printf("\nTimer stopped early by user.\n");
                break;
            } else if (input == 'p' || input == 'P') {
                paused = 1;
                printf("\nTimer paused. Press 'r' to resume.\n");
            } else if (input == 'r' || input == 'R') {
                if (paused) {
                    paused = 0;
                    // Reset start time so elapsed continues correctly
                    start = time(NULL) - elapsed;
                    printf("Timer resumed.\n");
                }
            }
        }

        Sleep(1000);  // wait 1 second
    }

    // Final report of time spent
    printf("You spent %02d:%02d (mm:ss) on the timer.\n", elapsed / 60, elapsed % 60);

    return 0;
}

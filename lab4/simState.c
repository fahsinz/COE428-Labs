#include <stdio.h>
#include <string.h>

#define N 8

int next_state[N][2];
int deleted[N];
int current;

int idx(char s) {
    return s - 'A';
}

char name_of(int i) {
    return (char)('A' + i);
}

void init_machine(void) {
    int i;

    for (i = 0; i < N; i++) {
        deleted[i] = 0;
    }

    /* Your personalized state machine */
    next_state[idx('A')][0] = idx('H');
    next_state[idx('A')][1] = idx('F');

    next_state[idx('B')][0] = idx('G');
    next_state[idx('B')][1] = idx('B');

    next_state[idx('C')][0] = idx('D');
    next_state[idx('C')][1] = idx('H');

    next_state[idx('D')][0] = idx('B');
    next_state[idx('D')][1] = idx('E');

    next_state[idx('E')][0] = idx('A');
    next_state[idx('E')][1] = idx('C');

    next_state[idx('F')][0] = idx('E');
    next_state[idx('F')][1] = idx('D');

    next_state[idx('G')][0] = idx('F');
    next_state[idx('G')][1] = idx('A');

    next_state[idx('H')][0] = idx('C');
    next_state[idx('H')][1] = idx('B');

    current = idx('F');
}

void mark_reachable(int state, int reachable[]) {
    if (deleted[state] || reachable[state]) {
        return;
    }

    reachable[state] = 1;
    mark_reachable(next_state[state][0], reachable);
    mark_reachable(next_state[state][1], reachable);
}

void find_reachable(int reachable[]) {
    int i;

    for (i = 0; i < N; i++) {
        reachable[i] = 0;
    }

    mark_reachable(current, reachable);
}

void print_machine(void) {
    int i;

    for (i = 0; i < N; i++) {
        if (!deleted[i]) {
			printf("%c %c %c\n",
				name_of(i),
				name_of(next_state[i][0]),
				name_of(next_state[i][1]));
        }
    }
}

void print_garbage(void) {
    int reachable[N];
    int i;
    int found = 0;

    find_reachable(reachable);

    for (i = 0; i < N; i++) {
        if (!deleted[i] && !reachable[i]) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No Garbage\n");
        return;
    }

    printf("Garbage:");
    for (i = 0; i < N; i++) {
        if (!deleted[i] && !reachable[i]) {
            printf(" %c", name_of(i));
        }
    }
    printf("\n");
}

void delete_unreachable(void) {
    int reachable[N];
    int newly_deleted[N] = {0}; // Track what gets deleted right now
    int i;
    int found = 0;

    find_reachable(reachable);

    for (i = 0; i < N; i++) {
        if (!deleted[i] && !reachable[i]) {
            deleted[i] = 1;
            newly_deleted[i] = 1; // Mark as newly deleted
            found = 1;
        }
    }

    if (!found) {
        printf("No states deleted.\n");
        return;
    }

    printf("Deleted:");
    for (i = 0; i < N; i++) {
        if (newly_deleted[i]) { // Only print the newly deleted ones
            printf(" %c", name_of(i));
        }
    }
    printf("\n");
}

void delete_one(char state_name) {
    int reachable[N];
    int state = idx(state_name);

    if (state < 0 || state >= N) {
        printf("Not deleted.\n");
        return;
    }

    find_reachable(reachable);

    if (!deleted[state] && !reachable[state]) {
        deleted[state] = 1;
        printf("Deleted.\n");
    } else {
        printf("Not deleted.\n");
    }
}

int main(void) {
    char line[100];
    int bit;
    char state_name;

    init_machine();

    printf("%c\n", name_of(current));

    while (fgets(line, sizeof(line), stdin) != NULL) {
        if (strcmp(line, "0\n") == 0 || strcmp(line, "0") == 0) {
            current = next_state[current][0];
            printf("%c\n", name_of(current));
        }
        else if (strcmp(line, "1\n") == 0 || strcmp(line, "1") == 0) {
            current = next_state[current][1];
            printf("%c\n", name_of(current));
        }
        else if (strcmp(line, "p\n") == 0 || strcmp(line, "p") == 0) {
            print_machine();
        }
        else if (strcmp(line, "g\n") == 0 || strcmp(line, "g") == 0) {
            print_garbage();
        }
        else if (strcmp(line, "d\n") == 0 || strcmp(line, "d") == 0) {
            delete_unreachable();
        }
        else if (sscanf(line, "d %c", &state_name) == 1) {
            delete_one(state_name);
        }
        else if (sscanf(line, "c %d %c", &bit, &state_name) == 2) {
            if ((bit == 0 || bit == 1)
                && state_name >= 'A' && state_name <= 'H'
                && !deleted[idx(state_name)]) {
                next_state[current][bit] = idx(state_name);
            }
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define GREEN "\033[32m"
#define NC "\033[0m" // No Color
#define WHITE "\033[37m"

int is_executable(const char *path) {
    struct stat file_stat;
    if (stat(path, &file_stat) < 0) {
        return 0;
    }
    return file_stat.st_mode & 0111;
}

int main(int argc, char *argv[]) {
    DIR *dir;
    struct dirent *entry;
    char path[1024];

    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    dir = opendir(argv[1]);
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        snprintf(path, sizeof(path), "%s/%s", argv[1], entry->d_name);
        if (is_executable(path)) {
            printf(GREEN "%s" NC "\n", entry->d_name);
        } else {
            printf(WHITE "%s" NC "\n", entry->d_name);
        }
    }

    closedir(dir);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define NC "\033[0m" // No Color
#define WHITE "\033[37m"

int is_executable(const char *path, int *is_dir) {
    struct stat file_stat;
    if (stat(path, &file_stat) < 0) {
        return 0;
    }
    *is_dir = S_ISDIR(file_stat.st_mode);
    return file_stat.st_mode & 0111;
}

int main(int argc, char *argv[]) {
    DIR *dir;
    struct dirent *entry;
    char path[1024];
    char cwd[1024];

    // 获取当前工作目录
    if (argc < 2) {
        if (getcwd(cwd, sizeof(cwd)) == NULL) {
            perror("getcwd");
            return 1;
        }
        dir = opendir(cwd);
    } else {
        dir = opendir(argv[1]);
    }

    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (argc < 2) {
            snprintf(path, sizeof(path), "%s/%s", cwd, entry->d_name);
        } else {
            snprintf(path, sizeof(path), "%s/%s", argv[1], entry->d_name);
        }
        int is_dir;
        if (is_executable(path, &is_dir)) {
            if (is_dir) {
                printf(GREEN "%s" NC "\n", entry->d_name);
            } else {
                printf(BLUE "%s" NC "\n", entry->d_name);
            }
        } else {
            printf(WHITE "%s" NC "\n", entry->d_name);
        }
    }

    closedir(dir);
    return 0;
}
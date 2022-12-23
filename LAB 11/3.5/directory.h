#ifndef C_DIRECTORY_H
#define C_DIRECTORY_H

#define FILE_NAME_LENGTH 9
#define EXTENSION_LENGTH 4
#define DIRECTORY_MAX_SIZE 100
#define DATE_STRING_LIMIT 20

enum bool {false, true};

typedef struct {
        int month;
        int day;
        int year;
        int hour;
        int minute;
        int second;
} DATE;

typedef struct {
    char directory_name[FILE_NAME_LENGTH];
    char** file_name;
    char** file_extension;
    unsigned long long octects;
    unsigned long long file_count;
    DATE** last_modified;
} DIRECTORY;

DATE* get_date();
void free_directory(DIRECTORY*);
void init_directory(DIRECTORY*);
void print_directory(FILE*, DIRECTORY*, char*);
void sort_directory(DIRECTORY*, enum bool (*)(void*, void*));
enum bool alphabetical(void*, void*);
enum bool last_modified(void*, void*);
#endif // C_DIRECTORY_H
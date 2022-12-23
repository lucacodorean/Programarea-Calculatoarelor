#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "directory.h"

DATE* get_date();
static enum bool COMPARE(DATE*, DATE*);
static void swap(void*, void*, unsigned int);
void init_directory(DIRECTORY*);
void free_directory(DIRECTORY*);
void print_directory(FILE*, DIRECTORY*, char*);
void sort_directory(DIRECTORY*, enum bool (*)(void*, void*));
enum bool alphabetical(void* first, void* second) { return (strcmp((char*)first, (char*)second) > 0 ? true : false); }
enum bool last_modified(void* first, void* second) { return COMPARE((DATE*)first, (DATE*)second); }

DATE* get_date() {
    DATE* date   = (DATE*)calloc(1,sizeof(DATE));
    time_t t     = time(NULL);
    struct tm tm = *localtime(&t);
    date->month  = tm.tm_mon + 1;
    date->day    = tm.tm_mday;
    date->year   = tm.tm_year + 1900;
    date->hour   = tm.tm_hour;
    date->minute = tm.tm_min ;
    date->second = tm.tm_sec;
    return date;
}

static enum bool COMPARE(DATE* first, DATE* second) {
    if(first->minute > second->minute) return true;
    if(first->minute < second->minute) return false;
    else if(first->minute == second ->minute) {
        if(first->second > second->second) return true;
        if(first->second < second->second) return false;
    }
}

static void swap(void* first, void* second, unsigned int size) {
    void* temp = calloc(1,size);
    if(temp==0) return;

    memmove(temp, first,     size);
    memmove(first, second,   size);
    memmove(second, temp,    size);
    free(temp), temp = NULL;
}

void init_directory(DIRECTORY* parameter) {
    parameter->file_name        = (char**)calloc(DIRECTORY_MAX_SIZE, sizeof(char*));
    parameter->file_extension   = (char**)calloc(DIRECTORY_MAX_SIZE, sizeof(char*));
    parameter->last_modified    = (DATE**)calloc(DIRECTORY_MAX_SIZE, sizeof(DATE*));
    parameter->octects          = sizeof(DIRECTORY);
    parameter->file_count       = 0;
    
    for(size_t i = 0; i<DIRECTORY_MAX_SIZE; i++) {
        parameter->file_name[i]         = (char*)calloc(FILE_NAME_LENGTH, sizeof(char));
        parameter->file_extension[i]    = (char*)calloc(EXTENSION_LENGTH, sizeof(char));
        parameter->last_modified[i]     = (DATE*)calloc(DIRECTORY_MAX_SIZE, sizeof(DATE));
    }
}

void print_directory(FILE* dest, DIRECTORY* parameter, char* header) {
    fprintf(dest,"%s\n", header);
    fprintf(dest,"Directory name <%s>\n", parameter->directory_name);
    fprintf(dest,"\tOctects <%llu>\n", parameter->octects);
    fprintf(dest,"\tFile count <%llu>\n", parameter->file_count);
    for(size_t i = 0; i<DIRECTORY_MAX_SIZE; i++) {
        if(parameter->file_name[i][0] != '\0' && parameter->file_extension[i][0] != '\0') {
            fprintf(dest,"\t\tFile name <%s.%s>", (parameter->file_name[i]), parameter->file_extension[i]);
            fprintf(dest,"\t\tLast modified <%d/%d/%d %d:%d:%d>\n", parameter->last_modified[i]->month, parameter->last_modified[i]->day, parameter->last_modified[i]->year, parameter->last_modified[i]->hour, parameter->last_modified[i]->minute, parameter->last_modified[i]->second);
        }
    }
}


void sort_directory(DIRECTORY* arr, enum bool (*comp_function)(void*, void*)) {
    if(comp_function == alphabetical) {
        enum bool finished = true;
        do{
            finished = true;
            for(size_t i = 0; i<arr->file_count-1; i++) {
                if(comp_function(arr->file_name[i], arr->file_name[i+1]) == true) {
                    swap((char*)&arr->file_name[i],         (char*)&arr->file_name[i+1],        FILE_NAME_LENGTH);
                    swap((char*)&arr->file_extension[i],    (char*)&arr->file_extension[i+1],   EXTENSION_LENGTH);
                    swap((DATE*)&arr->last_modified[i],     (DATE*)&arr->last_modified[i+1],    sizeof(DATE));
                    finished = false;
                }
            }
        }while (!finished);
    } else if(comp_function == last_modified) {
        enum bool finished = true;
        do{
            finished = true;
            for(size_t i = 0; i<arr->file_count-1; i++) {
                if(comp_function(arr->last_modified[i], arr->last_modified[i+1]) == true) {
                    swap((char*)&arr->file_name[i], (char*)&arr->file_name[i+1],           FILE_NAME_LENGTH);
                    swap((char*)&arr->file_extension[i], (char*)&arr->file_extension[i+1], EXTENSION_LENGTH);
                    swap((DATE*)&arr->last_modified[i], (DATE*)&arr->last_modified[i+1],   sizeof(DATE));
                    finished = false;
                }
            }
        }while (!finished);
    }
}

void free_directory(DIRECTORY* parameter) {
      for(size_t i = 0; i<parameter->file_count; i++) {
        free(parameter[i].file_name),      parameter[i].file_name = NULL;
        free(parameter[i].file_extension), parameter[i].file_extension = NULL;
        free(parameter[i].last_modified),  parameter[i].last_modified = NULL;
    }
    free(parameter); parameter = NULL;
}

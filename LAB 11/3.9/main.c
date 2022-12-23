#include <stdio.h>
#include <stdlib.h>

#define ERR_NO_PATH_SPECIFIED 1

int main(int argc, char* argv[]) {

    if(argc <= 1)  {
        printf("Error - no path and operatation mentioned.");
        return ERR_NO_PATH_SPECIFIED;
    } else {
        FILE* file;
        FILE* dest = fopen("result.txt", "w");
        for(int i = 1; i<argc; i++) {
            file = fopen(argv[i], "r");
            float number; int count = 0;
            while(fscanf(file, "%f", &number)>0) {
                fprintf(dest, "%lf ", number);
                count++;
                if(count == 10) { 
                    fprintf(dest, "\n");
                    count = 0;
                }
            }
            fclose(file);
        } fclose(dest);

        free(file), free(dest); 
        file = dest = NULL;
    }

    free(argv), argv = NULL;
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE * pFileInput;
    char buffer[1024];
    int arraySize;
    char outputName[256];
    FILE * pFileOutput;
    
    printf("How many files do you want to merge?\n");
    scanf("%d", &arraySize);
    char ** filesArray = (char **)malloc(arraySize * sizeof(char *));
    printf("Enter file directories\n");
    for (int i = 0; i < arraySize; i++)
    {
        char fileName[256];
        scanf("%s", fileName);
        filesArray[i] = (char *)malloc((strlen(fileName)+1) * sizeof(char));
        strcpy(filesArray[i], fileName);
    }
    printf("How do you want to call the merged file?\n");
    scanf("%s", outputName);  
    printf("%s", outputName);

    pFileOutput = fopen(outputName, "w");
    
    for (int i=0; i<arraySize; i++){
        printf("%s", filesArray[i]);
        pFileInput = fopen(filesArray[i], "r");
        if (pFileInput == NULL){
            printf("Oops, no file!");
            return -1;
        }
        while(fgets(buffer, 1024, pFileInput) != NULL){
            printf("%s", buffer);
            fprintf(pFileOutput, "%s", buffer);
        }
        fclose(pFileInput);
        printf("\n");
        fprintf(pFileOutput, "\n");
    }

    for (int i=0; i<arraySize; i++){
        free(filesArray[i]);
    }
    fclose(pFileOutput);
    free(filesArray);
    return 0;
}
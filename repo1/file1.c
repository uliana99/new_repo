#include <stdio.h>
#include <string.h>
#define FILENAME "file.txt"
#define FILE1NAME "file1.txt"
#define STR_SIZE 256
int a = 0;
int main()
{
    char str[STR_SIZE];
    char str1[STR_SIZE];
    int strn = 0, strn1 = 0;
    FILE* file = NULL, *file1 = NULL;
    file = fopen(FILENAME, "rt");
    file1 = fopen(FILE1NAME, "rt");
    if (file && file1) {
        
        while (!feof (file))
        {
            fgets(str, STR_SIZE, file);
            if (!feof(file))
            {
                fseek(file1, 0, SEEK_SET);
                strn1 = 0;
                while (!feof(file1))
                {
                    fgets(str1, STR_SIZE, file1);
                    if (!feof(file1))
                    {
                        if(strcmp(str, str1)) {
                printf("%d %s | %d %s |n", strn, str, strn1, str1);
                    }
                        strn1 ++;
                    }}
                strn ++;}
        
      /*  while ((!feof(file)) && (!feof(file1))) {
            fgets(str, STR_SIZE, file);
            fseek(file1, 0, SEEK_SET);
            while (!feof(file1)) {
                fgets(str2, STR_SIZE, file1);
                if(strcmp(str, str1)) {
                    printf("%d %s | %d %s |n", strn, str, strn1, str1);}
                strn2 ++;}
                }
            }
            //fgets(str1, STR_SIZE, file1);
            if (strcmp(str, str1)) {
                printf("Различия в строке %d\n", a);
            }
            a++;
        }*/
        
        fclose(file);
        file = NULL;
        fclose(file1);
        file1 = NULL;
    }
    if (file) fclose(file);
    if (file1) fclose(file1);
    }}

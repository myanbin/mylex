#include "mylex.h"

extern char id[21];
extern int  cur_line;
extern int  cur_col;
extern int  err_line;
extern int  err_col;
extern int  token_num;

FILE        *source, *out;

int main() {

    double  duration;
    char    filename[21]="\0";
    char    outname[21]="\0";
    int     flag;
    FILE    *stream;
    char    line[100];

    clock_t start, finish;

    printf("mylex is a pl/0 lexical analyzer by c luanage\n");
    printf("\ninput the source file : ");
    gets_s(filename, 20);
    if ((source = fopen(filename, "r")) == NULL) {
        printf("\n%s can not be opened, press anykey to exit ...\n", filename);
        _getch();
        return 1;
    }
    else {
        int i;
        start = clock();
        for (i=0; i<(int)strlen(filename)-4; i++)
            outname[i] = filename[i];
        strcat(outname, ".out");
        if ((out=fopen(outname,"w+")) == NULL) {
            printf("\ncan't create %s on current path, press anykey to exit ...\n", outname);
            _getch();
            return 1;
        }
        cur_line  = 1;
        cur_col   = 0;
        token_num = 0;
        fprintf(out, "+-----+--------------------+--------------------+--------------------+\n");
        fprintf(out, "|%5s|%20s|%20s|%20s|\n","No.","Symbol","Symbol Type","Notes");
        fprintf(out, "+-----+--------------------+--------------------+--------------------+\n");
        while (!feof(source)) {
            token_num++;
            flag = getsym();
            if (flag == 0)
                continue;
            write2file(flag);
        }
        fprintf(out, "+-----+--------------------+--------------------+--------------------+\n");
        fcloseall();
        stream = fopen(outname, "r");
        while(1) {
            fgets(line,100,stream);
			if (feof(stream))
				break;
			else
				printf("%s", line);
        }
        fclose(stream);
        finish   = clock();
        duration = (double)(finish-start)/CLOCKS_PER_SEC;
        printf("\nanalysis completed. (%2.3f sec)\n", duration);
        printf("\n");
		system("PAUSE");
    }
    return 0;
}
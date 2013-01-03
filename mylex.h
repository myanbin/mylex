/*  mylex.h */
/*  The main head file of MyLex. */
/*  Writen by: Yanbin MA */
/*  Date: 2009-12-5 */

#ifndef MYLEX_H
#define MYLEX_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define MAX_ID 20

typedef enum SYMBOL {
    nul, eof, plus, minus, times, slash, lparen, rparen, comma, semicolon, period, becomes,
    eql, neq, lss, gtr, leq, geq, number, ident,
    beginsym, callsym, constsym, dosym, endsym, ifsym, oddsym, proceduresym, readsym, thensym, varsym, whilesym, writesym
}SYMBOL;

SYMBOL getsym();

int read_ch();
int put_back(int);
int write2file(int);
int find_tab(char *);
int get_tab_data(int);
int error();

#endif
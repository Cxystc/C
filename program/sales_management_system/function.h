#include "initial.h"
Workers* creating(int,long long *,long long *);
Workers* input (Workers*,long long *);
void infile(Workers*,char *);
char * getfilepath (char * );
char *getdate(time_t);
void kept_day(int);
Product_Statistics* Pstatistic (long long ,int,long long *);
Worker_Statistics* Wstatistic (long long ,int );
void Pprint(Product_Statistics *,long long *);
void Wprint(Worker_Statistics * , long long *,int *);
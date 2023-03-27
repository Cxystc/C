#include <string.h>
#include <stdio.h>

struct boat {
    int p ;//表状态
    long long t ; //表时间；
    long long i ; //表标号
    long long times ; //表次数
};//要记得为他们清零

int main(){
    long long N,i,t,sum=0,c=0;
    int p ; 
    scanf("%lld", &N);
    struct boat table [N];//用来储存全部信息；
    memset(table,0,sizeof(struct boat)*N);
    int Qlist[N]; //储存问题列表
    long long Qi = 0 ; //下标
    int list [N] ; //足够大的数组用来储存以时间为下标的次数； 
    memset(list,0 ,sizeof(list)*N);
    memset(Qlist,0,sizeof(Qlist)*N);
    for ( int j = 0 ; j < N ; j ++ ){
        scanf("%lld",&p);
        if (p == 1 ) {
            scanf("%lld %lld",&t,&i);
            table[i].p = p ; 
            table[i].t = t ; 
            table[i].times ++ ;
            if (table[i].times == 2){
                table[i].times = 0 ; 
            }
        }
        if (p == 2){
            scanf("%lld",&t);
            Qlist[Qi++] = t ;
            c ++ ;
        }
    }

    //用新的数组储存对应时间的times
    for (int j = 0 ; j < N - c; j++){
        if (table[j].p == 1 ){
            list[table[j].t]+= table[j].times;
        }
    }
    
    for (int j = 0 ; j < c ; j++){//这里不能用N要用精确数字
        long long s = 0 ; 
        for ( int z = 0 ; z <= Qlist[j]; z++){
            s += list[z];
            sum += list[z];
        }
        printf("%lld\n",s);
    }
    printf("%lld\n",sum);
}
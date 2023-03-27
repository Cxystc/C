//处理整形变量的位数
#include <stdio.h>
int main (){
  int result;
  int a,b,c;
  scanf ("%d",&a);
  char term1 ,term2,term3; 
  term1 = getchar ();
  switch (term1){
    case '/': {
      scanf("%d",&b);
      term2 = getchar ();
      if (term2 == ';')result = a/ b ;break ; 
      if (term2 == '/'){
        scanf("%d",&c);
        result = a / b / c ; 
        term3 = getchar(); 
        if (term3 == ';')break ; 
      }
      else if (term2 == '*'){
        scanf("%d",&c);
        result = a / b * c ; 
         term3 = getchar(); 
        if (term3 == ';')break ; 
      }
    }
      
      case '*': {
      scanf("%d",&b);
      term2 = getchar ();
      if (term2 == ';'){result = a * b ; break ; }
      else if (term2 == '/'){
        scanf("%d",&c);
        result = a * b / c ; 
         term3 = getchar(); 
        if (term3 == ';')break ; 
      }
      else if (term2 == '*'){
        scanf("%d",&c);
        result = a * b * c ;
         term3 = getchar(); 
        if (term3 == ';')break ; 
      }
    //第一个运算是乘法
    }
   printf("result: %d\n",result);//re
}
}
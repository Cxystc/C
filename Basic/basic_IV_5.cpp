#include <iostream>
using namespace std; 
/*Rect类 ， 要两个参数，point（）
tl.x是tl下的x
topRight函数
bottomLeft函数
tl，br两个结构体*/
//Point类，要两个参数，是点的xy坐标
//推测Point (x,y)是一个类，但是没有赋值，而是直接用了
//.? ?推测是一个函数或者一个结构体的对象，没有括号的是结构体对象或者直接是public中的参数
//左边两个数是直接调用的，右边两个数是由函数得到的就是算出来的，验证了以上说法




class Point {
public :
    int X ; 
    int Y ; 

    Point(int x, int y){
        X = x ; 
        Y = y ; 
    }
   
}

class Rect {
Public :
    class Point1;
    class Point2; 

    struct P{
        int x1;
        int x2;
        int y1;
        int y2;  
        void topRight ()
        {
            P.x1 = P.x2;
        }
        void bottomLeft ()
        {
            P.x2 = P.x1
        }
    }tl,br;
    
    Rect (class p1,class p2){
        class Point1 = p1;
        class Point2 = p2;
        //初始化类为公共

        tl = {Point1.X,Point2.X,Point1.Y,Point2.Y};
        br = {Point1.X,Point2.X,Point1.Y,Point2.Y};
        //定义结构体tl就是左上角的点，里面就是点坐标
    }


}


int main (){
    
}



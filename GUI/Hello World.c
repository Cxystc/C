#include <windows.h>
#include <stdio.h>
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);             //回调函数声明
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) // Win32程序入口
{
    char szTitile[] = "销售管理系统";
    char szClassName[] = "纸条上传系统";
    //设计窗口类
    WNDCLASS wd1; //窗口类的实例化

    //填写窗口类相应的信息(必要)
    wd1.cbClsExtra = 0;                                       //类的额外附加字节数
    wd1.cbWndExtra = 0;                                       //窗口额外的附加字节数
    wd1.hbrBackground = (HBRUSH)GetStockObject(DKGRAY_BRUSH); //背景颜色
    wd1.hCursor = LoadCursor(NULL, IDC_ARROW);                //光标样式
    wd1.hIcon = LoadIcon(NULL, IDI_WINLOGO);                  //图标样式
    wd1.hInstance = hInstance;                                //实例句柄
    wd1.lpfnWndProc = WindowProc;                             //回调函数,由系统调用
    wd1.lpszClassName = szClassName;                          //窗口类名称
    wd1.lpszMenuName = NULL;                                  //菜单名字
    wd1.style = CS_HREDRAW | CS_VREDRAW;                      //窗口类型,这里是水平重画跟垂直重画


    //注册窗口类
    RegisterClass(&wd1);

    //创建窗口
    HWND hWnd ;
    hWnd = CreateWindow(
        szClassName, 
        szTitile,
        WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS,
        0,0,//位置
        600,400,//大小
        NULL,//父窗口
        NULL,//菜单
        hInstance,//实例句柄
        NULL//窗口创建数据
    );//这是一个函数调用
    
    ShowWindow(hWnd, SW_SHOWNORMAL);
    UpdateWindow(hWnd);//刷新

    
}

#include <vector>
#include <algorithm>
#include <windows.h>
#include <wingdi.h>

void SwapRectColor(HDC hdc, int x1, int y1, int cx1, int cy1, int x2, int y2, int cx2, int cy2) {
    HDC hdcMem = CreateCompatibleDC(hdc);
    HBITMAP hbmMem = CreateCompatibleBitmap(hdc, cx1 + cx2, cy1 + cy2);
    HBITMAP hbmOld = (HBITMAP)SelectObject(hdcMem, hbmMem);
    BitBlt(hdcMem, 0, 0, cx1 + cx2, cy1 + cy2, hdc, 0, 0, SRCCOPY);
    for (int i = 0; i < cx1; i++) {
        for (int j = 0; j < cy1; j++) {
            COLORREF color1 = GetPixel(hdcMem, x1 + i, y1 + j);
            COLORREF color2 = GetPixel(hdcMem, x2 + i, y2 + j);
            SetPixel(hdcMem, x2 + i, y2 + j, color1);
            SetPixel(hdcMem, x1 + i, y1 + j, color2);
        }
    }
    BitBlt(hdc, 0, 0, cx1 + cx2, cy1 + cy2, hdcMem, 0, 0, SRCCOPY);
    SelectObject(hdcMem,hbmOld);
    DeleteObject(hbmMem);
    DeleteDC(hdcMem);
}



int WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lpCmdLine,
    int       nShowCmd
)
{
HDC hdc=GetDC(NULL);
int x=0,y=0;
SwapRectColor(hdc,x,y,100,100,x*2,y*2+100,100,100);
ReleaseDC(NULL,hdc);
    return GetLastError();
}

#include <windows.h>
#include <wingdi.h>
#include <winuser.h>

void StretchBltShift(HDC hdc){
      RECT screen;
      // Because client coordinates are relative to the upper-left corner of a window's client area
      // the coordinates of the upper-left corner are (0,0).
      GetClientRect(WindowFromDC(hdc),&screen);
      int ScaleWidth = screen.right, ScaleHeight = screen.bottom;
      StretchBlt hdc, -1, -1, ScaleWidth - 1, ScaleHeight - 1, hdc, 0, 0, ScaleWidth - 1, ScaleHeight - 1, SRCERASE;
      StretchBlt hdc, -1, -1, ScaleWidth - 1, ScaleHeight - 1, hdc, 0, 0, ScaleWidth - 1, ScaleHeight - 1, PATINVERT;
}

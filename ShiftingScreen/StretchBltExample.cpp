#include <windows.h>
#include <wingdi.h>
#include <winuser.h>
#include <math.h>
void StretchBltCopyOutside(HDC hdc,int optionalvalue){ // actually copying outside HDC
      RECT screen;
      // Because client coordinates are relative to the upper-left corner of a window's client area
      // the coordinates of the upper-left corner are (0,0).
      GetClientRect(WindowFromDC(hdc),&screen);
      int ScaleWidth = screen.right, ScaleHeight = screen.bottom;
      int optionalvalue2=abs(optionalvalue);
      // StretchBlt(hdc, -optionalvalue, -optionalvalue, ScaleWidth - optionalvalue, ScaleHeight - optionalvalue, hdc, optionalvalue, optionalvalue, ScaleWidth - optionalvalue, ScaleHeight - optionalvalue, NOTSRCERASE); // optional 
      StretchBlt(hdc, -optionalvalue2, -optionalvalue2, ScaleWidth - optionalvalue2, ScaleHeight - optionalvalue2, hdc, optionalvalue2, optionalvalue2, ScaleWidth - optionalvalue2, ScaleHeight - optionalvalue2, PATINVERT);
}

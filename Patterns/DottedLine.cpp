#include <windows.h>
#include <wingdi.h>
#include <winuser.h>
/*	 x0			y0
      Source x		     Source y
	 x1			y1
      Dest x	    	     Dest y
*/
void DrawDottedLine(HDC hdc, int x1, int y1, int x2, int y2)
{
    for (int x = x1; x <= x2; x += 2)
    {
        SetPixel(hdc, x, y1, RGB(0, 0, 0));
    }
}

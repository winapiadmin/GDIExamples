#include <windows.h>
#include <wingdi.h>
#include <winuser.h>
/*	 x0			y0
      Source x		     Source y
	 x1			y1
      Dest x	    	     Dest y
*/
void DrawDashedLine(HDC hdc, int x1, int y1, int x2, int y2)
{
    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
}

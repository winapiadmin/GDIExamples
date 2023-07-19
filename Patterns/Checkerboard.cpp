#include <windows.h>
#include <wingdi.h>
#include <winuser.h>

/*	 x0			y0
      Source x		     Source y
	 width			height
      Dest width	     Dest height
* Dest width=dest height
* Size=20x20px
*/
void DrawCheckerboard(HDC hdc, int x0, int y0, int width, int height)
{
    for (int y = 0; y < height; y += 20)
    {
        for (int x = 0; x < width; x += 20)
        {
            if ((x + y) % 40 == 0)
            {
                Rectangle(hdc, x0 + x, y0 + y, x0 + x + 20, y0 + y + 20);
            }
            else
            {
                Rectangle(hdc, x0 + x + 20, y0 + y, x0 + x + 40, y0 + y + 20);
            }
        }
    }
}

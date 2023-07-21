#include <windows.h>
#include <wingdi.h>

int WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lpCmdLine,
    int       nShowCmd
)
{
        HDC hdc = GetDC(NULL);
        HBITMAP hBitmap = CreateBitmap(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), 1, 24, NULL);
        BITMAP bitmap;
        GetObject(hBitmap, sizeof(bitmap), &bitmap);

        BITMAPINFO bmi;
        ZeroMemory(&bmi, sizeof(BITMAPINFO));
        bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
        bmi.bmiHeader.biWidth = bitmap.bmWidth;
        bmi.bmiHeader.biHeight = bitmap.bmHeight;
        bmi.bmiHeader.biPlanes = 1;
        bmi.bmiHeader.biBitCount = 24;

        BYTE* pBits;
        HBITMAP hBitmapCopy = CreateDIBSection(hdc, &bmi, DIB_RGB_COLORS, (void**)&pBits, NULL, 0);

        HDC hdcMem = CreateCompatibleDC(hdc);
        HBITMAP hBitmapOld = (HBITMAP)SelectObject(hdcMem, hBitmapCopy);
        BitBlt(hdcMem, 0, 0, bitmap.bmWidth, bitmap.bmHeight, hdc, 0, 0, SRCCOPY);
        int value = rand()%255;
        for (int y = 0; y < bitmap.bmHeight; y++)
        {
            BYTE* pPixelRow = pBits + y * bitmap.bmWidth * 3;

            for (int x = 0; x < bitmap.bmWidth; x++)
            {
                BYTE* pPixel = pPixelRow + x * 3;

                int r = pPixel[2];
                int g = pPixel[1];
                int b = pPixel[0];

                if ((r + g + b) / 3+1 <= value)
                {
                    pPixel[2] = 0;
                    pPixel[1] = 0;
                    pPixel[0] = 0;
                }
                else
                {
                    pPixel[2] = 255;
                    pPixel[1] = 255;
                    pPixel[0] = 255;
                }
            }
            BitBlt(hdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, hdcMem, 0, 0, SRCCOPY);
       }
        BitBlt(hdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, hdcMem, 0, 0, SRCCOPY);
        //Sleep(1000);
        SelectObject(hdcMem, hBitmapOld);
        DeleteDC(hdcMem);
        DeleteObject(hBitmapCopy);

        ReleaseDC(NULL, hdc);
        DeleteObject(hBitmap);
    return GetLastError();
}

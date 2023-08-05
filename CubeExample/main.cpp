#include <windows.h>
#include <wingdi.h>
#include <winuser.h>
#ifdef NOFACECOLOR
void DrawCube(HDC hdc, int x, int y)
{
	MoveToEx(hdc, x, y, (LPPOINT)NULL);
	SelectObject(hdc, GetStockObject(NULL_BRUSH));
	Rectangle(hdc, 0 + x, 0 + y, 100 + x, 100 + y);
	Rectangle(hdc, 30 + x, 30 + y, 130 + x, 130 + y);
	LineTo(hdc, 30 + x, 30 + y);
	MoveToEx(hdc, 100 + x, 100 + y, (LPPOINT)NULL);
	LineTo(hdc, 130 + x, 130 + y);
	MoveToEx(hdc, 100 + x, 0 + y, (LPPOINT)NULL);
	LineTo(hdc, 130 + x, 30 + y);
	MoveToEx(hdc, 0 + x, 100 + y, (LPPOINT)NULL);
	LineTo(hdc, 30 + x, 130 + y);

}
#endif
#if _MSC_VER>=1500
#ifndef NOFACECOLOR
void DrawCube(HDC hdc, int x, int y,COLORREF color1,COLORREF color2,COLORREF color3,COLORREF color4)
{
	
	SelectObject(hdc, GetStockObject(NULL_BRUSH));
	HBRUSH brush=CreateSolidBrush(color1);
	SelectObject(hdc,brush);
	Rectangle(hdc, 0 + x, 0 + y, 100 + x, 100 + y);
	DeleteObject(brush);
	brush=CreateSolidBrush(color2);
	SelectObject(hdc,brush);
	Rectangle(hdc, 30 + x, 30 + y, 130 + x, 130 + y);
	DeleteObject(brush);
	brush=CreateSolidBrush(color3);
	SelectObject(hdc,brush);
	POINT points[5]{{30+x,30+y},{30+x,30+y},{x,y},{100+x,0+y},{130+x,30+y}};
	Polygon(hdc,points,5);
	DeleteObject(brush);
	brush=CreateSolidBrush(color4);
	SelectObject(hdc,brush);
	POINT points2[8]{{x,y},{30+x,30+y},{x,y},{0+x,100+y},{0+x,100+y},{30+x,130+y},{30+x,130+y},{30+x,30+y}};
	Polygon(hdc,points2,8);
	DeleteObject(brush);
}
#endif
#endif
#if _MSC_VER<=1200
#ifndef NOFACECOLOR
void DrawCube(HDC hdc, int x, int y,COLORREF color1,COLORREF color2,COLORREF color3,COLORREF color4)
{
	
	SelectObject(hdc, GetStockObject(NULL_BRUSH));
	HBRUSH brush=CreateSolidBrush(color1);
	SelectObject(hdc,brush);
	Rectangle(hdc, 0 + x, 0 + y, 100 + x, 100 + y);
	DeleteObject(brush);
	brush=CreateSolidBrush(color2);
	SelectObject(hdc,brush);
	Rectangle(hdc, 30 + x, 30 + y, 130 + x, 130 + y);
	DeleteObject(brush);
	brush=CreateSolidBrush(color3);
	SelectObject(hdc,brush);
	POINT points[5]={{30+x,30+y},{30+x,30+y},{x,y},{100+x,0+y},{130+x,30+y}};
	Polygon(hdc,points,5);
	DeleteObject(brush);
	brush=CreateSolidBrush(color4);
	SelectObject(hdc,brush);
	POINT points2[8]={{x,y},{30+x,30+y},{x,y},{0+x,100+y},{0+x,100+y},{30+x,130+y},{30+x,130+y},{30+x,30+y}};
	Polygon(hdc,points2,8);
	DeleteObject(brush);
}
#endif
#endif
#ifdef NOFACECOLOR
void Draw3x3Cube(HDC hdc, int x, int y)
{
	DrawCube(hdc, x, y);
	DrawCube(hdc, x + 100, y);
	DrawCube(hdc, x + 200, y);
	DrawCube(hdc, x, y + 100);
	DrawCube(hdc, x + 100, y + 100);
	DrawCube(hdc, x + 200, y + 100);
	DrawCube(hdc, x, y + 200);
	DrawCube(hdc, x + 100, y + 200);
	DrawCube(hdc, x + 200, y + 200);

	DrawCube(hdc, x + 30, y + 30);
	DrawCube(hdc, x + 100 + 30, y + 30);
	DrawCube(hdc, x + 200 + 30, y + 30);
	DrawCube(hdc, x + 30, y + 100 + 30);
	DrawCube(hdc, x + 100 + 30, y + 100 + 30);
	DrawCube(hdc, x + 200 + 30, y + 100 + 30);
	DrawCube(hdc, x + 30, y + 200 + 30);
	DrawCube(hdc, x + 100 + 30, y + 200 + 30);
	DrawCube(hdc, x + 200 + 30, y + 200 + 30);

	DrawCube(hdc, x + 30 + 30, y + 30 + 30);
	DrawCube(hdc, x + 100 + 30 + 30, y + 30 + 30);
	DrawCube(hdc, x + 200 + 30 + 30, y + 30 + 30);
	DrawCube(hdc, x + 30 + 30, y + 100 + 30 + 30);
	DrawCube(hdc, x + 100 + 30 + 30, y + 100 + 30 + 30);
	DrawCube(hdc, x + 200 + 30 + 30, y + 100 + 30 + 30);
	DrawCube(hdc, x + 30 + 30, y + 200 + 30 + 30);
	DrawCube(hdc, x + 100 + 30 + 30, y + 200 + 30 + 30);
	DrawCube(hdc, x + 200 + 30 + 30, y + 200 + 30 + 30);
}
#endif

#include <windows.h>
#include <vector>
#include <cmath>

// Vertex structure
struct Vertex {
    float x, y, z;
};

// Cube vertices
std::vector<Vertex> vertices = {
    {-1, -1, -1}, {1, -1, -1}, {1, 1, -1}, {-1, 1, -1},
    {-1, -1, 1}, {1, -1, 1}, {1, 1, 1}, {-1, 1, 1}
};

// Cube edges (pairs of vertex indices)
std::vector<std::pair<int, int>> edges = {
    {0, 1}, {1, 2}, {2, 3}, {3, 0},
    {4, 5}, {5, 6}, {6, 7}, {7, 4},
    {0, 4}, {1, 5}, {2, 6}, {3, 7}
};

// Rotation angles
float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
float diff = 0.01f;
// Function prototypes
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void Render(HDC hdc);
Vertex TransformAndProject(Vertex v, float angleX, float angleY, float angleZ);

// Main function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    const wchar_t CLASS_NAME[] = L"Sample Window Class";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        L"3D Cube Rendering with CPU",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (hwnd == NULL) {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

// Window procedure
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        Render(hdc);
        EndPaint(hwnd, &ps);
    } break;

    case WM_KEYDOWN:
        switch (wParam) {
        case VK_LEFT:
            angleY -= diff;
            break;
        case VK_RIGHT:
            angleY += diff;
            break;
        case VK_UP:
            angleX -= diff;
            break;
        case VK_DOWN:
            angleX += diff;
            break;
        case 'A':
            angleZ -= diff;
            break;
        case 'D':
            angleZ += diff;
            break;
        }
        InvalidateRect(hwnd, NULL, TRUE);
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

// Simple 3D rendering function
void Render(HDC hdc) {
    // Clear the background
    RECT rect;
    GetClientRect(WindowFromDC(hdc), &rect);
    FillRect(hdc, &rect, (HBRUSH)(COLOR_WINDOW + 1));

    for (const auto& edge : edges) {
        Vertex v0 = TransformAndProject(vertices[edge.first], angleX, angleY, angleZ);
        Vertex v1 = TransformAndProject(vertices[edge.second], angleX, angleY, angleZ);

        MoveToEx(hdc, v0.x + 400, v0.y + 300, NULL); // Centering the cube
        LineTo(hdc, v1.x + 400, v1.y + 300);
    }
}

// Transform and project a vertex
Vertex TransformAndProject(Vertex v, float angleX, float angleY, float angleZ) {
    // Rotate around X-axis
    float y = v.y * cos(angleX) - v.z * sin(angleX);
    float z = v.y * sin(angleX) + v.z * cos(angleX);
    v.y = y;
    v.z = z;

    // Rotate around Y-axis
    float x = v.x * cos(angleY) + v.z * sin(angleY);
    z = -v.x * sin(angleY) + v.z * cos(angleY);
    v.x = x;
    v.z = z;

    // Rotate around Z-axis
    x = v.x * cos(angleZ) - v.y * sin(angleZ);
    y = v.x * sin(angleZ) + v.y * cos(angleZ);
    v.x = x;
    v.y = y;

    // Simple perspective projection
    float distance = 3.0f;
    float factor = distance / (distance + v.z);
    v.x *= factor * 100; // Scale up for better visibility
    v.y *= factor * 100;

    return v;
}

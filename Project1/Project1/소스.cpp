#include <iostream>
#include <windows.h>  // Windows API를 사용하기 위한 헤더 파일

using namespace std;

void drawPinkRectangle(int width, int height) {
    HDC hdc = GetDC(NULL);  // 화면에 그리기 위한 디바이스 컨텍스트 얻기
    RECT rectangle;         // 사각형을 그리기 위한 RECT 구조체
    rectangle.left = 100;   // 사각형의 왼쪽 좌표
    rectangle.top = 100;    // 사각형의 위쪽 좌표
    rectangle.right = rectangle.left + width;  // 사각형의 오른쪽 좌표
    rectangle.bottom = rectangle.top + height; // 사각형의 아래쪽 좌표

    // 사각형을 핑크색으로 채우기
    HBRUSH pinkBrush = CreateSolidBrush(RGB(255, 182, 193));  // 핑크색 브러시 생성 (RGB 값)
    FillRect(hdc, &rectangle, pinkBrush);  // 사각형 그리기
    DeleteObject(pinkBrush);  // 브러시 객체 삭제

    ReleaseDC(NULL, hdc);  // 디바이스 컨텍스트 해제
}

int main() {
    int width, height;
    cout << "사각형의 가로 길이를 입력하세요: ";
    cin >> width;
    cout << "사각형의 세로 길이를 입력하세요: ";
    cin >> height;

    drawPinkRectangle(width, height);

    return 0;
}

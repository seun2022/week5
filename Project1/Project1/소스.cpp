#include <iostream>
#include <windows.h>  // Windows API�� ����ϱ� ���� ��� ����

using namespace std;

void drawPinkRectangle(int width, int height) {
    HDC hdc = GetDC(NULL);  // ȭ�鿡 �׸��� ���� ����̽� ���ؽ�Ʈ ���
    RECT rectangle;         // �簢���� �׸��� ���� RECT ����ü
    rectangle.left = 100;   // �簢���� ���� ��ǥ
    rectangle.top = 100;    // �簢���� ���� ��ǥ
    rectangle.right = rectangle.left + width;  // �簢���� ������ ��ǥ
    rectangle.bottom = rectangle.top + height; // �簢���� �Ʒ��� ��ǥ

    // �簢���� ��ũ������ ä���
    HBRUSH pinkBrush = CreateSolidBrush(RGB(255, 182, 193));  // ��ũ�� �귯�� ���� (RGB ��)
    FillRect(hdc, &rectangle, pinkBrush);  // �簢�� �׸���
    DeleteObject(pinkBrush);  // �귯�� ��ü ����

    ReleaseDC(NULL, hdc);  // ����̽� ���ؽ�Ʈ ����
}

int main() {
    int width, height;
    cout << "�簢���� ���� ���̸� �Է��ϼ���: ";
    cin >> width;
    cout << "�簢���� ���� ���̸� �Է��ϼ���: ";
    cin >> height;

    drawPinkRectangle(width, height);

    return 0;
}

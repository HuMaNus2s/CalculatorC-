// WindowInC++.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "WindowInC++.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
const int WEIGHT = 290;
const int HEIGHT = 500;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    wcscpy_s(szTitle, L"Калькулятор");
    LoadStringW(hInstance, IDC_WINDOWINC, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWINC));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWINC));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWINC);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
HWND hEdit; // Глобальная переменная для текстового поля

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, WEIGHT, HEIGHT, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    // Создание текстового поля для ввода/вывода
    hEdit = CreateWindowW(L"EDIT", nullptr,
        WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT,
        10, 10, 260, 40, hWnd, nullptr, hInstance, nullptr);

    // Создание кнопок
    CreateWindowW(L"BUTTON", L"1", WS_CHILD | WS_VISIBLE, 20, 300, 50, 50, hWnd, (HMENU)1, hInstance, nullptr);
    CreateWindowW(L"BUTTON", L"2", WS_CHILD | WS_VISIBLE, 80, 300, 50, 50, hWnd, (HMENU)2, hInstance, nullptr);
    CreateWindowW(L"BUTTON", L"3", WS_CHILD | WS_VISIBLE, 140, 300, 50, 50, hWnd, (HMENU)3, hInstance, nullptr);
    CreateWindowW(L"BUTTON", L"4", WS_CHILD | WS_VISIBLE, 20, 240, 50, 50, hWnd, (HMENU)4, hInstance, nullptr);
    CreateWindowW(L"BUTTON", L"5", WS_CHILD | WS_VISIBLE, 80, 240, 50, 50, hWnd, (HMENU)5, hInstance, nullptr);
    CreateWindowW(L"BUTTON", L"6", WS_CHILD | WS_VISIBLE, 140, 240, 50, 50, hWnd, (HMENU)6, hInstance, nullptr);
    CreateWindowW(L"BUTTON", L"7", WS_CHILD | WS_VISIBLE, 20, 180, 50, 50, hWnd, (HMENU)7, hInstance, nullptr);
    CreateWindowW(L"BUTTON", L"8", WS_CHILD | WS_VISIBLE, 80, 180, 50, 50, hWnd, (HMENU)8, hInstance, nullptr);
    CreateWindowW(L"BUTTON", L"9", WS_CHILD | WS_VISIBLE, 140, 180, 50, 50, hWnd, (HMENU)9, hInstance, nullptr);
    CreateWindowW(L"BUTTON", L"0", WS_CHILD | WS_VISIBLE, 80, 360, 50, 50, hWnd, (HMENU)100, hInstance, nullptr);
    CreateWindowW(L"BUTTON", L"+", WS_CHILD | WS_VISIBLE, 200, 300, 50, 50, hWnd, (HMENU)101, hInstance, nullptr);
    CreateWindowW(L"BUTTON", L"-", WS_CHILD | WS_VISIBLE, 200, 240, 50, 50, hWnd, (HMENU)102, hInstance, nullptr);
    CreateWindowW(L"BUTTON", L"*", WS_CHILD | WS_VISIBLE, 200, 180, 50, 50, hWnd, (HMENU)103, hInstance, nullptr);
    CreateWindowW(L"BUTTON", L"/", WS_CHILD | WS_VISIBLE, 200, 120, 50, 50, hWnd, (HMENU)104, hInstance, nullptr);
    CreateWindowW(L"BUTTON", L"=", WS_CHILD | WS_VISIBLE, 200, 360, 50, 50, hWnd, (HMENU)202, hInstance, nullptr);
    CreateWindowW(L"BUTTON", L"%", WS_CHILD | WS_VISIBLE, 20, 60, 50, 50, hWnd, (HMENU)108, hInstance, nullptr);

    CreateWindowW(L"BUTTON", L"<x", WS_CHILD | WS_VISIBLE, 200, 60, 50, 50, hWnd, (HMENU)105, hInstance, nullptr);
    CreateWindowW(L"BUTTON", L"C", WS_CHILD | WS_VISIBLE, 140, 60, 50, 50, hWnd, (HMENU)106, hInstance, nullptr);
    CreateWindowW(L"BUTTON", L"CE", WS_CHILD | WS_VISIBLE, 80, 60, 50, 50, hWnd, (HMENU)107, hInstance, nullptr);


    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static double firstNumber = 0;
    static double secondNumber = 0;
    static wchar_t operation = 0;
    wchar_t buffer[256];

    switch (message)
    {
    case WM_COMMAND: {
        // Объявляем wmId вне блока case
        int wmId = LOWORD(wParam);

        // Обработка нажатий на кнопки
        switch (wmId)
        {
        case 1: {
            SendMessage(hEdit, WM_GETTEXT, sizeof(buffer) / sizeof(buffer[0]), reinterpret_cast<LPARAM>(buffer));
            wcscat_s(buffer, L"1");  // Добавление числа 1
            SendMessage(hEdit, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(buffer));
            break;
        }
        case 2: {
            SendMessage(hEdit, WM_GETTEXT, sizeof(buffer) / sizeof(buffer[0]), reinterpret_cast<LPARAM>(buffer));
            wcscat_s(buffer, L"2");  // Добавление числа 2
            SendMessage(hEdit, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(buffer));
            break;
        }
        case 3: {
            SendMessage(hEdit, WM_GETTEXT, sizeof(buffer) / sizeof(buffer[0]), reinterpret_cast<LPARAM>(buffer));
            wcscat_s(buffer, L"3");  // Добавление числа 3
            SendMessage(hEdit, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(buffer));
            break;
        }
        case 4: {
            SendMessage(hEdit, WM_GETTEXT, sizeof(buffer) / sizeof(buffer[0]), reinterpret_cast<LPARAM>(buffer));
            wcscat_s(buffer, L"4"); // Добавление числа 4
            SendMessage(hEdit, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(buffer));
            break; }
        case 5: {
            SendMessage(hEdit, WM_GETTEXT, sizeof(buffer) / sizeof(buffer[0]), reinterpret_cast<LPARAM>(buffer));
            wcscat_s(buffer, L"5"); // Добавление числа 5
            SendMessage(hEdit, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(buffer));
            break; }
        case 6: {
            SendMessage(hEdit, WM_GETTEXT, sizeof(buffer) / sizeof(buffer[0]), reinterpret_cast<LPARAM>(buffer));
            wcscat_s(buffer, L"6"); // Добавление числа 6
            SendMessage(hEdit, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(buffer));
            break; }
        case 7: {
            SendMessage(hEdit, WM_GETTEXT, sizeof(buffer) / sizeof(buffer[0]), reinterpret_cast<LPARAM>(buffer));
            wcscat_s(buffer, L"7"); // Добавление числа 7
            SendMessage(hEdit, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(buffer));
            break; }
        case 8: {
            SendMessage(hEdit, WM_GETTEXT, sizeof(buffer) / sizeof(buffer[0]), reinterpret_cast<LPARAM>(buffer));
            wcscat_s(buffer, L"8"); // Добавление числа 8
            SendMessage(hEdit, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(buffer));
            break; }
        case 9: {
            SendMessage(hEdit, WM_GETTEXT, sizeof(buffer) / sizeof(buffer[0]), reinterpret_cast<LPARAM>(buffer));
            wcscat_s(buffer, L"9"); // Добавление числа 9
            SendMessage(hEdit, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(buffer));
            break; }
        case 100: {
            SendMessage(hEdit, WM_GETTEXT, sizeof(buffer) / sizeof(buffer[0]), reinterpret_cast<LPARAM>(buffer));
            wcscat_s(buffer, L"0"); // Добавление числа 0
            SendMessage(hEdit, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(buffer));
            break; }
        case 101: {
            SendMessage(hEdit, WM_GETTEXT, sizeof(buffer) / sizeof(buffer[0]), reinterpret_cast<LPARAM>(buffer));
            wcscat_s(buffer, L"+");  // Добавление оператора +
            SendMessage(hEdit, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(buffer));
            break;
        }
        case 102: {
            SendMessage(hEdit, WM_GETTEXT, sizeof(buffer) / sizeof(buffer[0]), reinterpret_cast<LPARAM>(buffer));
            wcscat_s(buffer, L"-");  // Добавление оператора -
            SendMessage(hEdit, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(buffer));
            break;
        }
        case 103: {
            SendMessage(hEdit, WM_GETTEXT, sizeof(buffer) / sizeof(buffer[0]), reinterpret_cast<LPARAM>(buffer));
            wcscat_s(buffer, L"*");  // Добавление оператора *
            SendMessage(hEdit, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(buffer));
            break;
        }
        case 104: {
            SendMessage(hEdit, WM_GETTEXT, sizeof(buffer) / sizeof(buffer[0]), reinterpret_cast<LPARAM>(buffer));
            wcscat_s(buffer, L"/");  // Добавление оператора /
            SendMessage(hEdit, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(buffer));
            break;
        }
        case 108: {
            SendMessage(hEdit, WM_GETTEXT, sizeof(buffer) / sizeof(buffer[0]), reinterpret_cast<LPARAM>(buffer));
            wcscat_s(buffer, L"%");  // Добавление оператора %
            SendMessage(hEdit, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(buffer));
            break;
        }
        case 202: { // Нажата кнопка "="
            try {
                wchar_t buffer[256];
                SendMessage(hEdit, WM_GETTEXT, sizeof(buffer) / sizeof(buffer[0]), reinterpret_cast<LPARAM>(buffer));

                std::wstring wExpression(buffer);
                std::string expression(wExpression.begin(), wExpression.end());

                std::vector<std::string> tokens = tokenize(expression);
                std::vector<std::string> rpn = toRPN(tokens);

                double result = evaluateRPN(rpn);

                swprintf_s(buffer, 256, L"%f", result);
                SendMessage(hEdit, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(buffer));
            }
            catch (...) {
                SendMessage(hEdit, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(L"Ошибка"));
            }
            break;
        }
        }
        break;
    }
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        EndPaint(hWnd, &ps);
        break;
    }
    case WM_DESTROY: {
        PostQuitMessage(0);
        break;
    }
    default: {
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    }
    return 0;
}



// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG: {
        return (INT_PTR)TRUE; }

    case WM_COMMAND: {
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break; }
    }
    return (INT_PTR)FALSE;
}

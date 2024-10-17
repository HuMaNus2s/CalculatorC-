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
const int WIDTH = 319;
const int HEIGHT = 490;

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
        CW_USEDEFAULT, 0, WIDTH, HEIGHT, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    // Создание текстового поля для ввода/вывода
    hEdit = CreateWindowW(L"EDIT", nullptr,
        WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT,
        10, 10, 260, 40, hWnd, nullptr, hInstance, nullptr);

    // Создание кнопок
    CreateWindowW(L"BUTTON", L"1", WS_CHILD | WS_VISIBLE, 20,  300, 50, 50, hWnd, (HMENU)1,   hInstance, nullptr);
    CreateWindowW(L"BUTTON", L"2", WS_CHILD | WS_VISIBLE, 80,  300, 50, 50, hWnd, (HMENU)2,   hInstance, nullptr);
    CreateWindowW(L"BUTTON", L"3", WS_CHILD | WS_VISIBLE, 140, 300, 50, 50, hWnd, (HMENU)3,   hInstance, nullptr);
    CreateWindowW(L"BUTTON", L"4", WS_CHILD | WS_VISIBLE, 20,  240, 50, 50, hWnd, (HMENU)4,   hInstance, nullptr);
    CreateWindowW(L"BUTTON", L"5", WS_CHILD | WS_VISIBLE, 80,  240, 50, 50, hWnd, (HMENU)5,   hInstance, nullptr);
    CreateWindowW(L"BUTTON", L"6", WS_CHILD | WS_VISIBLE, 140, 240, 50, 50, hWnd, (HMENU)6,   hInstance, nullptr);
    CreateWindowW(L"BUTTON", L"7", WS_CHILD | WS_VISIBLE, 20,  180, 50, 50, hWnd, (HMENU)7,   hInstance, nullptr);
    CreateWindowW(L"BUTTON", L"8", WS_CHILD | WS_VISIBLE, 80,  180, 50, 50, hWnd, (HMENU)8,   hInstance, nullptr);
    CreateWindowW(L"BUTTON", L"9", WS_CHILD | WS_VISIBLE, 140, 180, 50, 50, hWnd, (HMENU)9,   hInstance, nullptr);
    CreateWindowW(L"BUTTON", L"0", WS_CHILD | WS_VISIBLE, 80,  360, 50, 50, hWnd, (HMENU)100, hInstance, nullptr);
    CreateWindowW(L"BUTTON", L"+", WS_CHILD | WS_VISIBLE, 200, 300, 50, 50, hWnd, (HMENU)101, hInstance, nullptr);
    CreateWindowW(L"BUTTON", L"-", WS_CHILD | WS_VISIBLE, 200, 240, 50, 50, hWnd, (HMENU)102, hInstance, nullptr);
    CreateWindowW(L"BUTTON", L"*", WS_CHILD | WS_VISIBLE, 200, 180, 50, 50, hWnd, (HMENU)103, hInstance, nullptr);
    CreateWindowW(L"BUTTON", L"÷", WS_CHILD | WS_VISIBLE, 200, 120, 50, 50, hWnd, (HMENU)104, hInstance, nullptr);
    CreateWindowW(L"BUTTON", L"⌫",WS_CHILD | WS_VISIBLE, 200, 60,  50, 50, hWnd, (HMENU)105, hInstance, nullptr);
    CreateWindowW(L"BUTTON", L"C", WS_CHILD | WS_VISIBLE, 140, 60,  50, 50, hWnd, (HMENU)106, hInstance, nullptr);
    CreateWindowW(L"BUTTON", L"CE",WS_CHILD | WS_VISIBLE, 80,  60,  50, 50, hWnd, (HMENU)107, hInstance, nullptr);
    CreateWindowW(L"BUTTON", L"%", WS_CHILD | WS_VISIBLE, 20,  60,  50, 50, hWnd, (HMENU)108, hInstance, nullptr);
    CreateWindowW(L"BUTTON", L"⅟x", WS_CHILD | WS_VISIBLE, 20,  120,  50, 50, hWnd, (HMENU)109, hInstance, nullptr);
    CreateWindowW(L"BUTTON", L"x²", WS_CHILD | WS_VISIBLE, 80,  120,  50, 50, hWnd, (HMENU)110, hInstance, nullptr);
    CreateWindowW(L"BUTTON", L"²√x", WS_CHILD | WS_VISIBLE, 140,  120,  50, 50, hWnd, (HMENU)111, hInstance, nullptr);
    CreateWindowW(L"BUTTON", L".", WS_CHILD | WS_VISIBLE, 140, 360, 50, 50, hWnd, (HMENU)112, hInstance, nullptr);
    CreateWindowW(L"BUTTON", L"+/-", WS_CHILD | WS_VISIBLE, 20, 360, 50, 50, hWnd, (HMENU)113, hInstance, nullptr);
    CreateWindowW(L"BUTTON", L"=", WS_CHILD | WS_VISIBLE, 200, 360, 50, 50, hWnd, (HMENU)202, hInstance, nullptr);


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
double Position_ratio_size(double ratio, double size, int px) { // Функция для расположения кнопок с указанием размера можно применять для width и height
    double result;
    if (size > 0) {
        result = (ratio * size) + px;
    }
    else {
        result = px;
    }
    return result;  // Возвращаем результат
}

// Функция для преобразования wchar_t в std::string
std::string convertWCharToString(const wchar_t* wstr) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    return converter.to_bytes(wstr);
}

// Функция для преобразования std::string в wchar_t
std::wstring convertStringToWChar(const std::string& str) {
    return std::wstring(str.begin(), str.end());
}

// Функция для обработки нажатия кнопки "1/"
void handleReciprocalButton(HWND hEdit) {
    // Получаем текущее выражение из текстового поля
    wchar_t buffer[256];
    SendMessage(hEdit, WM_GETTEXT, sizeof(buffer) / sizeof(buffer[0]), reinterpret_cast<LPARAM>(buffer));

    std::wstring wstr(buffer); // используем wstring
    std::string expression(wstr.begin(), wstr.end()); // преобразуем в std::string

    // Находим последнее введенное число
    std::string lastNumber;
    size_t pos = expression.find_last_of("0123456789");

    // Считываем последнее число, если оно есть
    while (pos != std::string::npos && (isdigit(expression[pos]) || expression[pos] == '.')) {
        lastNumber = expression[pos] + lastNumber;
        pos--;
    }

    if (!lastNumber.empty()) {
        // Заменяем последнее введенное число на "1/число"
        expression.replace(expression.find(lastNumber), lastNumber.length(), "1/" + lastNumber);
    }

    // Устанавливаем обновленное выражение обратно в текстовое поле
    SendMessage(hEdit, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(std::wstring(expression.begin(), expression.end()).c_str()));
}

// Преобразование std::wstring в UTF-8
std::string wstringToUtf8(const std::wstring& wstr) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    return converter.to_bytes(wstr);
}

// Преобразование UTF-8 в std::wstring
std::wstring utf8ToWstring(const std::string& str) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    return converter.from_bytes(str);
}

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
        case 105: {
            SendMessage(hEdit, WM_GETTEXT, sizeof(buffer) / sizeof(buffer[0]), reinterpret_cast<LPARAM>(buffer));
            wcscat_s(buffer, L"<=");  // Добавление оператора /
            SendMessage(hEdit, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(buffer));
            break;
        }
        case 106: {
            SendMessage(hEdit, WM_GETTEXT, sizeof(buffer) / sizeof(buffer[0]), reinterpret_cast<LPARAM>(buffer));
            wcscat_s(buffer, L"C");  // Добавление оператора /
            SendMessage(hEdit, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(buffer));
            break;
        }
        case 107: {
            SendMessage(hEdit, WM_GETTEXT, sizeof(buffer) / sizeof(buffer[0]), reinterpret_cast<LPARAM>(buffer));
            wcscat_s(buffer, L"CE");  // Добавление оператора /
            SendMessage(hEdit, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(buffer));
            break;
        }
        case 108: {
            SendMessage(hEdit, WM_GETTEXT, sizeof(buffer) / sizeof(buffer[0]), reinterpret_cast<LPARAM>(buffer));
            wcscat_s(buffer, L"%");  // Добавление оператора %
            SendMessage(hEdit, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(buffer));
            break;
        }
        case 109: {  // Код для кнопки "1/"
            handleReciprocalButton(hEdit);
            break;
        }
        case 110: {
            SendMessage(hEdit, WM_GETTEXT, sizeof(buffer) / sizeof(buffer[0]), reinterpret_cast<LPARAM>(buffer));
            wcscat_s(buffer, L"²");  // Добавление оператора %
            SendMessage(hEdit, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(buffer));
            break;
        }
        case 111: {
            SendMessage(hEdit, WM_GETTEXT, sizeof(buffer) / sizeof(buffer[0]), reinterpret_cast<LPARAM>(buffer));
            wcscat_s(buffer, L"2<");  // Добавление оператора %
            SendMessage(hEdit, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(buffer));
            break;
        }
        case 112: {
            SendMessage(hEdit, WM_GETTEXT, sizeof(buffer) / sizeof(buffer[0]), reinterpret_cast<LPARAM>(buffer));
            wcscat_s(buffer, L".");  // Добавление оператора %
            SendMessage(hEdit, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(buffer));
            break;
        }
        case 113: {
            SendMessage(hEdit, WM_GETTEXT, sizeof(buffer) / sizeof(buffer[0]), reinterpret_cast<LPARAM>(buffer));
            wcscat_s(buffer, L"+/-");  // Добавление оператора %
            SendMessage(hEdit, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(buffer));
            break;
        }
        case 202: { // Нажата кнопка "="
            try {
                // Получаем текущее выражение как широкую строку (Unicode)
                wchar_t buffer[256];
                SendMessageW(hEdit, WM_GETTEXT, sizeof(buffer) / sizeof(buffer[0]), reinterpret_cast<LPARAM>(buffer));

                std::wstring wstr(buffer);

                // Преобразуем широкую строку в строку UTF-8
                std::string expression = wstringToUtf8(wstr);

                // Токенизация выражения
                std::vector<std::string> tokens = tokenize(expression);

                // Преобразование в RPN
                std::vector<std::string> rpn = toRPN(tokens);

                // Вычисление результата
                double result = evaluateRPN(rpn);

                // Отображение результата в вашем окне (с преобразованием обратно в wide-строку)
                std::string resultStr = std::to_string(result);
                SendMessageW(hEdit, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(utf8ToWstring(resultStr).c_str()));
            }
            catch (...) {
                SendMessageW(hEdit, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(L"Ошибка"));
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
    case WM_SIZE: {
        // Получаем новый размер окна
        int width = LOWORD(lParam);
        int height = HIWORD(lParam);
        int WIDTH_RATIO = width - (WIDTH * 0.72);
        int HEIGHT_RATIO = height - (HEIGHT * 0.765);

        // Изменяем размер и расположение элементов, если нужно
        MoveWindow(hEdit, 0, 0, width, height - 370, TRUE);

        // Например, можно изменять кнопки в зависимости от размера окна
        MoveWindow(GetDlgItem(hWnd, 1),   Position_ratio_size(0, 74, 4), Position_ratio_size(5, 60, 6), WIDTH_RATIO, HEIGHT_RATIO, TRUE);  // Пример для кнопки 1
        MoveWindow(GetDlgItem(hWnd, 4),   Position_ratio_size(0, 74, 4), Position_ratio_size(4, 60, 6), WIDTH_RATIO, HEIGHT_RATIO, TRUE);  // Пример для кнопки 4
        MoveWindow(GetDlgItem(hWnd, 7),   Position_ratio_size(0, 74, 4), Position_ratio_size(3, 60, 6), WIDTH_RATIO, HEIGHT_RATIO, TRUE);  // Пример для кнопки 7
        MoveWindow(GetDlgItem(hWnd, 108), Position_ratio_size(0, 74, 4), Position_ratio_size(1, 60, 6),  WIDTH_RATIO, HEIGHT_RATIO, TRUE);  // Пример для кнопки %
        MoveWindow(GetDlgItem(hWnd, 109), Position_ratio_size(0, 74, 4), Position_ratio_size(2, 60, 6), WIDTH_RATIO, HEIGHT_RATIO, TRUE);  // Пример для кнопки ⅟x
        MoveWindow(GetDlgItem(hWnd, 113), Position_ratio_size(0, 74, 4), Position_ratio_size(6, 60, 6), WIDTH_RATIO, HEIGHT_RATIO, TRUE);  // Пример для кнопки +/-
        MoveWindow(GetDlgItem(hWnd, 2),   Position_ratio_size(1, 74, 4), Position_ratio_size(5, 60, 6), WIDTH_RATIO, HEIGHT_RATIO, TRUE);  // Пример для кнопки 2
        MoveWindow(GetDlgItem(hWnd, 5),   Position_ratio_size(1, 74, 4), Position_ratio_size(4, 60, 6), WIDTH_RATIO, HEIGHT_RATIO, TRUE);  // Пример для кнопки 5
        MoveWindow(GetDlgItem(hWnd, 8),   Position_ratio_size(1, 74, 4), Position_ratio_size(3, 60, 6), WIDTH_RATIO, HEIGHT_RATIO, TRUE);  // Пример для кнопки 8
        MoveWindow(GetDlgItem(hWnd, 100), Position_ratio_size(1, 74, 4), Position_ratio_size(6, 60, 6), WIDTH_RATIO, HEIGHT_RATIO, TRUE);  // Пример для кнопки 0
        MoveWindow(GetDlgItem(hWnd, 107), Position_ratio_size(1, 74, 4), Position_ratio_size(1, 60, 6),  WIDTH_RATIO, HEIGHT_RATIO, TRUE);  // Пример для кнопки CE
        MoveWindow(GetDlgItem(hWnd, 110), Position_ratio_size(1, 74, 4), Position_ratio_size(2, 60, 6), WIDTH_RATIO, HEIGHT_RATIO, TRUE);  // Пример для кнопки x²
        MoveWindow(GetDlgItem(hWnd, 3),   Position_ratio_size(2, 74, 4), Position_ratio_size(5, 60, 6), WIDTH_RATIO, HEIGHT_RATIO, TRUE);  // Пример для кнопки 3
        MoveWindow(GetDlgItem(hWnd, 6),   Position_ratio_size(2, 74, 4), Position_ratio_size(4, 60, 6), WIDTH_RATIO, HEIGHT_RATIO, TRUE);  // Пример для кнопки 6
        MoveWindow(GetDlgItem(hWnd, 9),   Position_ratio_size(2, 74, 4), Position_ratio_size(3, 60, 6), WIDTH_RATIO, HEIGHT_RATIO, TRUE);  // Пример для кнопки 9
        MoveWindow(GetDlgItem(hWnd, 106), Position_ratio_size(2, 74, 4), Position_ratio_size(1, 60, 6),  WIDTH_RATIO, HEIGHT_RATIO, TRUE);  // Пример для кнопки C
        MoveWindow(GetDlgItem(hWnd, 111), Position_ratio_size(2, 74, 4), Position_ratio_size(2, 60, 6), WIDTH_RATIO, HEIGHT_RATIO, TRUE);  // Пример для кнопки ²√x
        MoveWindow(GetDlgItem(hWnd, 112), Position_ratio_size(2, 74, 4), Position_ratio_size(6, 60, 6), WIDTH_RATIO, HEIGHT_RATIO, TRUE);  // Пример для кнопки .
        MoveWindow(GetDlgItem(hWnd, 101), Position_ratio_size(3, 74, 4), Position_ratio_size(5, 60, 6), WIDTH_RATIO, HEIGHT_RATIO, TRUE);  // Пример для кнопки +
        MoveWindow(GetDlgItem(hWnd, 102), Position_ratio_size(3, 74, 4), Position_ratio_size(4, 60, 6), WIDTH_RATIO, HEIGHT_RATIO, TRUE);  // Пример для кнопки -
        MoveWindow(GetDlgItem(hWnd, 103), Position_ratio_size(3, 74, 4), Position_ratio_size(3, 60, 6), WIDTH_RATIO, HEIGHT_RATIO, TRUE);  // Пример для кнопки *
        MoveWindow(GetDlgItem(hWnd, 104), Position_ratio_size(3, 74, 4), Position_ratio_size(2, 60, 6), WIDTH_RATIO, HEIGHT_RATIO, TRUE);  // Пример для кнопки /
        MoveWindow(GetDlgItem(hWnd, 105), Position_ratio_size(3, 74, 4), Position_ratio_size(1, 60, 6),  WIDTH_RATIO, HEIGHT_RATIO, TRUE);  // Пример для кнопки ⌫
        MoveWindow(GetDlgItem(hWnd, 202), Position_ratio_size(3, 74, 4), Position_ratio_size(6, 60, 6), WIDTH_RATIO, HEIGHT_RATIO, TRUE);  // Пример для кнопки =
        
        // Аналогично для других кнопок

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

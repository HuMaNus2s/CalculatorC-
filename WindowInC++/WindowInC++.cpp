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
    hEdit = CreateWindowW(L"EDIT", L"0",
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
    CreateWindowW(L"BUTTON", L"x^", WS_CHILD | WS_VISIBLE, 80,  120,  50, 50, hWnd, (HMENU)110, hInstance, nullptr);
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
double Position_ratio_size(double ratio, double size, int px, double offset = 0) {
    if (size > 0) {
        return (ratio * size) + px + offset;  // добавляем отступ
    }
    return px + offset;  // добавляем отступ
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
void handleReciprocalButton(HWND hEdit, const std::string& str) {
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
        expression.replace(expression.find(lastNumber), lastNumber.length(), str + lastNumber);
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
            std::wstring currentText(buffer);
            // Проверяем, если текущее содержимое - это "0"
            if (currentText == L"0") { currentText = L"1"; }
            else { currentText += L"1"; }
            // Устанавливаем обновленный текст обратно в поле редактирования
            SendMessage(hEdit, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(currentText.c_str()));
            break; }
        case 2: {
            SendMessage(hEdit, WM_GETTEXT, sizeof(buffer) / sizeof(buffer[0]), reinterpret_cast<LPARAM>(buffer));
            std::wstring currentText(buffer);
            // Проверяем, если текущее содержимое - это "0"
            if (currentText == L"0") { currentText = L"2"; }
            else { currentText += L"2"; }
            // Устанавливаем обновленный текст обратно в поле редактирования
            SendMessage(hEdit, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(currentText.c_str()));
            break; }
        case 3: {
            SendMessage(hEdit, WM_GETTEXT, sizeof(buffer) / sizeof(buffer[0]), reinterpret_cast<LPARAM>(buffer));
            std::wstring currentText(buffer);
            // Проверяем, если текущее содержимое - это "0"
            if (currentText == L"0") { currentText = L"3"; }
            else { currentText += L"3"; }
            // Устанавливаем обновленный текст обратно в поле редактирования
            SendMessage(hEdit, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(currentText.c_str()));
            break; }
        case 4: {
            SendMessage(hEdit, WM_GETTEXT, sizeof(buffer) / sizeof(buffer[0]), reinterpret_cast<LPARAM>(buffer));
            std::wstring currentText(buffer);
            // Проверяем, если текущее содержимое - это "0"
            if (currentText == L"0") { currentText = L"4"; }
            else { currentText += L"4"; }
            // Устанавливаем обновленный текст обратно в поле редактирования
            SendMessage(hEdit, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(currentText.c_str()));
            break; }
        case 5: {
            SendMessage(hEdit, WM_GETTEXT, sizeof(buffer) / sizeof(buffer[0]), reinterpret_cast<LPARAM>(buffer));
            std::wstring currentText(buffer);
            // Проверяем, если текущее содержимое - это "0"
            if (currentText == L"0") { currentText = L"5"; }
            else { currentText += L"5"; }
            // Устанавливаем обновленный текст обратно в поле редактирования
            SendMessage(hEdit, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(currentText.c_str()));
            break; }
        case 6: {
            SendMessage(hEdit, WM_GETTEXT, sizeof(buffer) / sizeof(buffer[0]), reinterpret_cast<LPARAM>(buffer));
            std::wstring currentText(buffer);
            // Проверяем, если текущее содержимое - это "0"
            if (currentText == L"0") { currentText = L"6"; }
            else { currentText += L"6"; }
            // Устанавливаем обновленный текст обратно в поле редактирования
            SendMessage(hEdit, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(currentText.c_str()));
            break; }
        case 7: {
            SendMessage(hEdit, WM_GETTEXT, sizeof(buffer) / sizeof(buffer[0]), reinterpret_cast<LPARAM>(buffer));
            std::wstring currentText(buffer);
            // Проверяем, если текущее содержимое - это "0"
            if (currentText == L"0") { currentText = L"7"; }
            else { currentText += L"7"; }
            // Устанавливаем обновленный текст обратно в поле редактирования
            SendMessage(hEdit, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(currentText.c_str()));
            break; }
        case 8: {
            SendMessage(hEdit, WM_GETTEXT, sizeof(buffer) / sizeof(buffer[0]), reinterpret_cast<LPARAM>(buffer));
            std::wstring currentText(buffer);
            // Проверяем, если текущее содержимое - это "0"
            if (currentText == L"0") { currentText = L"8"; }
            else { currentText += L"8"; }
            // Устанавливаем обновленный текст обратно в поле редактирования
            SendMessage(hEdit, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(currentText.c_str()));
            break; }
        case 9: {
            SendMessage(hEdit, WM_GETTEXT, sizeof(buffer) / sizeof(buffer[0]), reinterpret_cast<LPARAM>(buffer));
            std::wstring currentText(buffer);
            // Проверяем, если текущее содержимое - это "0"
            if (currentText == L"0") { currentText = L"9"; }
            else { currentText += L"9"; }
            // Устанавливаем обновленный текст обратно в поле редактирования
            SendMessage(hEdit, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(currentText.c_str()));
            break; }
        case 100: {
            SendMessage(hEdit, WM_GETTEXT, sizeof(buffer) / sizeof(buffer[0]), reinterpret_cast<LPARAM>(buffer));
            std::wstring currentText(buffer);
            if (currentText == L"0") { currentText = L"0"; }
            else { currentText += L"0"; }
            SendMessage(hEdit, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(currentText.c_str()));
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
            wchar_t buffer[256];
            // Получаем текущее содержимое поля редактирования
            SendMessage(hEdit, WM_GETTEXT, sizeof(buffer) / sizeof(buffer[0]), reinterpret_cast<LPARAM>(buffer));
            std::wstring currentText(buffer);

            // Проверяем, что строка не пустая
            if (!currentText.empty()) {
                currentText.pop_back();
                if (currentText.empty())  currentText = L"0";
            }
            else {
                currentText = L"0";
            }
            SendMessage(hEdit, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(currentText.c_str()));
            break;
        }


        case 106: {
            SendMessage(hEdit, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(L"0"));
            break;
        }
        case 107: {
            SendMessage(hEdit, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(L"0"));
            break;
        }
        case 108: {
            SendMessage(hEdit, WM_GETTEXT, sizeof(buffer) / sizeof(buffer[0]), reinterpret_cast<LPARAM>(buffer));
            wcscat_s(buffer, L"%");  // Добавление оператора %
            SendMessage(hEdit, WM_SETTEXT, 0, reinterpret_cast<LPARAM>(buffer));
            break;
        }
        case 109: {  // Код для кнопки "1/"
            handleReciprocalButton(hEdit, "1/");
            break;
        }
        case 110: {
            SendMessage(hEdit, WM_GETTEXT, sizeof(buffer) / sizeof(buffer[0]), reinterpret_cast<LPARAM>(buffer));
            wcscat_s(buffer, L"^");  // Добавление оператора ^2
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
            handleReciprocalButton(hEdit, "-");
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
        // Массив идентификаторов кнопок
        int buttonIDs[] = { 1, 4, 7, 108, 109, 113, 2, 5, 8, 100, 107, 110, 3, 6, 9, 106, 111, 112, 101, 102, 103, 104, 105, 202 };

        // Размеры кнопок и отступы
        const int buttonWidth = 74;
        const int buttonHeight = 60;
        const int horizontalSpacing = 4;  // Отступ между кнопками по горизонтали
        const int verticalSpacing = 6;    // Отступ между кнопками по вертикали
        const int rows = 5;                // Количество рядов
        const int columns = 4;             // Количество колонок

        // Позиционирование кнопок
        for (int i = 0; i < sizeof(buttonIDs) / sizeof(buttonIDs[0]); ++i) {
            int row = i / columns;  // Номер ряда
            int column = i % columns;  // Номер колонки

            // Вычисляем позицию
            int posX = Position_ratio_size(column, buttonWidth, 4, horizontalSpacing * column);
            int posY = Position_ratio_size(row, buttonHeight, 6, verticalSpacing * row);

            // Перемещение кнопки
            MoveWindow(GetDlgItem(hWnd, buttonIDs[i]), posX, posY, buttonWidth, buttonHeight, TRUE);
        }


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

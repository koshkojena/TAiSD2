#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath> 
#include <algorithm>
#include <windows.h>
#include <cctype>
using namespace std;

void fillArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Введите " << i + 1 << " элемент массива: ";
        while (!(cin >> array[i]))
        {
            cout << "Ошибка! Введите целое число: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}
void fillArrayRandom(int array[], int size)
{
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 201 - 100;
    }
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}
void Sort(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (abs(array[i]) % 2 == 0) // Проверяем, что число четное
        {
            for (int j = i + 1; j < size; j++)
            {
                if (abs(array[j]) % 2 == 0) // Проверяем, что следующий элемент также четный
                {
                    if (array[j] > array[i]) // Если следующий элемент больше, меняем их местами
                    {
                        int temp = array[i];
                        array[i] = array[j];
                        array[j] = temp;
                    }
                }
            }
        }
    }
}
void Sentences(string& text)
{
    string result;
    bool odd = true;
    string word;
    for (char c : text)
    {
        if (c == '.' || c == '!' || c == '?')
        {
            if (odd)
            {
                reverse(word.begin(), word.end());
            }
            result += word + c + " ";
            word = "";
            odd = !odd;
        }
        else
        {
            word += c;
        }
    }
    text = result;
}
int main()
{
    setlocale(0, "");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int choice;
    do
    {
    l:cout << "Выберите тип данных для обработки:" << endl;
        cout << "1 - Массив." << endl;
        cout << "2 - Строка." << endl;
        cout << "3 - Выйти." << endl;
        if (!(cin >> choice))
        {
            cout << "Ошибка! Введите число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            goto l;
        }
        if (choice == 1)
        {
            int vibor;
            int size;
            int* array = nullptr;
            while (true)
            {
             x:   cout << "Выберите действие:" << endl;
                cout << "1 - Создать массив." << endl;
                cout << "2 - Вывести массив." << endl;
                cout << "3 - Отсортировать по убыванию только четные элементы массива." << endl;
                cout << "4 - Выйти в главное меню." << endl;
                if (!(cin >> vibor))
                {
                    cout << "Ошибка! Введите число." << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    goto x;
                }
                switch (vibor)
                {
                case 1:
                {
                    int fillChoice;
                f:    cout << "Каким способом будет создан массив?" << endl;
                    cout << "1 - Ввод с клавиатуры." << endl;
                    cout << "2 - Заполнение случайными числами." << endl;
                    cout << "3 - Выйти в меню создания массива." << endl;
                    if (!(cin >> fillChoice))
                    {
                        cout << "Ошибка! Введите число больше 0." << endl;
                        cin.clear();
                        cin.ignore(10000, '\n');
                        goto f;
                    }
                    if (fillChoice == 1)
                    {
                    e1:    cout << "Введите размер массива: " << endl;
                        if (!(cin >> size) || (size <= 0))
                        {
                            cout << "Ошибка! Размер массива должен быть положительным." << endl;
                            cin.clear();
                            cin.ignore(10000, '\n');
                            goto e1;
                        }
                        array = new int[size];
                        fillArray(array, size);
                        cout << "Массив создан" << endl;
                    }
                    else if (fillChoice == 2)
                    {
                    e:    cout << "Введите размер массива: " << endl;
                        if (!(cin >> size) || (size <= 0))
                        {
                            cout << "Ошибка! Размер массива должен быть положительным." << endl;
                            cin.clear();
                            cin.ignore(10000, '\n');
                            goto e;
                        }
                        array = new int[size];
                        fillArrayRandom(array, size);
                        cout << "Массив создан" << endl;
                    }
                    else if (fillChoice == 3)
                    {
                        continue;
                    }
                    break;
                }
                case 2:
                    if (array != nullptr) // Проверяем, что массив был создан
                    {
                        cout << "Исходный массив: " << endl;
                        printArray(array, size);
                    }
                    else
                    {
                        cout << "Массив не создан." << endl;
                    }
                    break;
                case 3:
                    if (array != nullptr) // Проверяем, что массив был создан
                    {
                        bool k = false;
                        for (int i = 0; i < size; i++)
                        {
                            if (abs(array[i]) % 2 == 0) // Проверяем, что число четное
                            {
                                k = true;
                                break;
                            }
                        }
                        if (k)
                        {
                            Sort(array, size);
                            cout << "Отсортированный по убыванию массив четных элементов:" << endl;
                            printArray(array, size);
                        }
                        else
                        {
                            cout << "В массиве нет четных чисел!" << endl;
                        }
                    }
                    else
                    {
                        cout << "Массив не создан." << endl;
                    }
                    break;
                case 4:
                {
                    // Освобождаем память перед выходом
                    delete[] array;
                    goto l;
                }
                break;
                default:
                {
                    cout << "Неизвестная операция!" << endl;
                    break;
                }
                }
            }
        }
        else if (choice == 2)
        {
            int choe = 0;
            string text;
            do
            {
                int choe;
            k:
                cout << "Что будем делать?:" << endl;
                cout << "1 - создать строку" << endl;
                cout << "2 - перевернуть нечётные предложения" << endl;
                cout << "3 - вывести строку" << endl;
                cout << "4 - выйти в главное меню" << endl;
               p: cout << "Выберите пункт меню: ";
                if (!(cin >> choe))
                {
                    cout << "Ошибка! Введите число больше 0." << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    goto p;
                }
                // Очистка буфера ввода
                cin.ignore();
                if (choe == 1)
                {
                    int vibr;
                y:    cout << "Выберите какую строку будем использовать." << endl;
                    cout << "1 - Введенную вами строку" << endl;
                    cout << "2 - Созданную строку" << endl;
                    cout << "3 - Выйти в меню работы со строкой." << endl;
                    if (!(cin >> vibr))
                    {
                        cout << "Ошибка! Введите число." << endl;
                        cin.clear();
                        cin.ignore(10000, '\n');
                        goto y;
                    }
                    cin.ignore(); // Очистка буфера ввода
                    if (vibr == 1)
                    {
                        cout << "Введите строку: ";
                        getline(cin, text);
                    }
                    else if (vibr == 2)
                    {
                        text = "Привет! Как твои дела? У меня тоже всё хорошо, спасибо.";
                    }
                    else if (vibr == 3)
                    {
                        goto k;
                    }
                }
                else if (choe == 2)
                {
                    if (!text.empty())
                    {
                        Sentences(text);
                        cout << "Результат: " << text << endl;
                    }
                    else
                    {
                        cout << "Строка не создана" << endl;
                    }
                }
                else if (choe == 3)
                {
                    if (!text.empty())
                    {
                        cout << "Строка: " << text << endl;

                    }
                    else
                    {
                        cout << "Строка не создана" << endl;
                    }
                }
                else if(choe == 4)
                {
                    goto l;
                }
            } while (choe != 4);
        }
        else if (choice == 3)
        {
            cout << "До новых встреч!" << endl;
            return 0;
        }
        else
        {
            cout << "Недопустимый выбор." << endl;
        }
    } while (choice != 3);
    return 0;
}


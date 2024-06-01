// zd_passwords.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Функция для генерации случайного пароля заданной длины и сложности
string generatePassword(int length, bool includeUppercase, bool includeNumbers) {
    // Создаем строку для хранения символов пароля
    string password = "";
    string generatedPassword;
    // Строки символов для различных компонент пароля
    string lowercaseLetters = "abcdefghijklmnopqrstuvwxyz"; 
    string uppercaseLetters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string numbers = "0123456789"; 
    // Если включены заглавные буквы, добавляем их к списку символов
    if (includeUppercase) 
        password += uppercaseLetters; 
    // Если включены цифры, добавляем их к списку символов
    if (includeNumbers) 
        password += numbers; 
    // Добавляем оставшиеся символы (маленькие буквы) к списку символов
    password += lowercaseLetters;
    // Инициализируем генератор случайных чисел текущим временем
    srand(time(0));
    // Генерируем случайный пароль заданной длины
    for (int i = 0; i < length; ++i) 
    {
        int randomIndex = rand() % password.length();
        generatedPassword += password[randomIndex]; // Добавляем случайный символ к паролю
    }
    return generatedPassword;
}

int main() 
{
    setlocale(0, "");
    // Длина пароля и настройки сложности
    int length, choice;
    bool includeUppercase;
    bool includeNumbers;
    string password;
    // Генерация и вывод пароля
    do 
    {
        cout << "Хотите сгенерировать новый пароль? (1 - да, 0 - нет): ";
        cin >> choice;
        switch (choice) 
        {
        case 1:
            cout << "Введите длину пароля: ";
            cin >> length;
            cout << "Включить заглавные буквы? (1 - да, 0 - нет): ";
            cin >> includeUppercase;
            cout << "Включить цифры? (1 - да, 0 - нет): ";
            cin >> includeNumbers;
            password = generatePassword(length, includeUppercase, includeNumbers);
            cout << "Сгенерированный пароль: " << password << endl;
            break;
        case 0:
            cout << "Выход." << endl;
            break;
        default:
            cout << "Некорректный ввод. Повторите выбор." << endl;
        }
    } while (choice != 0);
    return 0;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

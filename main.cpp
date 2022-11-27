#include <iostream>

// Функция выделения левой части адреса
std::string left_part (std::string str)
{
    std::string left;
    for (int i=0; i<str.length(); i++)
    {
        if (str[i] == '@')
        {
            return left;
        }
        else
        {
            left += str[i];
        }
    }
    return str;
}

// Функция выделения правой части адреса
std::string right_part (std::string str)
{
    std::string left = left_part(str);
    std::string right;
    for (int i=left.length()+1; i<str.length(); i++)
    {
        right += str[i];
    }
    return right;
}

// Функция проверки совпадения длины строк (проверка наличия знака '@')
bool check_dog (std::string str1, std::string str2)
{
    if (str1.length() == str2.length()) return true;
    else return false;
}

// Функция проверки длины строки
bool length_incorrect (std::string str, int l)
{
    if (str.length()>0 && str.length() <= l) return false;
    else return true;
}

// Функция проверки правильности использования точек
bool dot_incorrect (std::string str)
{
    int doubleDot = int (str.find(".."));
    if (str[0] == '.' || str[str.length()-1] == '.' || doubleDot >= 0) return true;
    else return false;
}

// Функция проверки строки по словарю
bool find_bad_char (std::string str, std::string dictionary)
{
    for (int i=0; i<str.length(); i++)
    {
        int goodChar = dictionary.find(str[i]);
        if (goodChar<0) return true;
    }
    return false;
}

int main()
{
    while (true)
    {
        // Ввод строки с адресом электронной почты
        std::string email;
        std::cout << "Enter your email address: ";
        std::cin >> email;

        std::string left, right;
        left = left_part(email);
        right = right_part(email);

        // Выход из цикла
        if (left == "exit" && right.length() == 0)
        {
            std::cout << "Program stopped!" << std::endl;
            break;
        }

        // Задание строк словарей для левой и правой частей
        std::string dictionary_left = "-.0123456789AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz"
                                      "!#$%&`*+-/=?^_'{|}~";
        std::string dictionary_right = "-.0123456789AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";

        // Вывод результата проверки
        if (check_dog(left, email) || length_incorrect(left, 64) || length_incorrect(right, 63) ||
                dot_incorrect(left) || dot_incorrect(right) || find_bad_char(left,dictionary_left) ||
                find_bad_char(right,dictionary_right))
        {
            std::cout << "Your email address is incorrect!" << std::endl;
        }
        else
        {
            std::cout << "Your email address is correct." << std::endl;
        }

    }

    return 0;
}

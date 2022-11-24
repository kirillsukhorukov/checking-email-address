#include <iostream>

// Функция выделения левой части адреса
std::string leftpart (std::string str)
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
std::string rightpart (std::string str)
{
    std::string left = leftpart(str);
    std::string right;
    for (int i=left.length()+1; i<str.length(); i++)
    {
        right += str[i];
    }
    return right;
}

// Функция проверки совпадения длины строк (проверка наличия знака '@')
bool equallength (std::string str1, std::string str2)
{
    bool equal = (str1.length() == str2.length()) ? true : false;
    return equal;
}

// Функция проверки длины строки
bool lengincorrect (std::string str, int l)
{
    bool incorrect = (str.length()>0 && str.length() <= l) ? false : true;
    return incorrect;
}

// Функция проверки правильности использования точек
bool dotincorrect (std::string str)
{
    int doubleDot = int (str.find(".."));
    bool incorrect = (str[0] == '.' || str[str.length()-1] == '.' || doubleDot >= 0) ? true: false;
    return incorrect;
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
        left = leftpart(email);
        right = rightpart(email);

        std::cout << "Left part your email address: " << left << std::endl;
        std::cout << "Right part your email address: " << right << std::endl;
        std::cout << int (left.find("..")) << std::endl;
        std::cout << int (right.find("..")) << std::endl;
        // Вывод результата проверки
        if (equallength(left, email) || lengincorrect(left, 64) || lengincorrect(right, 63) ||
            dotincorrect(left) || dotincorrect(right))
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

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>

template <typename F>
void forEach(char** strs, int n, F fn)
{
    for (int i = 0; i < n; ++i) {
        fn(strs[i]);
    }
}

int findIndex(char** items, int n, const char* item)
{
    for (int i = 0; i < n; i++)
    {
        if (!strcmp(items[i], item))
        {
            return i;
        }
    }
    return -1;
}

void append(char**& arr, int n, const char* item) {
    char** newArr = new char* [n + 1];
    for (int i = 0; i < n; ++i) {
        newArr[i] = arr[i];
    }
    char* newItem = new char[strlen(item) + 1];
    std::strcpy(newItem, item);
    newArr[n] = newItem;

    delete[] arr;
    arr = newArr;
}

void remove(char**& arr, int n, const int index)
{
    char** newArr = new char*[n-1];
    for (int i{}; i < index; i++)
        newArr[i] = arr[i];
    for (int i{ index + 1 }; i < n; i++)
        newArr[i - 1] = arr[i];

    delete[] arr;
    arr = newArr;

}

void edit(char**& arr, int n, const int index, char* item)
{
    char** newArr = new char* [n];
    for (int i{}; i < index; i++)
        newArr[i] = arr[i];
    newArr[index] = item;
    for (int i{ index + 1 }; i < n; i++)
        newArr[i] = arr[i];

    delete[] arr;
    arr = newArr;
}

void print(const char* s) {
    std::cout << s << '\n';
}

int main()
{
    char** ingredients{};
    int n{};

    std::ifstream fin("pantry.txt");
    char buffer[100]{};
    while (fin.getline(buffer, 99)) {
        append(ingredients, n++, buffer);
    }

    int option{};

    do
    {
        std::cout << "0: Quit\n";
        std::cout << "1: Add Ingredient\n";
        std::cout << "2: Remove Ingredient\n";
        std::cout << "3: Find Ingredient\n";
        std::cout << "4: Edit Ingredient(To work on)\n";
        std::cout << "5: Display Ingredients\n";
        std::cout << "6: Save\n";
        std::cout << "Choose an option: ";
        std::cin >> option;

        switch (option)
        {
        case 1:
        {
            std::cout << "What ingredient do you want to add to the list? ";
            std::cin >> buffer;
            append(ingredients, n++, buffer);
            break;
        }
        case 2:
        {
            std::cout << "What item do you want to delete? ";
            std::cin >> buffer;
            int index{};
            index = findIndex(ingredients, n, buffer);
            if (index >= 0)
                remove(ingredients, n--, index);
            else
                std::cout << "That item was not in the list.\n";
            break;
        }
        case 3:
        {
            std::cout << "What ingredient do you want to find?";
            std::cin >> buffer;
            int index{};
            index = findIndex(ingredients, n, buffer);
            if (index >= 0)
            {
                std::cout << buffer << " is number " << index << " on the list.\n";
            }
            else
            {
                std::cout << buffer << " is not on the list.\n";
            }
            break;
        }
        case 4:
        {
            std::cout << "What item do you want to edit? ";
            std::cin >> buffer;
            int index{};
            index = findIndex(ingredients, n, buffer);
            if (index >= 0)
            {
                std::cout << "What do you want to change it to? ";
                std::cin >> buffer;
                edit(ingredients, n, index, buffer);
            }
            else
                std::cout << buffer << " is not in the ingredients list.\n";
            break;
        }
        case 5:
        {
            forEach(ingredients, n, print);
            break;
        }
        case 6:
        {
            std::ofstream fout("pantry.txt");
            auto outLambda = [&](auto s) {
                fout << s << '\n';
            };
            forEach(ingredients, n, outLambda);
            break;
        }
        default:
            break;
        }
    } while (option != 0);
}
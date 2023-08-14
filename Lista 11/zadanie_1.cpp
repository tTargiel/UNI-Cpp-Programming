#include <iostream>

using namespace std;

// Tomasz Targiel
// Lista 11
// Zadanie 1

void run(int argc, const char *argv[])
{
    if (argc == 4)
    {
        try
        {
            if (isdigit(stoi(argv[1]) == true) & isdigit(stoi(argv[3]) == true))
            {
            }
        }
        catch (const exception &e)
        {
            throw logic_error("Błąd: Zarówno pierwszy lub trzeci argument nie mógł zostać przekonwertowany na liczbę!");
        }
        double a = stoi(argv[1]);
        double b = stoi(argv[3]);
        switch (*argv[2])
        {
        case '+':
        {
            cout << (a + b) << endl;
            break;
        };
        case '-':
        {
            cout << (a - b) << endl;
            break;
        };
        case '/':
        {
            if (b == 0)
            {
                throw logic_error("Błąd: Dzielenie przez zero!");
            }
            else
            {
                cout << (a / b) << endl;
                break;
            }
        };
        case '*':
        {
            cout << (a * b) << endl;
            break;
        };
        case '%':
        {
            if (b == 0)
            {
                throw logic_error("Błąd: Modulo 0!");
            }
            else
            {
                cout << (static_cast<int>(a) % static_cast<int>(b)) << endl;
                break;
            }
        };
        case '&':
        {
            cout << (static_cast<int>(a) & static_cast<int>(b)) << endl;
            break;
        };
        case '|':
        {
            cout << (static_cast<int>(a) | static_cast<int>(b)) << endl;
            break;
        };
        case '^':
        {
            cout << (static_cast<int>(a) ^ static_cast<int>(b)) << endl;
            break;
        };
        default:
        {
            throw logic_error("Błąd: Nieprawidłowe działanie!");
        };
        }
    }
    else
    {
        throw logic_error("Błąd: Nieprawidłowa liczba argumentów!");
    }
}

int main(int argc, const char *argv[])
{
    try
    {
        run(argc, argv);
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
    return 0;
}

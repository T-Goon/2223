#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <vector>

bool case_insensitive_equals(const std::string& left, const std::string& right)
{
    size_t size = left.size();
    if (right.size() != size)
    {
        return false;
    }
    for (size_t i = 0; i < size; ++i)
    {
        if (tolower(left[i]) != tolower(right[i]))
        {
            return false;
        }
    }
    return true;
}

class GameBoard
{
public:
    GameBoard(int green, int yellow, int orange)
        : green(green), yellow(yellow), orange(orange)
    {
    }

    void game()
    {
        int turn = 1;
        int turn_tracker = 1;
        std::string first_or_second = "a";

        while (!(case_insensitive_equals(first_or_second, "f") ||
                 case_insensitive_equals(first_or_second, "s")))
        {
            std::cout << "Do you want to go first or second?('f'/'s')"
                      << std::endl;
            std::cin >> first_or_second;
        }

        // mod 2 of the turn number to keep track of who goes when
        if (case_insensitive_equals(first_or_second, "f"))
        {
            turn_tracker = 1;
        }
        else if (case_insensitive_equals(first_or_second, "s"))
        {
            turn_tracker = 0;
        }

        // while moves can still be made

        // really rough, needs to be specific to each color. This is only if
        // you win
        while ((green + yellow + orange) > 0)
        {
            std::cout << "There are " << green << " green cells left"
                      << std::endl;
            std::cout << "There are " << yellow << " yellow cells left"
                      << std::endl;
            std::cout << "There are " << orange << " orange cells left"
                      << std::endl
                      << std::endl;

            if (turn % 2 == turn_tracker)
            {
                doPlayerTurn();
            }
            else
            {
                findComputerMove();
            }

            turn++;
        }

        if ((turn - 1) % 2 == turn_tracker)
        {
            std::cout << "Congratulations, You Win!";
        }
        else
        {
            std::cout << "Game Over, You Lose.";
        }
    }

private:
    int green;
    int yellow;
    int orange;

    enum class Color
    {
        GREEN,
        YELLOW,
        ORANGE
    };

    std::string from_color(Color& c)
    {
        std::string color;
        switch (c)
        {

        case Color::GREEN:
            color = "Green";
            break;
        case Color::YELLOW:
            color = "Yellow";
            break;
        case Color::ORANGE:
            color = "Orange";
            break;
        }
        return color;
    }

    Color to_color(const std::string& color)
    {

        if (case_insensitive_equals(color, "G"))
        {
            return Color::GREEN;
        }
        else if (case_insensitive_equals(color, "Y"))
        {
            return Color::YELLOW;
        }
        else if (case_insensitive_equals(color, "O"))
        {
            return Color::ORANGE;
        }
        else
        {
            std::cout << "Bad color: " << color << std::endl;
            exit(1);
        }
    }

    // Changes values based off a color and a number.
    // returns true of successful
    void updateBoard(const Color c, int j)
    {
        if (j > 0)
            switch (c)
            {

            case Color::GREEN:
                if (j <= green)
                {
                    green -= j;
                }
                break;
            case Color::YELLOW:
                if (j <= yellow)
                {
                    yellow -= j;
                }
                break;
            case Color::ORANGE:

                if (j <= orange)
                {
                    orange -= j;
                }
                break;
            default:
                break;
            }
    }

    Color randomColor()
    {
        Color c;
        int heap = std::rand() % 3;
        switch (heap)
        {

        case 0:
            c = Color::GREEN;
            break;
        case 1:
            c = Color::YELLOW;
            break;
        case 2:
            c = Color::ORANGE;
            break;
        default:
            std::cout << "Rand is broken. Fix your system." << std::endl;
            exit(1);
        }
        return c;
    }

    int randomMove(Color c)
    {

        int bound;
        switch (c)
        {
        case Color::GREEN:
            bound = this->green;
            break;
        case Color::YELLOW:
            bound = this->yellow;
            break;
        case Color::ORANGE:
            bound = this->orange;
            break;
        }
        return (std::rand() % bound) + 1;
    }

    void findComputerMove()
    {
        const int sum = green ^ yellow ^ orange;
        Color c;
        int cnt = -1;

        if (sum == 0)
        {
            // Choose a random move, no winning strategy.
            c = this->randomColor();
            cnt = this->randomMove(c);
        }
        else
        {
            int green_sum = sum ^ green;
            int yellow_sum = sum ^ yellow;
            int orange_sum = sum ^ orange;
            if (green_sum < green)
            {
                c = Color::GREEN;
                cnt = green - green_sum;
            }
            else if (yellow_sum < yellow)
            {
                c = Color::YELLOW;
                cnt = yellow - yellow_sum;
            }
            else if (orange_sum < orange)
            {
                c = Color::ORANGE;
                cnt = orange - orange_sum;
            }
            else
            {
                c = this->randomColor();
                cnt = this->randomMove(c);
            }
        }
        doComputerMove(c, cnt);
    }

    void doComputerMove(Color heap, int cnt)
    {
        std::cout << "Computer takes " << cnt << " from " << from_color(heap)
                  << std::endl;
        updateBoard(heap, cnt);
    }

    void doPlayerTurn()
    {
        std::string color = "foo";
        int removalNum = 0;

        while (!isValidColor(color))
        {
            std::cout
                << "Please enter the letter of the color you want to remove"
                << std::endl;
            std::cin >> color;
        }
        while (removalNum <= 0 || removalNum > colorRemaining(to_color(color)))
        {
            std::cout
                << "Please enter the number of that color you want to remove."
                << std::endl;
            std::cin >> removalNum;
        }
        updateBoard(to_color(color), removalNum);
    }

    bool isValidColor(const std::string& color)
    {
        if (case_insensitive_equals(color, "g") ||
            case_insensitive_equals(color, "y") ||
            case_insensitive_equals(color, "o"))
            return true;
        return false;
    }

    int colorRemaining(Color color)
    {
        switch (color)
        {
        case Color::GREEN:
            return green;
        case Color::YELLOW:
            return yellow;
        case Color::ORANGE:
            return orange;
        default:
            return -1;
        }
    }
};

int main()
{
    std::srand(time(NULL));
    GameBoard g(3, 7, 5);
    std::string temp;
    std::cout << "    ____              __    __        ______                 "
                 "__    __     __"
              << std::endl;
    std::cout << "   / __ \\____  __  __/ /_  / /__     /_  __/________  __  "
                 "__/ /_  / /__  / /"
              << std::endl;
    std::cout << "  / / / / __ \\/ / / / __ \\/ / _ \\     / / / ___/ __ \\/ / "
                 "/ / __ \\/ / _ \\/ /"
              << std::endl;
    std::cout << " / /_/ / /_/ / /_/ / /_/ / /  __/    / / / /  / /_/ / /_/ / "
                 "/_/ / /  __/_/ "
              << std::endl;
    std::cout << "/_____/\\____/\\__,_/_.___/_/\\___/    /_/ /_/   "
                 "\\____/\\__,_/_.___/_/\\___(_)"
              << std::endl;
    std::cout << "         G         " << std::endl;
    std::cout << "       G   G       " << std::endl;
    std::cout << "     Y   Y   Y     " << std::endl;
    std::cout << "   Y   Y   Y   Y   " << std::endl;
    std::cout << " O   O   O   O   O " << std::endl;
    g.game();
    return 0;
}

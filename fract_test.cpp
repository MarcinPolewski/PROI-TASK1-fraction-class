#include "fract.h"
#include <iostream>

int main()
{
    {
        fract f(1, 3);
        if (f.num() != 1 || f.denom() != 3)
            std::cerr << "Error in values after fract(1, 3) ctor\n";
        f.print(std::cout);
        std::cout << std::endl;
    }

    {
        fract f(2, 4);
        if (f.num() != 1 || f.denom() != 2)
            std::cerr << "Error in values after fract(2, 4) ctor\n";
        f.print(std::cout);
        std::cout << std::endl;
    }

    {
        fract f(0, 500);
        if (f.num() != 0 || f.denom() != 1)
            std::cerr << "Error in values after fract(0, 1) ctor\n";
        f.print(std::cout);
        std::cout << std::endl;
    }

    // testing equal()
    std::cerr << "equal() tests:\n";
    {
        fract f1(2, 4);
        fract f2(4, 8);

        if (!f1.equal(f2))
        {
            std::cerr << "Error, values are equal\n";
        }
    }
    std::cerr << "equal() tests:\n";
    {
        fract f1(4, 8);
        fract f2(2, 4);

        if (!f1.equal(f2))
        {
            std::cerr << "Error, values are equal\n";
        }
    }

    {
        fract f1(1, 3);
        fract f2(1, 3);

        if (!f1.equal(f2))
        {
            std::cerr << "Error, values are equal\n";
        }
    }

    {
        fract f1(0, 3);
        fract f2(0, 1000);

        if (!f1.equal(f2))
        {
            std::cerr << "Error, values are equal\n";
        }
    }

    {
        fract f1(1, 3);
        fract f2(1, 2);

        if (f1.equal(f2))
        {
            std::cerr << "Error, values are not equal\n";
        }
    }

    {
        fract f1(1, 3);
        fract f2(0, 2);

        if (f1.equal(f2))
        {
            std::cerr << "Error, values are not equal\n";
        }
    }

    // testing neg()
    std::cerr << "neg tests:\n";
    {
        fract f1(1, 2);
        fract f2 = f1.neg();

        if (f2.num() != -1 || f2.denom() != 2)
        {
            std::cerr << "Error, invalid fraction\n";
        }
        f2.print(std::cout);
        std::cout << std::endl;
    }

    {
        fract f1(-1, 2);
        fract f2 = f1.neg();

        if (f2.num() != 1 || f2.denom() != 2)
        {
            std::cerr << "Error, invalid fraction\n";
        }
        f2.print(std::cout);
        std::cout << std::endl;
    }

    {
        fract f1(0, 2);
        fract f2 = f1.neg();

        if (f2.num() != 0 || f2.denom() != 1)
        {
            std::cerr << "Error, invalid fraction\n";
        }
        f2.print(std::cout);
        std::cout << std::endl;
    }

    // testing lcm
    std::cerr << "testing lcm\n";
    {
        unsigned int a = 3;
        unsigned int b = 4;

        if (lcm(a, b) != 12)
            std::cerr << "Error, with lcm of " << a << " " << b << '\n';
    }

    {
        unsigned int a = 6;
        unsigned int b = 4;

        if (lcm(a, b) != 12)
            std::cerr << "Error, with lcm of " << a << " " << b << '\n';
    }

    {
        unsigned int a = 5;
        unsigned int b = 10;

        if (lcm(a, b) != 10)
            std::cerr << "Error, with lcm of " << a << " " << b << '\n';
    }

    // testing add
    std::cerr << "add() tests:\n";
    {
        fract f1(1, 2);
        fract f2(1, 3);

        f1.add(f2);

        if (f1.num() != 5 || f1.denom() != 6)
            std::cerr << "Error, wrong addition result!\n";
        f1.print(std::cout);
        std::cout << '\n';
    }

    {
        fract f1(-1, 2);
        fract f2(1, 2);

        f1.add(f2);

        if (f1.num() != 0 || f1.denom() != 1)
            std::cerr << "Error, wrong addition result!\n";
        f1.print(std::cout);
        std::cout << '\n';
    }

    {
        fract f1(1, 2);
        fract f2(-1, 4);

        f1.add(f2);

        if (f1.num() != 1 || f1.denom() != 4)
            std::cerr << "Error, wrong addition result!\n";
        f1.print(std::cout);
        std::cout << '\n';
    }

    {
        fract f1(-1, 2);
        fract f2(-1, 4);

        f1.add(f2);

        if (f1.num() != -3 || f1.denom() != 4)
            std::cerr << "Error, wrong addition result!\n";
        f1.print(std::cout);
        std::cout << '\n';
    }

    {
        fract f1(1, 4);
        fract f2(1, 4);

        f1.add(f2);

        if (f1.num() != 1 || f1.denom() != 2)
            std::cerr << "Error, wrong addition result!\n";
        f1.print(std::cout);
        std::cout << '\n';
    }

    // testing sum()
    std::cerr << "sum() tests:\n";
    {
        fract f1(-1, 2);
        fract f2(1, 2);

        fract f3 = f1.sum(f2);
        if (f3.num() != 0 || f3.denom() != 1)
        {
            std::cerr << "Error, wrong sum result\n";
        }
        f3.print(std::cout);
        std::cout << '\n';
    }
    {
        fract f1(1, 4);
        fract f2(1, 4);

        fract f3 = f1.sum(f2);
        if (f3.num() != 1 || f3.denom() != 2)
        {
            std::cerr << "Error, wrong sum result\n";
        }
        f3.print(std::cout);
        std::cout << '\n';
    }
    {
        fract f1(1, 2);
        fract f2(-1, 4);

        fract f3 = f1.sum(f2);
        if (f3.num() != 1 || f3.denom() != 4)
        {
            std::cerr << "Error, wrong sum result\n";
        }
        f3.print(std::cout);
        std::cout << '\n';
    }

    // testing mul()
    std::cerr << "mul() tests:\n";
    {
        fract f1(2, 3);
        fract f2(3, 4);

        f1.mul(f2);
        if (f1.num() != 1 || f1.denom() != 2)
        {
            std::cerr << "Error, wrong mul() result\n";
        }
        f1.print(std::cout);
        std::cout << '\n';
    }

    {
        fract f1(-2, 3);
        fract f2(3, 4);

        f1.mul(f2);
        if (f1.num() != -1 || f1.denom() != 2)
        {
            std::cerr << "Error, wrong mul() result\n";
        }
        f1.print(std::cout);
        std::cout << '\n';
    }

    {
        fract f1(-1, 3);
        fract f2(-1, 4);

        f1.mul(f2);
        if (f1.num() != 1 || f1.denom() != 12)
        {
            std::cerr << "Error, wrong mul() result\n";
        }
        f1.print(std::cout);
        std::cout << '\n';
    }

    // testing prod
    std::cerr << "prod() tests:\n";
    {
        fract f1(2, 3);
        fract f2(2, 4);
        fract f3;
        f3 = f1.prod(f2);

        if (f3.num() != 1 || f3.denom() != 3)
        {
            std::cerr << "Error, wron prod() result\n";
        }
        f3.print(std::cout);
        std::cout << '\n';
    }

    {
        fract f1(2, 3);
        fract f2(-2, 4);
        fract f3;
        f3 = f1.prod(f2);

        if (f3.num() != -1 || f3.denom() != 3)
        {
            std::cerr << "Error, wron prod() result\n";
        }
        f3.print(std::cout);
        std::cout << '\n';
    }

    {
        fract f1(-2, 3);
        fract f2(-2, 4);
        fract f3;
        f3 = f1.prod(f2);

        if (f3.num() != 1 || f3.denom() != 3)
        {
            std::cerr << "Error, wron prod() result\n";
        }
        f3.print(std::cout);
        std::cout << '\n';
    }

    {
        fract f1(1, 3);
        fract f2(1, 4);
        fract f3;
        f3 = f1.prod(f2);

        if (f3.num() != 1 || f3.denom() != 12)
        {
            std::cerr << "Error, wron prod() result\n";
        }
        f3.print(std::cout);
        std::cout << '\n';
    }
    std::cout << std::endl;
    return 0;
}

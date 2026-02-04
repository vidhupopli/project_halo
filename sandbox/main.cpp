#include <iostream>

int main()
{
    auto lambdaWithIntReturnTypeExplictlyWritten = []() -> int
    {
        return 10;
    };

    auto lambdaWithInferredIntReturnType = []()
    {
        return 20;
    };

    std::cout << lambdaWithIntReturnTypeExplictlyWritten() << std::endl;
    std::cout << lambdaWithInferredIntReturnType() << std::endl;

    return 0;
}
#include <vector>
#include <catch2/catch.hpp>

SCENARIO(
    "空のvectorに値を追加し参照する")
{
    GIVEN("空のvectorを準備")
    {
        std::vector<int> sut;

        THEN("vectorは空")
        {
            CHECK(sut.empty());
        }

        WHEN("値を追加")
        {
            sut.push_back(1);
            sut.push_back(2);
            sut.push_back(3);

            THEN("要素数=3")
            {
                REQUIRE(sut.size() == 3);

                AND_THEN("追加した順に格納されている")
                {
                    CHECK(sut[0] == 1);
                    CHECK(sut[1] == 2);
                    CHECK(sut[2] == 3);
                }
            }
        }
    }
}

SCENARIO(
    "vectorに最初から値を設定する")
{
    WHEN("vectorを準備")
    {
        std::vector<int> sut{4, 5, 6};

        THEN("要素数=3")
        {
            REQUIRE(sut.size() == 3);

            AND_THEN("追加した順に格納されている")
            {
                CHECK(sut[0] == 4);
                CHECK(sut[1] == 5);
                CHECK(sut[2] == 6);
            }
        }
    }
}

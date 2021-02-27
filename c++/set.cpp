#include <algorithm>
#include <set>
#include <catch2/catch.hpp>

SCENARIO(
    "空のsetに値を追加し有無確認・全参照")
{
    std::set<int> sut;
    REQUIRE(sut.empty());

    WHEN("新規の値を追加する")
    {
        const auto result = sut.insert(1);

        THEN("追加成功する")
        {
            REQUIRE(result.second);
            CHECK(sut.count(1) == 1);
        }

        AND_WHEN("重複する値を追加する")
        {
            const auto result = sut.insert(1);

            THEN("追加失敗する")
            {
                REQUIRE(!result.second);
                CHECK(sut.count(1) == 1);
            }

            AND_WHEN("他の値も追加")
            {
                sut.insert(2);
                sut.insert(3);

                AND_WHEN("値の小さい順に参照できる")
                {
                    auto p = sut.begin();
                    REQUIRE(p != sut.end());
                    CHECK(*p == 1);

                    ++p;
                    REQUIRE(p != sut.end());
                    CHECK(*p == 2);

                    ++p;
                    REQUIRE(p != sut.end());
                    CHECK(*p == 3);

                    ++p;
                    REQUIRE(p == sut.end());
                }

                AND_WHEN("要素を合計する")
                {
                    int sum = 0;

                    for (const auto i : sut)
                    {
                        sum += i;
                    }

                    THEN("結果は6")
                    {
                        CHECK(sum == 6);
                    }
                }
            }
        }
    }
}

SCENARIO(
    "最初から値ありのsetを生成")
{
    const std::set<int> sut{1, 2, 3};
    REQUIRE(sut.size() == 3);
    CHECK(sut.count(1) == 1);
    CHECK(sut.count(2) == 1);
    CHECK(sut.count(3) == 1);
}

SCENARIO(
    "集合演算")
{
    const std::set<int> a{1, 2, 3, 4};
    const std::set<int> b{3, 4, 5, 6};

    std::set<int> result;

    WHEN("和演算を実行")
    {
        std::set_union(
            a.begin(), a.end(),
            b.begin(), b.end(),
            std::inserter(result, result.end()));

        THEN("a∪bを得られる")
        {
            REQUIRE(result.size() == 6);
            CHECK(result.count(1) == 1);
            CHECK(result.count(2) == 1);
            CHECK(result.count(3) == 1);
            CHECK(result.count(4) == 1);
            CHECK(result.count(5) == 1);
            CHECK(result.count(6) == 1);
        }
    }

    SECTION("積演算を実行")
    {
        std::set_intersection(
            a.begin(), a.end(),
            b.begin(), b.end(),
            std::inserter(result, result.end()));

        THEN("a∩bを得られる")
        {
            REQUIRE(result.size() == 2);
            CHECK(result.count(3) == 1);
            CHECK(result.count(4) == 1);
        }
    }

    SECTION("aとbの差演算を実行")
    {
        std::set_difference(
            a.begin(), a.end(),
            b.begin(), b.end(),
            std::inserter(result, result.end()));

        THEN("a＼bを得られる")
        {
            REQUIRE(result.size() == 2);
            CHECK(result.count(1) == 1);
            CHECK(result.count(2) == 1);
        }
    }
}

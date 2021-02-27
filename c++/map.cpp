#include <map>
#include <catch2/catch.hpp>

SCENARIO(
    "空のmapに値を追加し有無確認・全参照")
{
    std::map<int, int> sut;
    REQUIRE(sut.empty());

    WHEN("存在しないキーの取得を試みる(find)")
    {
        const auto p = sut.find(0);

        THEN("存在しないことがわかる")
        {
            CHECK(p == sut.end());
        }
    }

    WHEN("存在しないキーの取得を試みる(op[])")
    {
        const auto v = sut[0];

        THEN("要素が生成されてしまう")
        {
            CHECK(v == 0);
        }
    }

    WHEN("新規の値を追加する")
    {
        const auto result = sut.insert({1, 2});

        THEN("追加成功する")
        {
            REQUIRE(result.second);
            CHECK(sut.count(1) == 1);
            CHECK(sut[1] == 2);
        }

        AND_WHEN("重複する値を追加する")
        {
            const auto result = sut.insert({1, 3});

            THEN("追加失敗する")
            {
                REQUIRE(!result.second);
                CHECK(sut.count(1) == 1);
                CHECK(sut[1] == 2);
            }

            AND_WHEN("他の値を2つ追加")
            {
                sut.insert({2, 3});
                sut.insert({3, 4});

                AND_WHEN("値の小さい順に参照できる")
                {
                    auto p = sut.begin();
                    REQUIRE(p != sut.end());
                    CHECK(p->first == 1);
                    CHECK(p->second == 2);

                    ++p;
                    REQUIRE(p != sut.end());
                    CHECK(p->first == 2);
                    CHECK(p->second == 3);

                    ++p;
                    REQUIRE(p != sut.end());
                    CHECK(p->first == 3);
                    CHECK(p->second == 4);

                    ++p;
                    REQUIRE(p == sut.end());
                }

                AND_WHEN("要素を合計する")
                {
                    int sum = 0;

                    for (const auto pair : sut)
                    {
                        sum += pair.second;
                    }

                    THEN("結果は想定通り")
                    {
                        CHECK(sum == 9);
                    }
                }

                AND_WHEN("要素の値を変更する")
                {
                    auto p = sut.find(2);
                    REQUIRE(p != sut.end());

                    p->second += 1;

                    THEN("変更した要素のみ値が変わっている")
                    {
                        CHECK(sut[1] == 2);
                        CHECK(sut[2] == 4);
                        CHECK(sut[3] == 4);
                    }
                }
            }
        }
    }
}

SCENARIO(
    "最初から値ありのmapを生成")
{
    const std::map<int, int> sut{{4, 16}, {5, 25}, {6, 36}};
    REQUIRE(sut.size() == 3);
    CHECK(sut.count(4) == 1);
    CHECK(sut.count(5) == 1);
    CHECK(sut.count(6) == 1);
}

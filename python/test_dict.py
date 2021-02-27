def test_空のdictに値を追加し有無確認_全参照():
    sut = {}
    assert len(sut) == 0

    # 存在しない値は取得できない(1)
    #   []の場合、なければ例外を投げる
    try:
        sut[0]
        assert False    # ここには来ないはず
    except KeyError:
        assert True     # ここに来るはず
    except:
        assert False    # KeyError以外は投げられないはず

    # 存在しない値は取得できない(2)
    #   getメソッドの場合、なければNoneを返す
    assert sut.get(0) == None

    # 新規の値(重複なし)を追加する
    sut[1] = 2
    sut[2] = 3
    sut[3] = 4
    assert len(sut) == 3
    assert 1 in sut
    assert sut[1] == 2
    assert 2 in sut
    assert sut[2] == 3
    assert 3 in sut
    assert sut[3] == 4

    # 重複する値の追加を試みる => 構文的に追加と更新とが分離していないので、更新される
    sut[2] = 4
    assert len(sut) == 3
    assert sut[1] == 2
    assert sut[2] == 4
    assert sut[3] == 4

    # 要素を合計する
    sum = 0
    for key in sut:
        sum += sut[key]
    assert sum == 10


def test_最初から値ありのdictを生成():
    sut = {4: 16, 5: 25, 6: 36}
    assert len(sut) == 3
    assert 4 in sut
    assert 5 in sut
    assert 6 in sut

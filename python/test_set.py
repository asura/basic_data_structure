def test_空のsetに値を追加し有無確認_全参照():
    sut = set()
    assert len(sut) == 0

    # 新規の値を追加する
    sut.add(1)
    sut.add(2)
    sut.add(3)
    assert len(sut) == 3
    assert 1 in sut
    assert 2 in sut
    assert 3 in sut

    # 重複する値を追加する => 変化なし
    sut.add(1)
    assert len(sut) == 3
    assert 1 in sut
    assert 2 in sut
    assert 3 in sut

    # 要素を合計する
    sum = 0
    for x in sut:
        sum += x
    assert sum == 6


def test_最初から値ありのsetを生成():
    sut = {4, 5, 6}
    assert len(sut) == 3
    assert 4 in sut
    assert 5 in sut
    assert 6 in sut


def test_集合演算_和():
    a = {1, 2, 3, 4}
    b = {3, 4, 5, 6}
    assert a.union(b) == {1, 2, 3, 4, 5, 6}
    assert (a | b) == {1, 2, 3, 4, 5, 6}


def test_集合演算_積():
    a = {1, 2, 3, 4}
    b = {3, 4, 5, 6}
    assert a.intersection(b) == {3, 4}
    assert (a & b) == {3, 4}


def test_集合演算_差():
    a = {1, 2, 3, 4}
    b = {3, 4, 5, 6}
    assert a.difference(b) == {1, 2}
    assert (a - b) == {1, 2}

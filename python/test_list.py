def test_空のlistに値を追加し参照する():
    sut = []
    assert len(sut) == 0

    # 値を追加
    sut.append(1)
    sut.append(2)
    sut.append(3)

    # 追加した順に格納されている
    assert len(sut) == 3
    assert sut[0] == 1
    assert sut[1] == 2
    assert sut[2] == 3

    # 要素を合計する
    sum = 0
    for value in sut:
        sum += value

    assert sum == 6


def test_listに最初から値を設定する():
    sut = [4, 5, 6]
    assert len(sut) == 3

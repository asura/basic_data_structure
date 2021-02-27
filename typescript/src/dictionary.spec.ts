/**
 * 文字列→数値の連想配列型
 * @note Objectクラスの力を借りる必要があり、キーは文字列にしておくのが無難
 */
interface Dictionary {
    [key: string]: number;
}

describe("Dictionary", () => {
    describe('空のDictionaryを用意する', () => {
        let sut: Dictionary = {};

        it('Dictionaryは空である', () => {
            expect(Object.keys(sut).length).toEqual(0);
        });

        describe('要素を3つ追加する', () => {
            beforeAll(() => {
                sut['1'] = 2;
                sut['2'] = 3;
                sut['3'] = 4;
            });

            it('要素数=3', () => {
                expect(Object.keys(sut).length).toEqual(3);
            });

            it('追加した値が格納されている', () => {
                expect('1' in sut).toBeTruthy();
                expect(sut['1']).toEqual(2);
                expect('2' in sut).toBeTruthy();
                expect(sut['2']).toEqual(3);
                expect('3' in sut).toBeTruthy();
                expect(sut['3']).toEqual(4);
            });

            describe('要素を合計する', () => {
                let sum = 0;

                beforeAll(() => {
                    Object.keys(sut).forEach(key => {
                        sum += sut[key];
                    });
                });

                it('結果は9', () => {
                    expect(sum).toEqual(9);
                });
            })

            describe('要素の値を変更する', () => {
                beforeAll(() => {
                    sut['1'] = 3;
                });

                it('変更した値になっている', () => {
                    expect('1' in sut).toBeTruthy();
                    expect(sut['1']).toEqual(3);
                });
            });
        });
    });

    describe('最初から値ありのDictionaryを生成', () => {
        const sut: Dictionary = { '4': 16, '5': 25, '6': 36 };

        it('要素数=3', () => {
            expect(Object.keys(sut).length).toEqual(3);
        });

        it('指定した値が格納されている', () => {
            expect('4' in sut).toBeTruthy();
            expect('5' in sut).toBeTruthy();
            expect('6' in sut).toBeTruthy();
        });
    });
});

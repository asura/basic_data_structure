describe("Array", () => {
    describe('空の配列を用意する', () => {
        let sut: number[] = [];

        it('配列は空である', () => {
            expect(sut.length).toEqual(0);
        });

        describe('値を追加する', () => {
            beforeAll(() => {
                sut.push(1);
                sut.push(2);
                sut.push(3);
            });

            it('要素数=3', () => {
                expect(sut.length).toEqual(3);
            });

            it('追加した順に格納されている', () => {
                expect(sut[0]).toEqual(1);
                expect(sut[1]).toEqual(2);
                expect(sut[2]).toEqual(3);
            });

            describe('要素を合計する', () => {
                let sum = 0;

                beforeAll(() => {
                    for (let value of sut) {
                        sum += value;
                    }
                });

                it('結果は6', () => {
                    expect(sum).toEqual(6);
                });
            })
        });
    });

    describe('要素あり配列を用意する', () => {
        let sut = [4, 5, 6];

        it('要素数=3', () => {
            expect(sut.length).toEqual(3);
        });
    });
});

describe("Set", () => {
    describe('空のSetを用意する', () => {
        let sut: Set<number> = new Set();

        it('Setは空である', () => {
            expect(sut.size).toEqual(0);
        });

        describe('値を追加する', () => {
            beforeAll(() => {
                sut.add(1);
                sut.add(2);
                sut.add(3);
            });

            it('要素数=3', () => {
                expect(sut.size).toEqual(3);
            });

            it('追加した値が格納されている', () => {
                expect(sut.has(1)).toBeTruthy();
                expect(sut.has(2)).toBeTruthy();
                expect(sut.has(3)).toBeTruthy();
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

    describe('最初から値ありのSetを生成', () => {
        let sut = new Set([4, 5, 6]);

        it('要素数=3', () => {
            expect(sut.size).toEqual(3);
        });

        it('指定した値が格納されている', () => {
            expect(sut.has(4)).toBeTruthy();
            expect(sut.has(5)).toBeTruthy();
            expect(sut.has(6)).toBeTruthy();
        });
    });

    describe('集合演算', () => {
        const a = new Set([1, 2, 3, 4]);
        const b = new Set([3, 4, 5, 6]);

        describe('和集合', () => {
            let result: Set<number> = new Set();
            const expected = new Set([1, 2, 3, 4, 5, 6]);

            beforeAll(() => {
                for (let value of a) {
                    result.add(value);
                }

                for (let value of b) {
                    result.add(value);
                }
            });

            it('想定どおりの結果を得られる', () => {
                expect(result).toEqual(expected);
            });
        });

        describe('積集合', () => {
            let result: Set<number> = new Set();
            const expected = new Set([3, 4]);

            beforeAll(() => {
                result = new Set([...a].filter(e => (b.has(e))));
            });

            it('想定どおりの結果を得られる', () => {
                expect(result).toEqual(expected);
            });
        });

        describe('差集合', () => {
            let result: Set<number> = new Set();
            const expected = new Set([1, 2]);

            beforeAll(() => {
                result = new Set([...a].filter(e => (!b.has(e))));
            });

            it('想定どおりの結果を得られる', () => {
                expect(result).toEqual(expected);
            });
        });
    });
});

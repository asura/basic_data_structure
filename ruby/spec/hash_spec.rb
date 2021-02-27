# frozen_string_literal: true

describe Hash do
  context '空のHashを用意する' do
    Given(:sut) { {} }
    Then { sut.empty? }

    context '存在しないキーの取得を試みる(fetch)' do
      specify '例外KeyError発生' do
        expect do
          sut.fetch(0)
        end.to raise_error(KeyError, 'key not found: 0')
      end
    end

    context '存在しないキーの取得を試みる([])' do
      When(:result) { sut[0] }
      Then { result.nil? }
    end

    context '新規の値を追加する' do
      When do
        sut[1] = 2
        sut[2] = 3
        sut[3] = 4
      end
      Then { sut.length == 3 }
      Then { sut.key?(1) }
      Then { sut[1] == 2 }
      Then { sut.key?(2) }
      Then { sut[2] == 3 }
      Then { sut.key?(3) }
      Then { sut[3] == 4 }

      context '重複する値を追加する' do # 構文的に追加と更新とが分離していないので、更新される
        When { sut[1] = 3 }
        Then { sut.length == 3 }
        Then { sut.key?(1) }
        Then { sut[1] == 3 }
        Then { sut.key?(2) }
        Then { sut[2] == 3 }
        Then { sut.key?(3) }
        Then { sut[3] == 4 }
      end

      context '要素を合計する' do
        When(:sum) do
          result = 0
          sut.each do |_key, value|
            result += value
          end
          result
        end
        Then { sum == 9 }
      end
    end
  end

  context '最初から値ありのHashを生成' do
    Given(:sut) { { 1 => 2, 2 => 3, a: 4, 'b' => 5 } }
    Then { sut.size == 4 }
    Then { sut.key?(1) }
    Then { sut.key?(2) }
    Then { sut.key?(:a) }
    Then { sut.key?('b') }
  end
end

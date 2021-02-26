# frozen_string_literal: true

describe Array do
  context '空の配列を用意する' do
    Given(:sut) { [] }
    Then { sut.empty? }

    context '値を追加する' do
      When { sut << 1 << 2 << 3 }
      Then { sut.size == 3 }
      Then { sut[0] == 1 }
      Then { sut[1] == 2 }
      Then { sut[2] == 3 }

      context '要素を合計する' do
        When(:sum) do
          result = 0
          sut.each do |value|
            result += value
          end
          result
        end
        Then { sum == 6 }
      end
    end
  end

  context '要素あり配列を用意する' do
    Given(:sut) { [4, 5, 6] }
    Then { !sut.empty? }
    Then { sut.size == 3 }
    Then { sut[0] == 4 }
    Then { sut[1] == 5 }
    Then { sut[2] == 6 }
  end
end

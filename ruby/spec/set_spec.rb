# frozen_string_literal: true

require 'set'

describe Set do
  context '空のSetを用意する' do
    Given(:sut) { Set.new }
    Then { sut.empty? }

    context '新規の値を追加する' do
      When { sut << 1 }
      Then { sut.size == 1 }

      context '重複する値を追加する' do
        When { sut << 1 }
        Then { sut.size == 1 }
      end

      context '他の値も追加' do
        When { sut << 2 << 3 }
        Then { sut.size == 3 }
        Then { sut.include?(1) }
        Then { sut.include?(2) }
        Then { sut.include?(3) }

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
  end

  context '最初から値ありのSetを生成' do
    Given(:sut) { Set.new([4, 5, 6]) }
    Then { sut.size == 3 }
  end

  context '集合演算' do
    Given(:a) { Set.new([1, 2, 3, 4]) }
    Given(:b) { Set.new([3, 4, 5, 6]) }

    context '和集合' do
      let(:expected) { Set.new([1, 2, 3, 4, 5, 6]) }

      When(:result1) { a.union(b) }
      Then { result1 ==  expected }

      When(:result2) { a + b }
      Then { result2 == expected }

      When(:result3) { a | b }
      Then { result3 == expected }
    end

    context '積集合' do
      let(:expected) { Set.new([3, 4]) }

      When(:result1) { a.intersection(b) }
      Then { result1 == expected }

      When(:result2) { a & b }
      Then { result2 == expected }
    end

    context '差集合' do
      let(:expected) { Set.new([1, 2]) }

      When(:result1) { a.difference(b) }
      Then { result1 == expected }

      When(:result2) { a - b }
      Then { result2 == expected }
    end
  end
end

# 様々な言語の基本的な型・データ構造のサンプル

* 普段C++を使っている者が他言語に手を出して「書き方わからない…」となったので、サンプルとしてまとめる
* 例: コンテナ系
  * emptyあるか
  * size? length? メソッド？プロパティ？
  * ループはクラスのメソッドなのかグローバルな言語構文なのか、forなのかeachなのか
* 適当なテストツールを選び、テストコードとして書いた

||C++|Python|Ruby|TypeScript|
|-|-|-|-|-|
|整数|int, long, long long||||
|浮動小数点数|float, double||||
|文字列|string||||
|配列・リスト|[vector](c++/vector.cpp), array, list|[list](python/test_list.py)|[Array](ruby/spec/array_spec.rb)|[Array](typescript/src/array.spec.ts)|
|連想配列|[map](c++/map.cpp), unordered_map|[dict](python/test_dict.py)|[Hash](ruby/spec/hash_spec.rb)||
|集合|[set](c++/set.cpp), unordered_set|[set](python/test_set.py)|[Set](ruby/spec/set_spec.rb)|[Set](typescript/src/set.spec.ts)|
||||||
|<テストツール>|[Catch2](https://github.com/catchorg/Catch2)|[pytest](https://docs.pytest.org/en/stable/)|[rspec-given](https://github.com/jimweirich/rspec-given)|[jest](https://jestjs.io/docs/ja/getting-started)|

## サンプルの動かしかた

### C++

```
$ cd c++
$ mkdir build
$ cd build
$ cmake .. -DCMAKE_BUILD_TYPE=Release
$ make
$ ./sample
```

### Python

```
$ cd python
$ pip3 install -r requirements.txt 
$ pytest -v
```

### Ruby

```
$ cd ruby
$ bundle install
$ bundle exec rspec
```

### TypeScript

```
$ cd typescript
$ jest --verbose
```

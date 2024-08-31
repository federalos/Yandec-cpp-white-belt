# Класс Rational: Часть 4

Наконец, вам нужно реализовать возможность использовать объекты класса Rational в качестве элементов контейнера set и ключей в контейнере map. Пример:

```c++
set<Rational> rationals;
rationals.insert(Rational(1, 2));
rationals.insert(Rational(1, 3));

map<Rational, string> name;
name[Rational(1, 2)] = "одна вторая";
```

[**Шаблон программы**](rational_map.cpp)

[**Решение**](Rational_part_5.cpp)

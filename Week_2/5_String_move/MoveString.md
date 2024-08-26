# Перемещение строк

Напишите функцию MoveStrings, которая принимает два вектора строк, source и destination, и дописывает все строки из первого вектора в конец второго. После выполнения функции вектор source должен оказаться пустым.

_Чтобы очистить содержимое вектора, надо вызвать у него метод clear:_
```c++
vector<string> words = {"hey", "hi"};
words.clear();
// Теперь вектор words пуст
```
## Пример

```c++
vector<string> source = {"a", "b", "c"};
vector<string> destination = {"z"};
MoveStrings(source, destination);
// source должен оказаться пустым
// destination должен содержать строки "z", "a", "b", "c" именно в таком порядке
```
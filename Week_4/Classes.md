# Структуры исключения и перегрузка операторов


## Дополнение к конструкторам
Сейчас может быть довольно странная часть текста, но всё же...

На текущий момент, мы научились делать структуры и классы. Но есть некоторая механика, которая немного усложняет код, но повышает его читаемость для будущего себя и других коллег, которые будут смотреть твой код без тебя. Возьмём пример: структура `date`:
```c++
struct Date {
	int day;
	int month;
	int year;
}
void PrintDate(const Date& date){
	cout << date.day << "." << date.month << "." << date.year << "\n";
}
int main(){
	Date date = {1, 1, 2017};
	return 0;
}
```
вывод:
```
1.1.2017
```

На первый взгляд всё работает и выводится. Но теперь представим, что структура не видна, и ты забыл, как она выглядит и имеется доступ только к куску кода из `main()`:
```C++
int main(){
	Date date = {10, 12, 11};
	return 0;
}
```
Какой здесь формат даты? Обычный: день-месяц-год? А может быть американский стиль: месяц-день-год? А может и вовсе: год-месяц-день? Для таких дел, можно с помощью структур и конструкторов решить этот вопрос. Пусть конструктор принимает на вход не просто целые числа, а некоторые "обёртки" над числами:
```c++
// структуры с одиним полем:
struct Day{
	int value;
};
struct Month{
	int value;
};
struct Year{
	int value;
};
struct Date {
	int day;
	int month;
	int year;
	// конструктор получает структуры
	Date(Day new_day, Month new_month, Year new_year){
		// и иницииализзирует поля Date по этим структурам
		day = new_day.value;
		month = new_month.value;
		year = new_year.value;
	}
}
```
В такой записи, мы не сможем воспользоваться вызовом:
```C++
int main(){
	Date date = {10, 12, 11};
	return 0;
}
```
Будет выдана ошибка компиляции, так как не получится компилятору однозначно распределить данные в структуры структур. И есть возможность теперь объявить поля структуры `Date` следующим образом:
```C++
// var 1
Date date(Day{10}, Month{11}, Year{12}); // Создай объект типа Day со значением 10 и так далее
// or
// var 2
Date date({10}, {11}, {12}); // разрешённая компилятором "оптимизация"
```
Так вот, мы почти решили проблему читаемости кода, но у нас остаётся `var 2` и получается, что это "как бы " решило вопрос, но с другой стороны вы наделали дополнительных делов, а толку почти ноль. Так не пойдёт. Для явной задачи дней-месяцев-годов нужно объявить конструкторы в структурах дней-месяцев-годов и с запретом на неявные преобразование типа: "целого числа к структурам типа день-месяц-год". Делается это путём "Явного конструктора" преобразования целых чисел к структурам через команду #explicit:
```C++
struct Day{
	int value;
	Explicit Day(int new_value){
		value = new_value;
	}
};
struct Month{
	int value;
	Explicit Month(int new_value){
		value = new_value;
	}
};
struct Year{
	int value;
	Explicit Year(int new_value){
		value = new_value;
	}
};
```
После этого для компилятора не останётся другого выбора кроме как требовать от разработчика явной задачи типов структур и останется только один единственный способ объявления структуры типа `Date`:
```C++
// var 1
Date date(Day{10}, Month{11}, Year{12});
// var 2
Date date(Day{10}, Month{11}, Year{12});

```

## Работа с файлами и потоками С++
Базовые классы потока:
- istream - поток ввода (cin)
- ostream - поток вывода (cout)
- iostream - поток вводы/вывода


Остальные классы, которые будут рассмотрены ниже либо будут наследовать эти классы, либо будут реализовывать вышеуказанные классы

Потоки для работы с файлами
`#include <fstream>`
- ifstream - для чтения (наследник *istream*)
- ofstream - для записи (наследник *ostream*)
- fstream - для чтения и записи (наследник *iostream*)

Чтение файла:
- Потоковый ввод: `>>`
- Построчное считывание данных из файла: `getline()`

Теперь поговорим о том, как на деле работать с файлами. 

```C++
int main(){
	ifstream input ("file_name.txt");
	string line;
	getline(input, line);
	cout << line << endl;
	return 0;
}
```

Здесь произошло следующее: мы определелили в переменную класс `ifstream` , на вход которой подаётся адрес до считываемого файла. Затем, с помощью `getline(input,line)` определили каким методом считать данные из `input` и куда записать полученный результат `line`. Для того, чтобы считать вторую строку, можно вызвать метод `getline(input,line)` второй раз и так далее. Интересный момент, если вызвать метод `getline(input,line)` больше раз ($L$), чем строчек в файле($N$), то есть $L > N$ тогда выводы $L-N$ последних строчек будет выводится дубликат самой последней строчки файла.

Метод `getline(input,line)` возвращает ссылку на поток из которого она читает данные, а поток можно привести к типу `boolen`, который будет `false` при окончании потока. Тогда код выше можно переписать так, чтобы считывалось все строчки из файла (и ни строчкой более):
```C++
int main(){
	ifstream input ("file_name.txt");
	string line;
	while (getline(input, line)){
		cout << line << endl;
	}
	return 0;
}
```
`getline(input,line)` считывает до ближайшего знака разделения строки. То есть ближайший знак `\n` он не включает в себя. стоит помнить об этом.

У потоков есть метод is_open(), который проверят получилось ли "открыть" доступ к выбранному файлу. Не прочитать поток можно по разным причинам: файл не существует, путь до файл объявлен с ошибкой, сам файл объявлен с ошибкой или к нему закрыт доступ из программы на считывание. Для таких случаев как раз и нужен метод `is_open()`, чтобы проверять наличие потока:

```C++
int main(){
	ifstream input ("file_name.txt");
	string line;
	if (input.is_open()){
		while (getline(input, line)){
			cout << line << endl;
		}
		cout << "Done!" << endl; 
	} else {
		cout << "Error!" << endl; 
	}
	return 0;
}
```

Но вспомним то, что потоки можно приводить к логическому типу, и тогда код можно слегка упростить:

```C++
int main(){
	ifstream input ("file_name.txt");
	string line;
	if (input){
		while (getline(input, line)){
			cout << line << endl;
		}
		cout << "Done!" << endl; 
	} else {
		cout << "Error!" << endl; 
	}
	return 0;
}
```

Теперь, как работать с данным внутри которых есть некоторые разделители? Это не так сложно, один из аргументов метода `getline(input, line, '-')` - это разделить, до которого будет считывать этот метод. В данном случае этот аргумент `-`. То есть поток считается до первого `-`.  

Второй способ считывания потока идёт через `>>` (как было сказано ранее). И сейчас рассмотрим, как они работают с потоком. Пусть есть файл `date.txt`, внутри которого находится дата в следующем формате:

```
2017-01-25
```

И мы хотим считать год, месяц и день в программе. Тогда скрипт программы будет выглядеть следующим образом:

```C++
int main(){
	ifstream input ("date.txt");
	int year = 0;
	int month = 0;
	int day = 0;

	if (input){
		input >> year;
		input.ignore(1);
		input >> month;
		input.ignore(1);		
		input >> day;
		input.ignore(1);
	}
	cout << year << ' ' << month << ' ' << day;
	return 0;
}
```

Вывод подобной программы будет:

```
2017 01 25
```

Что здесь произошло? Считается поток до `-` (из-за приведения типа, `-`первый символ, который в данном контексте сложно привести к `int` ), но нам нужно будет проигнорировать, при считывании следующей порции информации. Для таких вещей как раз и существует метод `input.ignore(N);`, который "пропустит следующие N символов". И после этого можно снова считать поток в новую переменную.

С чтением разобрались, теперь поговорим о записи в файл. 

```c++
int main(){
	const string path = "out.txt";
	ofstream output(path);
	output << "Hello" << endl;
	ifstream input (path)
	if (input){
		string line;
		while (getline(input, line)){
			cout << line << endl;
		}
	return 0;
}
```

Каждый раз, когда вызывается `ofstream` файл по адресу стирается и полностью перезаписывается. Но если нужно дозаписать данные в файл, то можно использовать флаг при объявлении:

```c++
	ofstream output(path, ios::app);
```

где `app` сокращение от *append*, то есть добавить в конец.  

Но как можно организовать вывод в поток так, чтобы он был читаем и красив? для таких задач можно подлючить модуль `#include <iomanip>`. Это библиотека имеет набор методов, которые позволят как-то изменять выходной поток. Рассмотрим проблематику поэтапно и пошагово будем вносить модификации. Пусть названия колонок таблицы `names` и значения распределённые по этим колонкам `values`:

```c++
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main(){
	vector<string> names = {"a", "b", "c"};
	vector<double> values = {5, 0.01, 0.000005};

	for (const auto& n: names){
		cout << n << ' ';
	}
	cout << endl;
	for (const auto& v: values){
		cout << v << ' ';
	}

}
```

Вывод в консоле будет следующим:

![alt text](/Week_4/Conspect_scripts/image.png)

Иными слоами - не читаем из-за формата. Это можно поправить переконфигурировав выводной поток с помощью потоковых манипуляторов (для этого и нужен модуль `iomanip`). Первое что опробуем: переведём вывод из экспоненциальном вида в вывод с фиксированной точкой:

```c++
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main(){
	vector<string> names = {"a", "b", "c"};
	vector<double> values = {5, 0.01, 0.000005};

	for (const auto& n: names){
		cout << n << ' ';
	}
	cout << endl;
	cout << fixed;
	for (const auto& v: values){
		cout << v << ' ';
	}

}
```

Тогда вывод преобразиться:

![alt text](/Week_4/Conspect_scripts/image-1.png)

Уже лучше, но видна избыточность (для некоторых целей). Но можно задать точность вывода (до какой точки после запятой). Можно сконфигурировать эту точность с помощью `setprecision(N)`, где N - это до какого знака после запятой выводить:

``` c++
int main(){
	vector<string> names = {"a", "b", "c"};
	vector<double> values = {5, 0.01, 0.000005};

	for (const auto& n: names){
		cout << n << ' ';
	}
	cout << endl;
	cout << fixed << setprecision(2);
	for (const auto& v: values){
		cout << v << ' ';
	}

}
```
И вывод будет иметь вид:

![alt text](/Week_4/Conspect_scripts/image-2.png)

Теперь поиграемся с "резервированием" места под данные: манипулятор setwidth `setw(L)`, где L - количество символов, отводящееся под данные:
``` c++
int main(){
	vector<string> names = {"a", "b", "c"};
	vector<double> values = {5, 0.01, 0.000005};

	for (const auto& n: names){
		cout << n << ' ';
	}
	cout << endl;
	cout << fixed << setprecision(2);
	cout << setw(10);
	
	for (const auto& v: values){
		cout << v << ' ';
	}

}
```

![alt text](/Week_4/Conspect_scripts/image-3.png)

Но так будет резервирование только под первое значение из вектора `values`. То есть он сбрасывается после первого использования. Для того, чтобы зарезервировать подкаждое нужно встроиться в цикл (здесь ещё встроимся с резервирование в `names`):

``` c++
int main(){
	vector<string> names = {"a", "b", "c"};
	vector<double> values = {5, 0.01, 0.000005};

	for (const auto& n: names){
		cout << setw(10) << n << ' ';
	}
	cout << endl;
	cout << fixed << setprecision(2);
	
	for (const auto& v: values){
		cout << setw(10) << v << ' ';
	}

}
```

Тогда вывод будет уже намного более читаемым:

![alt text](/Week_4/Conspect_scripts/image-4.png)

Следующее что можно улучшить в выоде это заполнение пустого пространство чем-то. Это можно сделать с помощью `setfill(C)`, где `C` - это некоторый символ, `char`, которым будут заполняться пустое пространство (не задействованное при резервировании) далее в коде. Пример кода и вывода:

``` c++
int main(){
	vector<string> names = {"a", "b", "c"};
	vector<double> values = {5, 0.01, 0.000005};
	cout << setfill('.');
	for (const auto& n: names){
		cout << setw(10) << n << ' ';
	}
	cout << endl;
	cout << fixed << setprecision(2);
	
	for (const auto& v: values){
		cout << setw(10) << v << ' ';
	}

}
```

![alt text](/Week_4/Conspect_scripts/image-5.png)

Можно задать по какой области выровнять данные внутри зарезервированной области с помощью `left`:

``` c++
int main(){
	vector<string> names = {"a", "b", "c"};
	vector<double> values = {5, 0.01, 0.000005};
	cout << setfill('.');
	cout << left;
	for (const auto& n: names){
		cout << setw(10) << n << ' ';
	}
	cout << endl;
	cout << fixed << setprecision(2);
	
	for (const auto& v: values){
		cout << setw(10) << v << ' ';
	}

}
```

![alt text](/Week_4/Conspect_scripts/image-6.png)

## Перегрузка операторов

По умолчанию, нет особых проблем с такими операциями как ввод, вывод, сложение, вычитание и так далее. Но когда речь идёт про структуры и классы, некоторые операции могут быть немного иными, по сравнению с базовыми. И вот тут как раз и нужна перегразка операторов: грубо говоря "адаптирование и переопределение операций под нужды програмы и структ данных, использованных в программе". Рассмотрим пример: ввод и вывод времени:

```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

struct Duration {
    int hour;
    int min;
};
Duration ReadDuration(istream& stream){
    int h = 0;
    int m = 0;
    stream >> h;
    stream.ignore(1);
    stream >> m;
    return Duration {h, m};
}
void PrintDuration(ostream& stream, const Duration& duration){
    stream << setfill('0');
    stream << setw(2) << duration.hour << ':' 
           << setw(2) << duration.min;
}
int main (){
    stringstream dur_ss("01:50");
    Duration dur1 = ReadDuration(dur_ss);
    PrintDuration(cout, dur1);
    return 0;
}
```
В коде выше, пока нет никаких перегрузок операторов, это стандартная работа с потоками. Но обсудим их немного подробнее и поэтапно. Есть структура `Duration`, тип данных, в которых будут поля с часами и минутами. Мы хотим из некоторого потока считать время и вывести в другом поток. Для этого можно завести отдельную функцию `ReadDuration()`, которая на вход будет принимать поток из которого мы хотим считать время (делается через ссылку на класс входного потока `istream`, то есть `istream&`). Пусть мы знаем, что время казывается в формате "число - разделитель - число". Какой разделитель нам не особо важно (`stream.ignore()` решит этот вопрос). Выход этой функции будет объявленная ранее структура с полями `hour` и `min`. 

А теперь объявим функцию, которая будет выводить в поток время, которое будет храниться в нашей структуре. Этой функцией будет `PrintDuration()`. На вход она будет принимать ссылку на поток, куда мы хотим её вывести `ostream& stream`, а также экземпляр класса `const Duration& duration`. Внутри самой функции стандартизуем вывод: заполнение нулями там, где нет цифры, резервируем место и встраиваем разделитель между часами и минутами.

И теперь посмотрим, как оно работает: вызове наши функции в `main()`. А теперь новый трюк: можно ввести поток, с помощью класса stringstream - это наш текущий поток (не путать с переменной). В принципе это равносильно тому, что мы запросили ввод через консоль и отдельно там прописали время "01:50". 

В переменную `dur1` как структуру результат считывания из потока `dur_ss`. А вот печатать будем в консоль, то есть нашим потоком вывода будет как раз `cout`, а значит передаём первым аргументом именно этот поток.

Но в рамках языка С++ можно не вызывать функции `ReadDuration()` и `PrintDuration()`, а обойтись более простыми решениями: операторами ввода (`>>`) и операторами вывода (`<<`). 

Но сначала небольшое отступление. Рассмотрим операцию:
```c++
cout << "hello" << " world";
```
Банальная операция, но на деле мы имеем дело с укороченной записью вызовы оператора. Как это будет выглядеть в более полной форме:
```c++
operator<< (cout, "hello");
```
Есть глобальный оператор (`operator<<`), который на вход принимает поток, куда производить вывод, а вторым аргументом - набор символов для вывода. Если что, этот код рабочий, и вместо `<<` можно вызывать глобальный оператор (но не надо). А вот что он возвращает этот оператор? Возвращает сам поток, в который он делал вывод. А теперь как же работает изначальный пример:
```c++
operator<<(operator<<(cout, "hello"), " world");
```

Теперь мы знаем, что оператор должен вернуть сам поток. И вот теперь мы можем перегрузить оператор вывода и заменить функцию `PrintDuration()`, на вызов оператора `<<`. Аналогичную процедуру проделаем и для оператора ввода `>>` и функции `ReadDuration()`. И заметим, что сами функции нам более нужны, смело их заменяем операторами и тогда код будет выглядеть следующим образом:

```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

struct Duration {
    int hour;
    int min;
};

istream& operator>>(istream& stream, Duration& duration){
    stream >> duration.hour;
    stream.ignore(1);
    stream >> duration.min;
    return stream;
}

ostream& operator<<(ostream& stream, const Duration& duration){
    stream << setfill('0');
    stream << setw(2) << duration.hour << ':' 
           << setw(2) << duration.min;
    return stream;
}

int main (){
    stringstream dur_ss("01:50");
    Duration dur1 {0, 0};
    dur_ss >> dur1;
    cout << dur1 << endl;
    return 0;
}
```

По логике программы, блоки остались теми же, но ввод и вывод стал более простым для нас. Более того, не нужны дополнительные вспомогательные переменные `h` и `m`, которые были у нас в функции `ReadDuration()`.

Так перегружать можно не только ввод и вывод, но и другие операторы. Например сложение, вычитание и прочие. Модифируем пример кода выше:
Во-первых, стоит для начала обновить структуру, добавить конструктор и пересчёт в минуты и часы (чтобы не было 0 часов 70 минут, а было 1 час и 10 минут). Сделаем это через "общее время в минутах", `total`, а затем будем смотреть целое от деление на 60 и остаток от деления. И определим оператор сложения `+` для нашей структуры для того, чтобы мы могли складывать 2 структуры:
```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

struct Duration {
    int hour;
    int min;

    Duration (int h = 0, int m = 0){
        int total = h*60 + m;
        hour = total / 60;
        min = total % 60;
    }
};

Duration operator+(const Duration& lhs, const Duration& rhs){
    return Duration(lhs.hour + rhs.hour, lhs.min + rhs.min);
}

istream& operator>>(istream& stream, Duration& duration){
    stream >> duration.hour;
    stream.ignore(1);
    stream >> duration.min;
    return stream;
}

ostream& operator<<(ostream& stream, const Duration& duration){
    stream << setfill('0');
    stream << setw(2) << duration.hour << ':' 
           << setw(2) << duration.min;
    return stream;
}

int main (){
    stringstream dur_ss("01:50");
    Duration dur1 {0, 0};
    dur_ss >> dur1;
    cout << dur1 << endl;
    return 0;
}
```

Очевидно, что если мы проводим операцию над структурой: складываем 2 структуры, то и результат будет та же структура, а значит оператор будет возвращать структуру `Duration`, где мы опеределили, что сначала складываем часы, а потом складываем минуты.

А теперь, допустим, хотим воспользоваться функцией `sort()`, но для неё же должна быть опеределена операция сравнения `<`. Если мы сходу захотим упорядочить вектор из нескольких структур типа `Duration`, компилятор выдаст ошибку, так как сравнение не определено. И снова, мы можем глобально перегрузить оператор нашим прописанным сравнением и тогда функция `sort()` будет оперировать дополненными инструкциями. Вот пример кода:

```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

struct Duration {
    int hour;
    int min;

    Duration (int h = 0, int m = 0){
        int total = h*60 + m;
        hour = total / 60;
        min = total % 60;
    }
};

Duration operator+(const Duration& lhs, const Duration& rhs){
    return Duration(lhs.hour + rhs.hour, lhs.min + rhs.min);
}

bool operator<(const Duration& lhs, const Duration& rhs){
    if (lhs.hour == rhs.hour){
        return lhs.min < rhs.min;
    }
    return lhs.hour < rhs.hour;
}

istream& operator>>(istream& stream, Duration& duration){
    stream >> duration.hour;
    stream.ignore(1);
    stream >> duration.min;
    return stream;
}

ostream& operator<<(ostream& stream, const Duration& duration){
    stream << setfill('0');
    stream << setw(2) << duration.hour << ':' 
           << setw(2) << duration.min;
    return stream;
}

void PrintVector(const vector<Duration>& durs){
    for (const auto& d:durs){
        cout << d << ' ';
    }
    cout << endl;
}

int main (){
    stringstream dur_ss("02:50");
    Duration dur1;
    dur_ss >> dur1;
    Duration dur2 = {0, 35};
    Duration dur3 = dur1 + dur2;
    vector<Duration> v{dur3, dur1, dur2};
    PrintVector(v);
    sort(begin(v), end(v));
    PrintVector(v);
    return 0;
}
```

Вывод будет следующим:


![alt text](/Week_4/Conspect_scripts/image-7.png)


## Исключения

Это инструмент встроенные в С++ для отработки каких-то ошибок, некоретнных аргументов функций и так далее. По факту, всегда нужно контролировать, например, ввод с потока: насколько он соответствует тому, что мы ожидали. А если он не соответствует, то выдать какую-то детализированную ошибку (логировать ошибко). И вот рассмотрим пример:

Пусть у нас есть структура с датой (`Date`) и есть парсер `ParseDate()` этой даты из потока в соответствии с поля `Date`:

```C++
#include <sstream>
#include <iomanip>
#include <exception>
#include <iostream>

using namespace std;

struct Date{
    int year;
    int month;
    int day;
};

Date ParseDate(const string& s){
    stringstream stream(s); // объявление строкового потока, с которым далее работаем
    Date date;
    stream >> date.year;
    stream.ignore(1);
    stream >> date.month;
    stream.ignore(1);
    stream >> date.day;
    return date;
}

int main(){
    string date_str = "2017/01/25";
    Date date = ParseDate(date_str);
    cout << setw(2) << setfill('0') << date.day << '.'
         << setw(2) << setfill('0') << date.month << '.'
         << setw(2) << setfill('0') << date.year << endl;
    return 0;
}
```
Вывод будет выглядеть следующим образом:

![alt text](/Week_4/Conspect_scripts/image-8.png)

В таком случае у нас просто будет игнорироваться разделитель и не важно какой символ будет:

"2017/01/25" или "2017a01b25"

А такие вещи стоит контролировать в коде и давать знать пользователю, что пошло не так. Чтобы он смог скорретировать входные данные, например.

Самое очевидное решение - это вводить проверки на символы на стадии парсинга даты: соответвуют ли символы на позициях ожидаемым. Это можно сделать с помощью метода для потока `peek()` - подглядеть следующий символ, но не совсем считать его. Но тогда придётся менять сигнатуру функции и её входы: на вход подавать структуру `Date`, а выход преобразуется в `bool` - флаг того, что удало ли распарсить дату или нет. И всё это не очень удобно, особенно в масштабных проектах. Для таких задач лучше воспользовать "отловом исключений". 

Первое что стоит ввести:
```c++
 throw exception()
 ``` 
 То есть, выбрось в специальный класс exception в вызывающий код `main()`, что что-то пошло не так. Но для полноценной отлова ошибки этого недостаточно, так как нужна конструкция куда выбрасываться в случае ошибки: `try-catch`:

 ```c++
try{
	// Код, который проверяется на исключения / код, который может выдать ошибку
} catch (exception&){ // Класс, который будет ловиться при ошибке 
	// Отработчик ошибки
}

```

Пример того, как это может отрабатываться дан ниже:

```c++
#include <sstream>
#include <iomanip>
#include <exception>
#include <iostream>

using namespace std;

struct Date{
    int year;
    int month;
    int day;
};

void EnsureNextSymbolAndSkip(stringstream& stream){
    if (stream.peek() != '/'){
        throw exception();
    }
    stream.ignore(1);
}

Date ParseDate(const string& s){
    stringstream stream(s); // объявление строкового потока, с которым далее работаем
    Date date;
    stream >> date.year;
    EnsureNextSymbolAndSkip(stream);
    stream >> date.month;
    EnsureNextSymbolAndSkip(stream);
    stream >> date.day;
    return date;
}

int main(){
    string date_str = "2017a01b25";
    try{
        Date date = ParseDate(date_str);
        cout << setw(2) << setfill('0') << date.day << '.'
             << setw(2) << setfill('0') << date.month << '.'
             << setw(2) << setfill('0') << date.year << endl;
    }
    catch(exception& ex)
    {
        cout << "exception happens" << endl;
    }
    return 0;
}
```
В таком случае консоль выдаст следующее сообщение:

![alt text](/Week_4/Conspect_scripts/image-9.png)

Но есть возможность не только отловить какие-то ошибки, но и сообщить, что пошло не так при исполнении программы. И в `exception` можно как раз записать, что же пошло не так. Для этого есть `runtime_error`, где и будет храниться инфа об ошибке

```c++
#include <sstream>
#include <iomanip>
#include <exception>
#include <iostream>

using namespace std;

struct Date{
    int year;
    int month;
    int day;
};

void EnsureNextSymbolAndSkip(stringstream& stream){
    if (stream.peek() != '/'){
        stringstream ss;
        ss << "expected /, but has: " << char(stream.peek());
        throw runtime_error(ss.str());
    }
    stream.ignore(1);
}

Date ParseDate(const string& s){
    stringstream stream(s); // объявление строкового потока, с которым далее работаем
    Date date;
    stream >> date.year;
    EnsureNextSymbolAndSkip(stream);
    stream >> date.month;
    EnsureNextSymbolAndSkip(stream);
    stream >> date.day;
    return date;
}

int main(){
    string date_str = "2017a01b25";
    try{
        Date date = ParseDate(date_str);
        cout << setw(2) << setfill('0') << date.day << '.'
             << setw(2) << setfill('0') << date.month << '.'
             << setw(2) << setfill('0') << date.year << endl;
    }
    catch(exception& ex)
    {
        cout << "exception happens: " << ex.what() << endl;
    }
    return 0;
}
```

Вывод уже такой программы будет более информативным:

![alt text](/Week_4/Conspect_scripts/image-10.png)

Здесь метод `what()` класса `ex` содержит в себе текст ошибки, которую ранее мы записали с помощью строчки `throw runtime_error(ss.str())`

## Домашние задания ( #HW )
1. [Структура LectureTitle](/Week_4/1_Lecture_title/Lecture_struct.md)
2. [Обратимая функция](/Week_4/2_Reversible_Func/Reversible_Func.md)
3. [Обратимая функция с умножением и делением](/Week_4/3_Reversible_Func_2/Reversible_Func_2.md)
4. [Работа с файлами](/Week_4/4_Files/File_Tasks.md)
5. [Вывод с точностью](/Week_4/5_Precision/Precision.md)
6. [Чтение и вывод таблицы](/Week_4/6_Read_and_Write_Table/Read_and_Write_Table.md)
7. [Список студентов](/Week_4/7_Students_List/Students_List.md)
8. [Класс Rational](/Week_4/8_Rational/Rational.md)
9. [Функция EnsureEqual](/Week_4/9_EnsureEqual/EnsureEqual.md)
10. [Исключения в классе Rational](/Week_4/10_Exception_Rational/Exception_Rational.md)
11. [Калькулятор обыкновенных дробей](/Week_4/11_Frac_calc/frac_calc.md)
12. [Работа с сервером времени](/Week_4/12_Server_Time/Server_Time.md)


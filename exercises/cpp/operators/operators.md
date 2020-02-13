# Перегрузка операций

## OP-010-COMPLEX

Напишите класс `Complex` для комплексных чисел, имеющий следующие операции:

- `Complex::Complex(double re, double im)` инициализирует состояние комплексным числом `re + im * i`.
- `double Complex::re()` возвращает вещественную часть
- `double Complex::im()` возвращает мнимую часть
- бинарный `+` для сложения двух комплексных чисел (получается некоторое третье число, слагаемые не меняются)
- бинарный `-` для вычитания одного комплексного числа из другого (получается третье число)
- присваивание одной переменной в другую (состояние одной переменной перезаписывается состоянием другой переменной), присваивания можно делать в цепочке
- присваивания со сложением и с вычитанием
- префиксные и постфиксные инкремент и декремент (прибавляют и отнимают 1 от вещественной части)
- все виды арифметических сравнений
- должна быть возможность отправить комплексное число в поток вывода ("распечатать")

В вашем коде должны работать все привычные арифметические выражения с комлексными числами, например:

- `a = a + b + 2`
- `c != 1 - c`
- `x = d += a`
- `s++ + --d`

## OP-020-VECTOR

Дополните класс `IntVector` из раздела "Классы" операцией индексирования.

## OP-030-STRING

Дополните класс `String` из раздела "Классы" операциями над строками (соединение, сравнение и т.п.).

## OP-040-UNIQUEPTR

Напишите класс `IntUniquePtr`, реализующий указатель на область динамической памяти из одного целого числа. Этот объект может быть *пустым* (т.е. не содержать указатель) или *непустым* (содержать указатель). При удалении непустого объекта должна освобождаться его область динамической памяти. При копировании непустого объект в создаваемый объект происходит передача области динамической памяти создаваемому объекту.

- Метод `IntUniquePtr::IntUniquePtr()` создает пустой объект.
- Метод `IntUniquePtr::IntUniquePtr(int *p)` создает непустой объект, указывающий на область памяти, куда указывает`p`.
- Метод `IntUniquePtr::~IntUniquePtr()` освобождает область памяти, если объект непуст.
- Метод `IntUniquePtr::IntUniquePtr(IntUniquePtr &p)` передает создаваемому объекту область памяти из `p` и делает `p` пустым.
- должна быть возможность использовать переменную типа `IntUniquePtr` так же, как использовалась бы переменная типа `int *`, т.е. разыменовывать, сравнивать.
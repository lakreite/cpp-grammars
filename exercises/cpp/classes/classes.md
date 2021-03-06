# Классы

В языке Си мы оперируем областями памяти (переменными в тексте программы) и функциями, которые выполняют какое-то действия над ними. В языке Си++ то же самое - вы оперируете областями памяти (переменные в тексте программы) и функциями, которые выполняют какие-то действия над ними. Но синтаксис Си++ позволяет записывать некоторые действия компактнее, чем на чистом Си. Компилятор с языка Си++ выдает ассемблерный текст, как и компилятор с языка Си, т.е. код из функций и области памяти.

Вы увидели в своем коде такой набор функций:
- в каждой функции есть первый формальный параметр типа указатель
- все эти формальные параметры имеют один и тот же тип
- набор функций мыслится как решение некоторой одной задачи

Последняя фраза - очень общая и пока непонятная, она требует пояснения. Пример: получение максимума последовательности чисел, последовательность целиком не хранится, ее надо получать поэлементно из некоторого источника (например, из файла). Причем надо уметь прерываться между получением элементов последовательности и получать текущие максимумы тоже по запросу. Зачем надо прерываться? Например, чтобы в одной части кода получить одну часть последовательности, в другой - другую. Это гибче, чем задача без прерывания. А раз надо прерываться, а потом восстанавливать решение, то, получается, что у решения этой задачи есть состояние! Получена часть последовательности - сохранили ее - можно уже получать текущий максимум (при желании). Потом когда-то продолжим получать элементы последовательности - сохраним и их в состоянии - получим тот текущий максимум.

Итак, вы увидели в своем коде *класс*. Он решает *задачу* с *состоянием*. Функция тоже решает некоторую задачу, но в ней нет состояния. В языке Си есть статическая локальная переменная, она может быть таким *состоянием* в рамках одной функции. Это удобно, только если функция одна. А если состояние разделяется несколькими функциями, то локальная переменная уже не подойдет, ее будет видеть только одна из функций, а другие - не увидят. А несколько функций действительно потребуются. Посмотрите на наш пример: сначала ведь надо инициализировать состояние решения задачи, не прочитав еще ни один элемент последовательности, потом получать элемент последовательности, получать максимумы. Границы функций - это те "точки", в которых можно прерываться.

Как этим пользоваться? Так же, как и в языке Си: создать область памяти для состояния, не забыть ее инициализировать, потом вызывать функции, передавая им адрес области памяти, наконец удалить область памяти. В языке ассемблера всё это надо делать руками. В языке Си часть этого уже может сделать компилятор за вас: объявили переменную, тогда компилятор сам выделит под нее память и удалит под нее память при окончании жизни переменной. Вызывать функцию инициализации вам нужно самим. Язык Си++ идет дальше и еще больше автоматизирует эту работу: объявив переменную, компилятор не только выделит память, но и сам обязательно вызовет функцию инициализации (вы ему скажете, какая требуется функция), а при окончании жизни переменной сам вызовет функцию деинициализации (например, в ней вы закроете файлы, освободите блоки памяти, которые вы выделяли функцией `malloc`) и сам удалит память.

Что это дает кроме того, что функция инициализации обязательно будет вызвана? Имея некоторый класс, решающий некоторую задачу, можно **с минимальными затратами** получать классы, решающие похожие задачи. Не надо будет писать решение целиком заново, достаточно будет заменить часть существующего класса. А раз они так похожи, то можно будет их использовать для того кода, которому не важна разница между ними: код, который работал с исходным классом, должен оставаться рабочим и для нового класса. Классический пример: визуальный интерфейс пользователя с окнами, кнопками, надписями и прочим:
1. всё это классы (у них есть состояние, например, нажата кнопка или нет, какой текст написан на надписи и т.п.);
2. можно получать одни кнопки из других, меняя реакцию на нажатие и сохраняя форму, цвет и т.п.
3. у остальных видов визуальных элементов тоже есть, что поменять и получить похожий класс
4. для алгоритма определения, вылезает ли элемент за границы экрана или не вылезает, не важно, что именно это за элемент, они похожи друг на друга *в этом смысле*, достаточно знать координаты прямоугольника, в котором находится этот элемент, а они у всех элементов есть, а алгоритму больше ничего не нужно. В итоге, если появляется новый визуальный элемент, не нужно писать новый вариант алгоритма, он уже будет компилироваться и работать с новым типом. (вот в языке Си такого нет, каждый новый тип - это действительно отдельный тип, любая функция содержит жестко фиксированные типы параметров, появление нового типа будет означать необходимость писать новую функцию, во многом повторяющую исходную функцию...)

Написание программы с классами тоже не отличается от написания программы без классов: вы продумываете *архитектуру* своей программы и реализуете ее. Только здесь появляются новые возможности: составными элементами могут быть не только функции, но и классы. И точно так же, как и с функциями, работают подходы "сверху-вниз" и "снизу-вверх". "Сверху-вниз" означает, что надо начинать с функции `main` и далее придумывать функции/классы, которые необходимы для ее написания, потом то же надо сделать с этими функциями/классами. Понятно, с чего начинать программирование, можно быстро взяться за дело. Но если программа большая, то в ней обязательно будут похожие части кода и ошибки. И много дублирующего друг друга кода. Исправили ошибку в одной копии - не знали, что надо исправить ошибку в остальных дубликатах. Можно было бы дубликаты объединить, но как это сделать, когда уже написано много кода и целиком его не обозреть. Где там дубликаты и что объединять - непонятно. Подход "снизу-вверх" означает, что вначале надо подготовить *библиотеку* (или даже воспользоваться готовой, которую вы или кто-то еще написали при подготовке других программ). Библиотека - это набор функций/классов. Там нет функции `main`, это всё решения некоторых задач. Причем эти задачи должны быть полезны при написании разных программ (иначе какая же это библиотека). То есть эти задачи должны быть достаточно независимы друг от друга. Потом на основе одной библиотеки вы делаете другие - и так далее, пока не получите библиотеку с программой, которая решает вашу задачу. Такое возможно? Какой подход лучше? Истина, как всегда, посередине, надо брать всё лучшее из обоих подходов и комбинировать их. Не надо сразу браться за написание кода - надо подумать об *архитектуре* - какая бы пригодилась библиотека? Классы позволяют делать библиотеки из *расширяемых* компонентов кода (классы тем и лучше функций, что они *расширяемы*). Только следите за тем, чтобы библиотека не решала частных задач, чтобы разные библиотеки были независимыми, не решали похожих задач. Напоследок, чтобы написать расширяемую библиотеку, надо понимать, какое потребуется расширение. Это может быть понятно сразу, это может быть совсем непонятно. Не всегда угадывают и потом переделывают код (это называется *рефакторинг*). Этого не нужно бояться, это нужно уметь делать. Но потом, не в этом вводном курсе.



## CL-010-MAX

Напишите класс `MaxSeq`, решающий задачу вычисления максимума последовательности чисел типа `int`.

- Метод `void MaxSeq::add(int n)` добавляет `n` - очередной элемент последовательности.
- Метод `int MaxSeq::max()` возвращает максимум последовательности чисел, добавленной всеми предыдущими методами `add`. Этот метод не вызывается для пустой последовательности чисел.
- Метод `size_t MaxSeq::count()` возвращает количество добавленных элементов. Считаем, что оно не превышает границ типа `size_t`.


## CL-020-VECTOR

Напишите класс `IntVector`, решающий задачу организации динамического массива чисел типа `int`. Вначале все элементы считаются равными 0.

- Метод `void IntVector::set(int i, int value)` устанавливает значение `i`-го элемента массива, равным `value`.
- Метод `int IntVector::get(int i)` возвращает значение `i`-го элемента массива.

Ваш класс должен, с одной стороны, оптимально расходовать память, а с другой стороны - максимально быстро выполнять операции `set` и `get`. То есть не надо выделять сразу память под `INT_MAX` значений - почти все они скорее всего не будут использоваться. Скорее всего, вам потребуется динамическая память. Значит, потребуется функция инициализации и функция деинициализации. Не забудьте проверить, что они действительно вызываются (что обращения в динамическую память корректны, память выделили, и то что память не утекает, ее удалили), здесь вам поможет `valgrind`. Не забудьте проверить, что класс правильно работает при копировании объектов.

## CL-030-STRING

Напишите класс `String`, предназначенный для хранения строки и предоставления удобных операций над нею.

- Метод `String::String(const char *)` инициализирует состояние класса указанной Си-шной строкой. Класс должен владеть своей памятью под строку, т.е. если область памяти по переданному сюда адресу будет удалена, то это не должно повлиять на работу объекта `String`.
- Метод `size_t String::length()` возвращает длину строку.
- Метод `char &String::at(size_t index)` возвращает ссылку на символ строки по указанному индексу `index`. Считаем, что эту функцию вызывают только с индексами от 0 до `length-1`.
- Метод `void String::append(char *)` дописывает в конец текущей строки переданную Си-шную строку.
- Метод `const char *String::raw()` возвращает адрес начала Си-шной строки, которой владеет объект `String`. Метод не дает гарантий сохранения возвращаемой области памяти при дальнейших операциях над объектом `String`.

## CL-040-LINES

Напишите класс `TextFileReader`, предназначенный для удобного чтения текстового файла по строкам.

- Метод `TextFileReader::TextFileReader(const char *path)` открывает файл по пути `path`. Предполагается, что файл существует и к нему есть все необходимые права.
- Метод `TextFileReader::~TextFileReader()` закрывает файл.
- Метод `std::string TextFileReader::get()` возвращает очередную строку файла.
- Метод `bool TextFileReader::hasNext()` возвращает истину тогда и только тогда, когда в файле еще есть непрочитанные строки.

Копирование объектов этого класса должно приводить к ошибке компиляции. Объект этого класса не дает гарантий правильной работы, если файл будет изменяться по ходу его чтения.



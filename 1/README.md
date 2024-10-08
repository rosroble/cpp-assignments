# Лабораторная работа №1

Рассматриваемые темы: ввод/вывод, файловый ввод вывод. Основные типы данных и выражения. Понятие функции. Основы компиляции.

С основными типа данных можно ознакомиться, например, здесь: https://cplusplus.com/doc/tutorial/variables/

Разработать программу, которая вводит с клавиатуры два или три типа данных, и в качестве результата выводит в файл функцию, в которой будут созданы и проинициализированы переменные указанных типов, а также осуществлены арифметические операции над этими переменными с последующим выводом результата.

Предложите способ, позволяющий легко модифицировать программу генератор, чтобы она могла синтезировать более сложные выражения, используя, например, файл в котором каждая строка содержит символы операций. Приветствуются любые решения.

Создать программу, вызывающую данную функцию.

Откомпилировать и запустить результирующую программу. 

По результатам работы оформить отчет, содержащий исходные тексты или ссылку на GitHub с ними, примеры вывода.
В выводах укажите основные недостатки, с вашей точки зрения, построенной в ходе работы функции. 

## Решение

Исходный код приведен в файле `main.cpp`.

Пример работы:

```
(base) bpoloshkov@mbp c++ % make generator
g++ main.cpp -o generator
(base) bpoloshkov@mbp c++ % ./generator
Enter the number of types: 2
int
float
Enter the number of operations: 2
+
-
(base) bpoloshkov@mbp c++ % make func     
g++ func.cpp -o func
(base) bpoloshkov@mbp c++ % ./func     
3
-1
```

Сгенерированная программа:

```cpp
#include <iostream>
void f(void) {
	int int_0 = 1;
	float float_1 = 2;
	std::cout << int_0 + float_1 << std::endl;
	std::cout << int_0 - float_1 << std::endl;
}
int main() { f(); return 0; }
```

### Компиляция программы

```
make generator
```

### Компиляция программы, запускающую функцию

```
make func
```

## Заключение

В ходе выполнения лабораторной работы разработали программу, генерирующую другую программу, выводящую результат применения заданных операций к заданным типам.

### Недостатки реализации

- нет проверки корректности типов и операций
- нельзя указать инициализируемое значение
- нельзя указать директивы (как следствие, можно тестировать только стандартные типы)
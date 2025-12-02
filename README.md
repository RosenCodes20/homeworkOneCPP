# Проект: Библиотека (Library System)

## Описание

Проектът „Библиотека“ представлява малка C++ система, която моделира работа с книги, автори и членове на библиотека чрез пет взаимосвързани класа — `Author`, `Book`, `Member`, `Loan` и `Library`.
Той демонстрира прилагането на основни обектно-ориентирани концепции в C++:

* конструктори и деструктори;
* капсулация и достъп чрез getters и setters;
* const-коректност и валидация на данни;
* статични членове и методи;
* добри ООП практики в реалистичен контекст.

## Структура на проекта

```
homeworkOne/
├── Author.h
├── Book.h
├── Member.h
├── Loan.h
├── Library.h
├── README.md
├── main.cpp
└── main
```

## Компилация и изпълнение

Отворете терминал в директорията `library/` и изпълнете:

```bash
g++ -std=c++17 -Wall -Wextra -O2 main.cpp -o library
```

След това стартирайте програмата:

```bash
./library
```

## Примерен изход

```
Member name: Rosen Ivanov
Member id: 1251121252
Member year joined: 2018

Has book?: 1

Is book available: 1

Is book loaned: 1

Is book loaned: 1

Is book returned: 1
Found books: 2
Title: Harry Potter
Author name: J.K. Rowling
Author birth year: 1965
Book year: 1997
Book price: 29.990000
Book isbn: 9780545010221
Total Book counts 13

Title: Harry Potter Updated
Author name: J.K. Rowling
Author birth year: 1965
Book year: 1998
Book price: 35.500000
Book isbn: 9780545010221
Total Book counts 13

Library info:
Total books: 3
Total members: 2
Active loans: 1
```

## Класове

### Author

Представя автор на книга.

**Членове:**

* `std::string name` — име
* `int birthYear` — година на раждане

**Методи:**

* `Author()` — конструктор по подразбиране
* `Author(const std::string& name, int birthYear)` — конструктор с параметри
* `setName()`, `getName()`
* `setBirthYear()`, `getBirthYear()`
* `toString()` — текстово представяне

### Book

Представя книга.

**Членове:**

* `std::string isbn` — ISBN
* `std::string title` — заглавие
* `Author author` — автор
* `int copies` — брой налични копия

**Методи:**

* `Book()`
* `Book(const std::string& isbn, const std::string& title, const Author& author, int copies)`
* `setTitle()`, `getTitle()`
* `setCopies()`, `getCopies()`
* `getAuthor()`
* `toString()`

### Member

Представлява член на библиотеката.

**Членове:**

* `int id` — уникален идентификатор
* `std::string name` — име

**Методи:**

* `Member()`
* `Member(int id, const std::string& name)`
* `setName()`, `getName()`
* `getId()`
* `toString()`

### Loan

Представя заем на книга.

**Членове:**

* `std::string isbn` — ISBN на книгата
* `int memberId` — ID на члена
* `std::string startDate` — начална дата
* `std::string dueDate` — крайна дата
* `bool returned` — дали е върната

**Методи:**

* `Loan()`
* `Loan(const std::string& isbn, int memberId, const std::string& start, const std::string& due, bool returned=false)`
* `setReturned()`
* `isReturned()`
* `toString()`

### Library

Управлява книги, членове и заеми.

**Членове:**

* `std::vector<Book> books`
* `std::vector<Member> members`
* `std::vector<Loan> loans`

**Методи:**

* `addBook()`
* `addMember()`
* `borrowBook()`
* `returnBook()`
* `listLoans()`
* `listBooks()`

## Образователни цели

Проектът има за цел да демонстрира:

* разделение между интерфейс (.h) и имплементация (.cpp);
* използване на списъци за инициализация;
* валидация и обработка на изключения;
* работа със статични членове;
* прилагане на const-коректност.

## Автор

Име: Роес Иванов
Номер: 22324
Курс: Обектно-ориентирано програмиране (C++)
Дата: 02.12.2025

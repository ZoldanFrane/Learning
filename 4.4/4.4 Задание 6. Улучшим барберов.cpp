#include <iostream>

//Напишите программу, которая отвечает на вопрос хватает ли барберов в данном
//городе если задано число людей и число барберов, а так же указано, что
//один барбер работает 8 часов в день, на одного клиента тратит 1 час
//а каждый клиент приходит раз в месяц. Воспользуйтесь для решения проблемы
//целочисленного деления оператором %

int main() {
    int people; // Количество людей
    int barbers; // Количество барберов

    std::cout << "********* Барбершоп-калькулятор *********\n";
    std::cout << "Введите количество людей: ";
    std::cin >> people; // Указываем количество людей с клавиатуры и сохраняем в переменной people

    std::cout << "Сколько уже барберов удалось нанять? ";
    std::cin >> barbers; // Указываем количество барберов с клавиатуры и сохраняем в переменной barbers

    int mansPerBarberPerDay = 8; // Один человек в час, смена 8 часов
    int daysPerMonth = 30; // Количество дней в месяце
    int mansPerBarberPerMonth = mansPerBarberPerDay * daysPerMonth; // Сколько людей обслужит 1 барбер за месяц

    std::cout << "Один барбер стрижет столько клиентов в месяц: " << mansPerBarberPerMonth << "\n";

    int requiredBarbersCount = people / mansPerBarberPerMonth; // Сколько барберов нужно
    if (people % mansPerBarberPerMonth != 0) {
        requiredBarbersCount += 1; // Если остались необслуженные — нужен ещё 1 барбер
    }
    std::cout << "Необходимое число барберов: " << requiredBarbersCount << "\n";
    
    int realServed = barbers * mansPerBarberPerMonth; // Вычисляем, сколько максимум человек реально обслужат все нанятые барберы за месяц
    if (barbers > 1) { // Добавляем условие для вывода строки чтобы исключить повторения информирования сколько может подстричь 1 барбер за месяц
        std::cout << barbers << " барберов могут постричь " << realServed << " человек за месяц\n";
    }

    if (requiredBarbersCount > barbers) {
        std::cout << "Нужно больше барберов!!!\n";
        int barbersNeeded = requiredBarbersCount - barbers; // сколько ещё требуется
        std::cout << "Дополнительно требуется барберов: " << barbersNeeded << "\n";
        int unserved = people - realServed;
        if (unserved > 0)
            std::cout << "Не хватает на " << unserved << " человек(а)\n";
    } else {
        std::cout << "Барберов хватает!\n";
    }
}

#include <iostream>


int main()
{
    setlocale(LC_ALL, "Russian");

    struct time {
        int hours;
        int minutes;
    };

    struct raspisaniye {
        int  reis;
        char bus_type[64];
        char punkt_naznachenya[64];
        time  vremya_otpravlenya;
        time  vremya_pribitiya;
    };

    raspisaniye Raspisaniye_avtovokzala[3];

    for (int i = 0; i < 3; i++) {
        Raspisaniye_avtovokzala[i].reis = i + 1;
        
        std::cout << "Рейс №" << i + 1 << "." << "Введите тип автобуса: " << std::endl;
        std::cin >> Raspisaniye_avtovokzala[i].bus_type;
        
        std::cout << "Рейс №" << i + 1 << "." << "Введите пункт назначения: " << std::endl;
        std::cin >> Raspisaniye_avtovokzala[i].punkt_naznachenya;
       
        std::cout << "Рейс №" << i + 1 << "." << "Введите время отправления(часы): " << std::endl;
        std::cin >> Raspisaniye_avtovokzala[i].vremya_otpravlenya.hours;
        std::cout << "Рейс №" << i + 1 << "." << "Введите время отправления(минуты): " << std::endl;
        std::cin >> Raspisaniye_avtovokzala[i].vremya_otpravlenya.minutes;

        std::cout << "Рейс №" << i + 1 << "." << "Введите время прибытия(часы): " << std::endl;
        std::cin >> Raspisaniye_avtovokzala[i].vremya_pribitiya.hours;
        std::cout << "Рейс №" << i + 1 << "." << "Введите время прибытия(минуты): " << std::endl;
        std::cin >> Raspisaniye_avtovokzala[i].vremya_pribitiya.minutes;
    }

    for (int i = 0; i < 3; i++) {

        std::cout << "Рейс №" << i + 1 << "." << "Тип автобуса: " 
            << Raspisaniye_avtovokzala[i].bus_type << std::endl;
        std::cout << "Рейс №" << i + 1 << "." << "Пункт назначения: " 
            << Raspisaniye_avtovokzala[i].punkt_naznachenya << std::endl;
        std::cout << "Рейс №" << i + 1 << "." << "Время отправления: " 
            << Raspisaniye_avtovokzala[i].vremya_otpravlenya.hours << ":" << Raspisaniye_avtovokzala[i].vremya_otpravlenya.minutes << std::endl;
        std::cout << "Рейс №" << i + 1 << "." << "Время прибытия: "
            << Raspisaniye_avtovokzala[i].vremya_pribitiya.hours << ":" << Raspisaniye_avtovokzala[i].vremya_pribitiya.minutes << std::endl;
    }

    std::cout << "Выберите пункт назначения:" << std::endl;
    
    for (int i = 0; i < 3; i++) { 
        std::cout << "[" << i << "]" << Raspisaniye_avtovokzala[i].punkt_naznachenya << std::endl;
    }

    int vybraniy_marshrut;
    std::cin >> vybraniy_marshrut;

    time vremia;

    std::cout << "Введите время желаемого прибытия(часы): " << std::endl;
    std::cin >> vremia.hours;
    std::cout << "Введите время желаемого прибытия(минуты): " << std::endl;
    std::cin >> vremia.minutes;

    if (vremia.hours <= Raspisaniye_avtovokzala[vybraniy_marshrut].vremya_pribitiya.hours) {
        if (vremia.minutes < Raspisaniye_avtovokzala[vybraniy_marshrut].vremya_pribitiya.minutes) {
            std::cout << "Можно ехать!";
        }
        else {
            std::cout << "Нельзя ехать!";
        }
    }
    else {
        std::cout << "Нельзя ехать!";
    }
    
    return 0;
}

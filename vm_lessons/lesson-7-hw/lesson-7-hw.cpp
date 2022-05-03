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
        
        std::cout << "���� �" << i + 1 << "." << "������� ��� ��������: " << std::endl;
        std::cin >> Raspisaniye_avtovokzala[i].bus_type;
        
        std::cout << "���� �" << i + 1 << "." << "������� ����� ����������: " << std::endl;
        std::cin >> Raspisaniye_avtovokzala[i].punkt_naznachenya;
       
        std::cout << "���� �" << i + 1 << "." << "������� ����� �����������(����): " << std::endl;
        std::cin >> Raspisaniye_avtovokzala[i].vremya_otpravlenya.hours;
        std::cout << "���� �" << i + 1 << "." << "������� ����� �����������(������): " << std::endl;
        std::cin >> Raspisaniye_avtovokzala[i].vremya_otpravlenya.minutes;

        std::cout << "���� �" << i + 1 << "." << "������� ����� ��������(����): " << std::endl;
        std::cin >> Raspisaniye_avtovokzala[i].vremya_pribitiya.hours;
        std::cout << "���� �" << i + 1 << "." << "������� ����� ��������(������): " << std::endl;
        std::cin >> Raspisaniye_avtovokzala[i].vremya_pribitiya.minutes;
    }

    for (int i = 0; i < 3; i++) {

        std::cout << "���� �" << i + 1 << "." << "��� ��������: " 
            << Raspisaniye_avtovokzala[i].bus_type << std::endl;
        std::cout << "���� �" << i + 1 << "." << "����� ����������: " 
            << Raspisaniye_avtovokzala[i].punkt_naznachenya << std::endl;
        std::cout << "���� �" << i + 1 << "." << "����� �����������: " 
            << Raspisaniye_avtovokzala[i].vremya_otpravlenya.hours << ":" << Raspisaniye_avtovokzala[i].vremya_otpravlenya.minutes << std::endl;
        std::cout << "���� �" << i + 1 << "." << "����� ��������: "
            << Raspisaniye_avtovokzala[i].vremya_pribitiya.hours << ":" << Raspisaniye_avtovokzala[i].vremya_pribitiya.minutes << std::endl;
    }

    std::cout << "�������� ����� ����������:" << std::endl;
    
    for (int i = 0; i < 3; i++) { 
        std::cout << "[" << i << "]" << Raspisaniye_avtovokzala[i].punkt_naznachenya << std::endl;
    }

    int vybraniy_marshrut;
    std::cin >> vybraniy_marshrut;

    time vremia;

    std::cout << "������� ����� ��������� ��������(����): " << std::endl;
    std::cin >> vremia.hours;
    std::cout << "������� ����� ��������� ��������(������): " << std::endl;
    std::cin >> vremia.minutes;

    if (vremia.hours <= Raspisaniye_avtovokzala[vybraniy_marshrut].vremya_pribitiya.hours) {
        if (vremia.minutes < Raspisaniye_avtovokzala[vybraniy_marshrut].vremya_pribitiya.minutes) {
            std::cout << "����� �����!";
        }
        else {
            std::cout << "������ �����!";
        }
    }
    else {
        std::cout << "������ �����!";
    }
    
    return 0;
}

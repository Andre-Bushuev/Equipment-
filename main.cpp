#include <iostream>
#include <vector>
#include <list>

using namespace std;

#include "main_Eq_true.h"

Equipment::Equipment()
{
    EquipmentIsGood = bool  (rand() % 2); // произвольным образом определяем новый или нет и В хорошем качестве или нет
    EquipmentNew = bool  (rand() % 2);

    Color = EquipmentColor::UnknownColor;
    Country = EquipmentCountry::UnknownCountry;
    Size = EquipmentSize::unisex;
}

EquipmentContainer::EquipmentContainer(int maxSize) //Создаем вспомогательный конструктора для выделения и отчистку памяти под массив
{
	EquipmentBox = new EquipmentPtr[maxSize];

	for(int i =0 ; i <maxSize; i++)
	{
		EquipmentBox[i] = NULL;
	}

	EquipmentCount = 0;
	MaxSize = maxSize;
};

EquipmentContainer::~EquipmentContainer()
{
	for(int i =0 ; i <MaxSize; i++)
	{
		if(EquipmentBox[i] != NULL)
		{
			delete EquipmentBox[i];
			EquipmentBox[i] = NULL;
		}
	}

	delete[] EquipmentBox;
};

void EquipmentContainer::AddEquipment (EquipmentPtr newEquipment) //добавляет новое оборудование в контейнер
{
    EquipmentBox[EquipmentCount] = newEquipment;
    EquipmentCount++;
}

wstring PrintEquipmentType (const EquipmentType type)//сопоставления типа оборудования с соответствующей строкой, которая затем возвращается.
{
    switch(type)
    {
        case EquipmentType::Sports: return L"Спортивная";
        case EquipmentType::Military: return L"Военная";
        case EquipmentType::Safety: return L"Спасательная";
        case EquipmentType::Travel: return L"Путешественская";
        default: return L"неизвестный";
    }
}

wstring PrintEquipmentColor (const EquipmentColor color)//аналогично
{
    switch(color) {
        case EquipmentColor::Red: return L"Красный";
        case EquipmentColor::Orange: return L"Оранжевый";
        case EquipmentColor::Yellow: return L"Желтый";
        case EquipmentColor::Green: return L"Зеленый";
        case EquipmentColor::Blue: return L"Голубой";
        case EquipmentColor::DarkBlue: return L"Синий";
        case EquipmentColor::Violet: return L"Фиолетовый";
        default: return L"неизвестный"; }
}

wstring PrintEquipmentCountry (const EquipmentCountry country)//аналогично
{
    switch(country) {
    case EquipmentCountry::Russian: return  L"Российская";
    case EquipmentCountry::China: return  L"Китайская";
    case EquipmentCountry::Germany: return  L"Немецкая";
    case EquipmentCountry::France: return  L"Французская";
    case EquipmentCountry::Americonskay: return  L"Американская";
    default: return L"неизвестный"; }
}
wstring PrintEquipmentSize (const EquipmentSize size)//аналогично
{
    switch(size) {
    case EquipmentSize::xs_Size: return  L"XS";
    case EquipmentSize::s_Size: return  L"S";;
    case EquipmentSize::m_Size: return  L"M";;
    case EquipmentSize::l_Size: return  L"L";;
    case EquipmentSize::xl_Size: return  L"XL";;
    case EquipmentSize::xxl_Size: return  L"XXL";;
    default: return L"неизвестный"; }
}
Equipment *CreateEquipment(EquipmentType type) // фабричный метод
{
    switch(type)
    {
        case EquipmentType::Sports: return new Sports;
        case EquipmentType::Military: return new Military;
        case EquipmentType::Safety: return new Safety;
        case EquipmentType::Travel: return new Travel;
        default: return NULL;
    }
}

Equipment *Equipment::Create(EquipmentType type)
{
    return CreateEquipment(type);
}

int main()
{
    setlocale(LC_ALL, "Russian");

    MegaEquipmentContainer equipmentBox; // заполняем контейнер

    for(int i = 0; i< 30; i++)
	{
		equipmentBox.AddEquipment(CreateEquipment(EquipmentType::Sports));
	}
	for(int i = 0; i< 30; i++)
	{
		equipmentBox.AddEquipment(CreateEquipment(EquipmentType::Military));
	}
	for(int i = 0; i< 20; i++)
	{
		equipmentBox.AddEquipment(CreateEquipment(EquipmentType::Safety));
	}
	for(int i = 0; i< 20; i++)
	{
		equipmentBox.AddEquipment(CreateEquipment(EquipmentType::Travel));
	}
};

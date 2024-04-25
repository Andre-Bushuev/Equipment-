#include <iostream>
#include <vector>
#include <list>

using namespace std;

#include "main_Eq_true.h"

Equipment::Equipment()
{
    EquipmentIsGood = bool  (rand() % 2); // ������������ ������� ���������� ����� ��� ��� � � ������� �������� ��� ���
    EquipmentNew = bool  (rand() % 2);

    Color = EquipmentColor::UnknownColor;
    Country = EquipmentCountry::UnknownCountry;
    Size = EquipmentSize::unisex;
}

EquipmentContainer::EquipmentContainer(int maxSize) //������� ��������������� ������������ ��� ��������� � �������� ������ ��� ������
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

void EquipmentContainer::AddEquipment (EquipmentPtr newEquipment) //��������� ����� ������������ � ���������
{
    EquipmentBox[EquipmentCount] = newEquipment;
    EquipmentCount++;
}

wstring PrintEquipmentType (const EquipmentType type)//������������� ���� ������������ � ��������������� �������, ������� ����� ������������.
{
    switch(type)
    {
        case EquipmentType::Sports: return L"����������";
        case EquipmentType::Military: return L"�������";
        case EquipmentType::Safety: return L"������������";
        case EquipmentType::Travel: return L"���������������";
        default: return L"�����������";
    }
}

wstring PrintEquipmentColor (const EquipmentColor color)//����������
{
    switch(color) {
        case EquipmentColor::Red: return L"�������";
        case EquipmentColor::Orange: return L"���������";
        case EquipmentColor::Yellow: return L"������";
        case EquipmentColor::Green: return L"�������";
        case EquipmentColor::Blue: return L"�������";
        case EquipmentColor::DarkBlue: return L"�����";
        case EquipmentColor::Violet: return L"����������";
        default: return L"�����������"; }
}

wstring PrintEquipmentCountry (const EquipmentCountry country)//����������
{
    switch(country) {
    case EquipmentCountry::Russian: return  L"����������";
    case EquipmentCountry::China: return  L"���������";
    case EquipmentCountry::Germany: return  L"��������";
    case EquipmentCountry::France: return  L"�����������";
    case EquipmentCountry::Americonskay: return  L"������������";
    default: return L"�����������"; }
}
wstring PrintEquipmentSize (const EquipmentSize size)//����������
{
    switch(size) {
    case EquipmentSize::xs_Size: return  L"XS";
    case EquipmentSize::s_Size: return  L"S";;
    case EquipmentSize::m_Size: return  L"M";;
    case EquipmentSize::l_Size: return  L"L";;
    case EquipmentSize::xl_Size: return  L"XL";;
    case EquipmentSize::xxl_Size: return  L"XXL";;
    default: return L"�����������"; }
}
Equipment *CreateEquipment(EquipmentType type) // ��������� �����
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

    MegaEquipmentContainer equipmentBox; // ��������� ���������

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

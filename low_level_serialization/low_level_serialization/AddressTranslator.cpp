

#include "AddressTranslator.h"
#include <cstddef>


AddressTranslator & AddressTranslator::GetInstance()
{
    static AddressTranslator * pInst = NULL;
    if (pInst == NULL)
        pInst = new AddressTranslator();
    return *pInst;
}



void AddressTranslator::AddAddress(void * oldAddress, void * newAddress)
{
    //AddressTable mytable;

    //mytable[233]=434343;
    //mytable.insert(std::make_pair(200,300));
    m_table[(int)oldAddress] = (int)newAddress;
    //s_table[200] = 3283;
}


void * AddressTranslator::TranslateAddress(void * oldAddress)
{
    AddressTable::iterator it = m_table.find((int)oldAddress);
    if (it == m_table.end())
        return NULL;
    return (void *)(*it).second;
}


void AddressTranslator::Reset()
{
    m_table.clear();
}

